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

		方法是，	数据存储用 双向链表，对于给定的节点，数据的修改和添加都是O(1)
				节点的位置用hash-map存储， 所以查找某个节点的时间复杂度也是O(1)

		要点是：
			1. 无论查找还是更新，都要重新排序，所以，记得更新map中的位置

	NOTE：
		hash + linklist 应该还可以演化成 集合(set) 的实现，可以使得
		insert, delete, update, ismember, getallelements 这5个操作的时间复杂度都是O(1)
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
class LRUDoubleLinkList {
	//
	//	专门用于LRUcache的双向链表
	//		只需要删除给定节点和在头部插入两个操作
	//
public:
	LRUDoubleLinkList()
	: _head(nullptr), _tail(nullptr), _size(0) {
	}

public:
	void push_front(Node<K, V>* p_node) {
		assert(p_node);

		// 放在最前边
		p_node->next = _head;
		if(_head) {
			_head->pre = p_node;
		}
		_head = p_node;

		// 设置尾指针
		if(!_tail) {
			_tail = p_node;
		}

		++_size;
	}

	void remove(Node<K, V>* p_node) {
		assert(p_node);

		if(p_node->next) {
			// 后一个节点的前驱跨过要删除的节点
			p_node->next->pre = p_node->pre;
		}

		if(p_node->pre) {
			// 前一个节点的后继跨过要删除的节点
			p_node->pre->next = p_node->next;
		}

		if(p_node == _head) {
			_head = p_node->next;
		}

		if(p_node == _tail) {
			_tail = p_node->pre;
		}

		--_size;

		// 这个节点和list不在有关联
		p_node->pre = nullptr;
		p_node->next = nullptr;
	}

	Node<K, V>* pop_back() {

		if(!_tail) {
			return nullptr;
		}

		Node<K, V>* p_ret = _tail;

		// 尾指针前移，并且next置为nullptr
		_tail = _tail->pre;
		if(_tail) {
			_tail->next = nullptr;
		}

		// 要删除的节点也是头结点
		if(p_ret == _head) {
			_head = nullptr;
		}

		--_size;

		// 这个节点和list不在有关联
		p_ret->pre = nullptr;
		p_ret->next = nullptr;

		return p_ret;
	}

	size_t size() {
		return _size;
	}

	void clear() {
		Node<K, V>* p_cur = _head;

		while(p_cur) {
			delete p_cur;
			p_cur = p_cur->next;
		}

		_size = 0;
	}

	string display_str() {
		Node<K, V>* p_cur = _head;

		ostringstream oss;
		while(p_cur) {
			oss << p_cur->value << " ";
			p_cur = p_cur->next;
		}

		return oss.str();
	}

private:
	Node<K, V>* _head;		// 头节点
	Node<K, V>* _tail;		// 尾节点
	size_t _size;		// 当前链表中的元素个数
};

template <typename K, typename V>
class LRUCache {
public:
	LRUCache(size_t capacity = 100) :_capacity(capacity) {
		assert(capacity > 0);
	}

public:
	bool get(const K& key, V& value) {
		bool found = false;

		MapIterator it = _map.find(key);
		if( it != _map.end()) {
			found = true;

			Node<K, V>* p_node = it->second;
			value = p_node->value;

			// 把这个节点移动到链表的开始
			_list.remove(p_node);
			_list.push_front(p_node);
		}

		ostringstream oss;
		oss << "cmd:get, key:" << key << ", found:" << found << ", value:" << value;
		display(oss.str());

		return found;
	}

	void set(const K& key, const V& value) {

		Node<K, V>* p_node = nullptr;

		ostringstream oss;
		oss << "cmd:set, key:" << key << ", value:" << value;

		MapIterator it = _map.find(key);

		if( it != _map.end()) {
			// 已经存在了
			Node<K, V>* p_node = it->second;
			p_node->value = value;

			// 移到链表的前边
			_list.remove(p_node);
			_list.push_front(p_node);

		} else  {
			// 不存在，需要创建
			if(_map.size() == _capacity) {
				// 需要把最后一个(也就是最长时间没有使用的)删除掉
				// 我们这里不全部删除，只是从list结尾拿掉，直接用来存要加的数据
				p_node = _list.pop_back();
				_map.erase(p_node->key);
				oss << ", remove:" << p_node->key;

				p_node->set(key, value);
			} else {
				p_node = new Node<K, V>(key, value);
			}

			assert(p_node);

			_list.push_front(p_node);
			_map.insert(make_pair(key, p_node));
		}

		display(oss.str());
	}

	void display(const string& msg) {

		string list_str = _list.display_str();
		ostringstream oss_map_str;
		for(const auto item : _map) {
			oss_map_str << item.first << " ";
		}

		cout << msg;
		cout << "\n\tlist: " << list_str;
		cout << "\n\tmap: " << oss_map_str.str();
		cout << "\n\tmap_size: " << _map.size();
		cout << "\n\tlist_size: " << _list.size() << "\n" << endl;
	}

private:
	unordered_map<K/*key*/, Node<K, V>* /*pos_in_list*/> _map;
	LRUDoubleLinkList<K, V> _list;
	size_t _capacity;
	typedef typename unordered_map<K/*key*/, Node<K, V>* /*pos_in_list*/>::const_iterator MapIterator;
};


int main(int argc, char **argv) {
	LRUCache<long, string> aCache(1);
	aCache.set(1, "1");
	aCache.set(2, "2");		// {2, 1}

	string value;
	aCache.get(1, value);		// {1, 2}

	aCache.set(3, "3");		// {3, 1, 2}
	aCache.set(4, "4");		// {4, 3, 1}   2-out

	aCache.get(1, value);		// {1, 4, 3}
	aCache.get(2, value);

	aCache.set(5, "5");		// 3-out

	return 0;
}
