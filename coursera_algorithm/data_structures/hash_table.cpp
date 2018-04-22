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
	OpenAddressingHashTable(uint size)
		:_size(size)
	{
		_p_buckets = new Entry[_size];
		memset(_p_buckets, sizeof(Entry) * _size, 0);
	}


public:
	int Insert(int key, VALUE_TYPE value)
	{
		int i=0;
		uint hash = hash_func(key, i);

		while(i < _size)
		{
			Entry& entry = *(_p_buckets + hash);

			if(entry.deleted || entry.empty) {
				entry.key = key;
				entry.value = value;
				entry.empty = false;
				entry.deleted = false;
				return hash;
			} else {
				hash = hash_func(key, ++i);
			}
		}

		return	-1;
	}

	bool Search(int key, VALUE_TYPE& ret)
	{
		int i = 0;
		uint hash = hash_func(key, i);

		while(i++ < _size) {
			Entry& entry = *(_p_buckets + hash);

			if (entry.empty)
				return false;
			else if(entry.key == key) {
				ret = entry.value;
				return true;
			} else {
				hash = hash_func(key, i);
			}
		}

		return false;
	}

	void Delete(int key)
	{
		int i = 0;
		uint hash = hash_func(key, i);

		while(i++ < _size) {
			Entry& entry = *(_p_buckets + hash);

			if(entry.key == key) {
				entry.deleted = true;

				// 注意这里不能直接设置为空，即是删除了，空的话会是查找中断，导致其他相同hash值的元素找不到
				// 这个也是开放定址法要注意的点
				//entry.empty = true;
				return;
			}
		}

	}

	void display() {
		for(int i=0; i< _size; ++i) {
			Entry& entry = *(_p_buckets + i);
			if (!entry.deleted && !entry.empty)
				cout << entry.key << ": " << entry.value << "\t\t";
			else
				cout << -1 << ": " << "  " << "\t\t";
		}
		cout << endl;
	}

	uint hash_func(int key, int probnum)
	{
		return (key + probnum) % _size;
	}

private:

	Entry* _p_buckets;
	unsigned int _size;
};

int main(int argc, char **argv) {

	typedef string value_t;
	OpenAddressingHashTable<value_t> table(10);

	cout << "insert 1 at: " << table.Insert(1, "one") << endl;
	table.display();
	cout << "insert 2 at: " << table.Insert(2, "two") << endl;
	table.display();
	cout << "insert 3 at: " << table.Insert(3, "three") << endl;
	table.display();
	cout << "insert 4 at: " << table.Insert(4, "four") << endl;
	table.display();
	cout << "insert 5 at: " << table.Insert(5, "five") << endl;
	table.display();
	cout << "insert 6 at: " << table.Insert(6, "six") << endl;
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
