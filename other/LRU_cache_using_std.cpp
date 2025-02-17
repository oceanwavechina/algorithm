/*
 * LRU_cache.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <list>
#include <unordered_map>

using namespace std;

/*
 	 LRU cache
 	 	 修改和查找的时间复杂度都是 O(1)
 */

template <typename K, typename V>
class Node {
public:
	Node(const K& _key, const V& _value)
		: key(_key), value(_value), pre(nullptr), next(nullptr) {
	}

	void set(const K& _key, const V& _value)
	{
		key = _key;
		value = _value;
	}

public:
	K key;
	V value;

	Node* pre;
	Node* next;
};



template <typename K, typename V>
class LRUCache {
public:
	LRUCache(size_t capacity = 100) :_capacity(capacity) {
		assert(capacity > 0);
	}

public:
	bool get(const K& key, V& value) {
	    MapIterator map_iter = _map.find(key);
	    if(map_iter == _map.end()) {
	        return false;
	    }

	    value = map_iter->second->value;
	    _list.splice(_list.begin(), _list, map_iter->second);

	    return true;
	}

	void set(const K& key, const V& value) {
	    MapIterator map_iter = _map.find(key);
        if(map_iter == _map.end()) {

            if(_map.size() == _capacity) {
                _map.erase(_list.back().key);
                _list.pop_back();
            }

            _list.push_front(Node<K, V>(key, value));
            _map[key] = _list.begin();
            return;
        }

        _list.splice(_list.begin(), _list, map_iter->second);
        map_iter->second->value = value;
	}

	void display(const std::string& msg) {

        ostringstream oss_list_str;
        for(const auto item : _list) {
            oss_list_str << item.value << " ";
        }

		ostringstream oss_map_str;
		for(const auto item : _map) {
			oss_map_str << item.first << " ";
		}

		cout << msg;
		cout << "\n\tlist: " << oss_list_str.str();
		cout << "\n\tmap: " << oss_map_str.str();
		cout << "\n\tmap_size: " << _map.size();
		cout << "\n\tlist_size: " << _list.size() << "\n" << endl;
	}

private:
	typedef typename std::list<Node<K, V>>::iterator ListIterator;
	typedef typename unordered_map<K/*key*/, ListIterator /*pos_in_list*/>::iterator MapIterator;

	unordered_map<K/*key*/, ListIterator/*pos_in_list*/> _map;
	std::list<Node<K, V>> _list;
	size_t _capacity;
};


int main(int argc, char **argv) {
	//LRUCache<long, string> aCache(1);
	LRUCache<long, string> aCache(3);
	aCache.set(1, "1");
	aCache.set(2, "2");		// {2, 1}
	aCache.display("target: {2, 1}");

	string value;
	aCache.get(1, value);		// {1, 2}
	aCache.display("target: {1, 2}");

	aCache.set(3, "3");		// {3, 1, 2}
	aCache.set(4, "4");		// {4, 3, 1}   2-out
	aCache.display("target: {4, 3, 1}");

	aCache.get(1, value);		// {1, 4, 3}
	aCache.get(2, value);
	aCache.display("target: {1, 4, 3}");

	aCache.set(5, "5");		// 3-out
	aCache.display("target: {5, 1, 4}");

	return 0;
}




/*
    方法是:
        数据存储用 双向链表，对于给定的节点，数据的修改和添加都是O(1)
            节点的位置用hash-map存储， 所以查找某个节点的时间复杂度也是O(1)

    要点是：
        1. 无论查找还是更新，都要重新排序，所以，记得更新map中的位置

    NOTE：
        hash + linklist 应该还可以演化成 集合(set) 的实现，可以使得
        insert, delete, update, ismember, getallelements 这5个操作的时间复杂度都是O(1)
 */
