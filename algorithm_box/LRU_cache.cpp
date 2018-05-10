/*
 * LRU_cache.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: liuyanan
 */

#include <iostream>
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


class LRUCache{

public:
	LRUCache(int capacity):_capacity(capacity){};


	int get(int key) {

		cout << "get|key:" << key;

		if ( _cache_map.find(key) == _cache_map.end()) {
			cout << "|value:-1" << endl;
			return -1;
		}

		// 把该节点移动到链表的头部
		_cache_list.splice(_cache_list.begin(), _cache_list, _cache_map[key]);
		// 更新map中的位置
		_cache_map[key] = _cache_list.begin();

		cout << "|value:" << _cache_map[key]->value << endl;

		return _cache_map[key]->value;
	}

	void set(int key, int value) {

		cout << "set|key:" << key << "|value:" << value;

		if ( _cache_map.find(key) == _cache_map.end()) {

			if (_capacity == _cache_list.size()){
				cout << "|expire_key:" << _cache_list.back().key;
				// 删除最长时间不访问的节点
				_cache_map.erase(_cache_list.back().key);
				_cache_list.pop_back();
			}

			CacheNode aCacheNode(key, value);
			_cache_list.push_front(aCacheNode);
			_cache_map[key] = _cache_list.begin();
			cout << "|insert_key:" << key << "|insert_value:" << value;
		} else {
			cout << "|update_key:" << key << "|old_value:" << value;
			_cache_map[key]->value = value;

			// 把该节点移动到链表的头部
			_cache_list.splice(_cache_list.begin(), _cache_list, _cache_map[key]);
			// 更新map中的位置
			_cache_map[key] = _cache_list.begin();
		}

		cout << endl;
	}

private:
	struct CacheNode{
		int key;
		int value;
		CacheNode(int k, int v):key(k), value(v) {}
	};

	int _capacity;
	list<CacheNode> _cache_list;
	unordered_map<int/*key*/, list<CacheNode>::iterator /*pos_in_list*/> _cache_map;
};


int main(int argc, char **argv) {
	LRUCache aCache(3);
	aCache.set(1, 11);
	aCache.set(2, 22);	// {2, 1}
	aCache.get(1);		// {1, 2}
	aCache.set(3, 33);	// {3, 1, 2}
	aCache.set(4, 44);	// {4, 3, 1}   2-out

	aCache.get(1);		// {1, 4, 3}
	aCache.get(2);

	aCache.set(5, 55);	// 3-out

	return 0;
}
