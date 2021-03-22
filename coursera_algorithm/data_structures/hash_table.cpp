/*
 * hash_table.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: liuyanan
 */

#include <iostream>

using namespace std;

template <typename VALUE_TYPE>
class OpenAddressingHashTable{

private:
	class Entry {

		/*
		 *	封装了key和value，几点需要注意
		 *		1. key一定是原始的key，不能是hash后的，这个显而易见
		 *		2. 这里设置了empty和deleted两个flag，empty含义显而易见，deleted是为了删除用的
		 */
	public:
		Entry()
			:key(-1), deleted(false), empty(true)
		{}

		Entry(int _key, VALUE_TYPE _value)
			:key(_key), value(_value), deleted(false), empty(true)
		{}

		int key;
		VALUE_TYPE value;
		bool deleted;
		bool empty;
	};


public:
	// 默认大小是10
	OpenAddressingHashTable()
		:_table_size(10), _loadfactor_threshold(_table_size / 2), _member_size(0)
	{
		_p_buckets = new Entry[_table_size];
	}


public:
	int Insert(int key, VALUE_TYPE value)
	{
		// 需要重新分配更大的空间
		if(_member_size + 1 > _loadfactor_threshold) {
			_resize();
		}

		// 找一个没有使用的位置
		uint64_t pos = get_hash_position(key);

		for(size_t prob_cnt = 0; prob_cnt < _table_size; ++prob_cnt) {
			Entry& entry = _p_buckets[pos++];

			if(entry.deleted || entry.empty) {
				entry.key = key;
				entry.value = value;
				entry.empty = false;
				entry.deleted = false;

				++_member_size;

				return pos;
			}

		}

		return	-1;
	}

	bool Search(int key, VALUE_TYPE& ret)
	{
		uint64_t pos = get_hash_position(key);

		for(size_t prob_cnt = 0; prob_cnt < _table_size; ++prob_cnt) {
			const Entry& entry = _p_buckets[pos++];

			if (entry.empty)
				return false;
			else if(entry.key == key) {
				ret = entry.value;
				return true;
			}

		}

		return false;
	}

	void Delete(int key)
	{
		uint64_t pos = get_hash_position(key);

		for(size_t prob_cnt = 0; prob_cnt < _table_size; ++prob_cnt) {
			Entry& entry = *(_p_buckets + pos++);

			if(entry.key == key) {
				entry.deleted = true;

				--_member_size;

				// WARNING:
				// 		注意这里不能直接设置为空，即是删除了，空的话会是查找中断，导致其他相同hash值的元素找不到
				// 		这个也是开放定址法要注意的点
				//		entry.empty = true;
				return;
			}
		}
	}

	void display() {
		for(int i=0; i< _table_size; ++i) {
			Entry& entry = *(_p_buckets + i);
#if 0
			if (!entry.deleted && !entry.empty)
				cout << entry.key << ": " << entry.value << "\t";
			else
				cout << -1 << ": " << "  " << "\t";
#else
			cout<< entry.key << ":" << entry.value;
			if(entry.deleted)
				cout << ":d";

			cout << "\t";
#endif
		}
		cout << "msize:" << _member_size;
		cout << endl << endl;
	}

	uint64_t get_hash_position(int key, uint64_t probnum = 0)
	{
		// hash 出来的pos肯定是在table数组里边的
		return (key + probnum) % _table_size;
	}

private:
	 void _resize() {
		 // 1. 重新分配表: 原有空间大小 * 2
		 // 2. 把之前所有元素，重现计算hash，放到新的表里边

		 Entry* _p_old_buckets = _p_buckets;
		 size_t old_size = _table_size;

		 // 分配空间, 并修改当前空间的大小和阈值
		 _table_size = old_size * 2;
		 _loadfactor_threshold = _table_size / 2;
		 _p_buckets = new Entry[_table_size];

		 cout << "_resize, newsize:" << _table_size << endl;

		 // 移动元素，且重新hash
		 for(size_t i=0; i<old_size; ++i) {

			 Entry old_entry = _p_old_buckets[i];

			 // 找到一个没有使用的位置
			 uint64_t pos = get_hash_position(old_entry.key);

			 for(size_t prob_cnt = 0; prob_cnt < _table_size; ++prob_cnt) {
				 Entry& entry = _p_buckets[pos++];

				 if(entry.deleted || entry.empty) {
					entry.key = old_entry.key;
					entry.value = old_entry.value;
					entry.empty = false;
					entry.deleted = false;
					break;
				 }

			 };
		 }

		 delete[] _p_buckets;
	 }

private:

	Entry* _p_buckets;
	size_t _table_size;

	size_t _member_size;	// 这个是当前表里边已经存的数据的个数
	int _loadfactor_threshold;	// 负载因子的阈值：当表中的元素个数大于 _loadfactor_threshold 时 需要resize
};

int main(int argc, char **argv) {

	typedef string value_t;
	OpenAddressingHashTable<value_t> table;

	cout << "insert 1 at: " << table.Insert(1, "one") << endl;
	table.display();
	cout << "insert 2 at: " << table.Insert(2, "two") << endl;
	table.display();
	cout << "insert 3 at: " << table.Insert(3, "three") << endl;
	table.display();
//	cout << "insert 4 at: " << table.Insert(4, "four") << endl;
//	table.display();
//	cout << "insert 5 at: " << table.Insert(5, "five") << endl;
//	table.display();
	cout << "insert 14 at: " << table.Insert(14, "fourteen") << endl;
	table.display();
	cout << "insert 7 at: " << table.Insert(7, "seven") << endl;
	table.display();
//	cout << "insert 8 at: " << table.Insert(8, "eight") << endl;
//	table.display();
//	cout << "insert 9 at: " << table.Insert(9, "nine") << endl;
//	table.display();
//	cout << "insert 10 at: " << table.Insert(10, "ten") << endl;
//	table.display();

	cout << endl << endl;

	cout << "insert 14 at: " << table.Insert(14, "fourteen") << endl;
	table.display();

	table.Delete(7);
	cout << "after delete 7" << endl;
	table.display();

	value_t val;
	if(table.Search(14, val)) {
		cout << "find key=14, with value=" << val << endl;
	} else {
		cout << "failed to find key=14" << endl;
	}

	cout << "insert 8 at: " << table.Insert(8, "eight") << endl;
	table.display();

	if(table.Search(8, val)) {
		cout << "find key=8, with value=" << val << endl;
	} else {
		cout << "failed to find key=8" << endl;
	}




	cout << endl << endl;

	if(table.Search(6, val)) {
		cout << "find key=6, with value=" << val << endl;
	}

	if(!table.Search(11, val)) {
		cout << "failed to find key=11" << endl;
	}

	cout << endl << endl;

	table.Delete(5);
	cout << "after delete 5" << endl;
	table.display();

	if(!table.Search(5, val)) {
		cout << "failed to find key=5" << endl;
	}


	return 0;
}
