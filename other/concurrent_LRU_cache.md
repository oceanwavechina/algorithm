# concurrent lru cache

lru的基本思想就是 hash + linklist 的模式，hash用来快速查找，然后利用linklist 的有序性和快速删除的特性，给数据进行热度排序。

但是实际中，单线程场景并不多，很多时候，需要多线程并发访问，这样就不可避免的引入各种锁机制来保证数据的并发访问。如此一来，锁带来的性能下降也就不可避免。

所以，这篇文章我们分析下实际应用中支持多线程的 lru-cache，以及各种优化手段来减小锁的瓶颈。

<br>

## 1. lru 的基础版本

----

<br>

为了理解上的直观，我们先放一个单线程的版本

```cpp
bool get(K key, V value) {

    // lock()

    HashMapIterator it = hash_map.find(key);
    if( it != hash_map.end()) {
        Node<K, V>* p_node = it->second;
        value = p_node->value;
        link_list.move_to_front(p_node);  // 移动到链表开始
    }

    // unlock()
}

void set(const K& key, const V& value) {    
    Node<K, V>* p_node = nullptr;

    // unlock()

    HashMapIterator it = hash_map.find(key);

    if( it != hash_map.end()) {    // 已经存在了
        p_node = it->second;
        p_node->value = value;
        link_list.move_to_front(p_node);    // 移到链表的前边
    } else  { // 不存在，需要创建
        if(hash_map.size() == _capacity) {
            p_node = list.pop_back();
            hash_map.erase(p_node->key);
            p_node->set(key, value);
        } else {
            p_node = new Node<K, V>(key, value);
        }

        link_list.push_front(p_node);
        hash_map.insert(make_pair(key, p_node));
    }

    // unlock()
}
```

需要注意的是，在get方法中，我们也会修改链表，所以 lru-cache 的接口没有存粹的只读操作

为了支持多线程访问，我们就要在代码中加锁，如上述伪代码中注释部分的形式。但这样一来，在高并发下锁本身就会严重拖累性能，不能把lru-cache的优势完全发挥出来。

接下来，我们就依次看看有哪些常用手段，可以继续压榨出一些性能提升。

<br>

## 2. Sharding: 数据分片

----



分片的思想在分布式系统中应用广泛，通过对数据分片可以整体减少锁的粒度。