/*
 * hash_table.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: liuyanan
 */

#include <iostream>

using namespace std;


/*
  	Integer Hash Function
 	 	http://web.archive.org/web/20071223173210/http://www.concentric.net/~Ttwang/tech/inthash.htm

	Note from
		https://www.geeksforgeeks.org/what-are-hash-functions-and-how-to-choose-a-good-hash-function/


	The mod method:
		In this method for creating hash functions,
		we map a key into one of the slots of table by taking the remainder of key divided by table_size.
		That is, the hash function is

			h(key) = key mod table_size

			i.e. key % table_size

		* Since it requires only a single division operation, hashing by division is quite fast.

		* When using the division method, we usually avoid certain values of table_size
		  like table_size should not be a power of a number suppose r,
		  since if table_size = r^p, then h(key) is just the p lowest-order bits of key.
		  Unless we know that all low-order p-bit patterns are equally likely,
		  we are better off designing the hash function to depend on all the bits of the key.

		* It has been found that the best results with the division method are achieved when the table size is prime.
		  However, even if table_size is prime, an additional restriction is called for.
		  If r is the number of possible character codes on an computer, and if table_size is a prime such that r % table_size equal 1,
		  then hash function h(key) = key % table_size is simply the sum of the binary representation of the characters in the key mod table_size.

			Suppose r = 256 and table_size = 17, in which r % table_size i.e. 256 % 17 = 1.
			So for key = 37599, its hash is
				37599 % 17 = 12

			But for key = 573, its hash function is also
				573 % 17 = 12

		* Hence it can be seen that by this hash function, many keys can have the same hash. This is called Collision.

		* A prime not too close to an exact power of 2 is often good choice for table_size.
 */

template <typename KEY_TYPE, typename VALUE_TYPE>
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
			:deleted(false), empty(true)
		{}

		Entry(KEY_TYPE _key, VALUE_TYPE _value)
			:key(_key), value(_value), deleted(false), empty(true)
		{}

		KEY_TYPE key;
		VALUE_TYPE value;

		bool deleted;
		bool empty;
	};


public:
	// 默认大小是10
	OpenAddressingHashTable()
		:_table_size(4), _loadfactor_threshold(_table_size / 2), _member_size(0)
	{
		_p_buckets = new Entry[_table_size];
	}


public:
	int Insert(KEY_TYPE key, VALUE_TYPE value)
	{
		// 需要重新分配更大的空间
		if(_member_size + 1 > _loadfactor_threshold) {
			_resize();
		}

		// 找一个没有使用的位置
		size_t pos = get_hash_position(key);

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

	bool Search(KEY_TYPE key, VALUE_TYPE& ret)
	{
		size_t pos = get_hash_position(key);

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

	void Delete(KEY_TYPE key)
	{
		size_t pos = get_hash_position(key);

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

	size_t get_hash_position(KEY_TYPE key)
	{
		// hash 出来的pos肯定是在table数组里边的

		//return key % _table_size;
		return std::hash<KEY_TYPE>{}(key) % _table_size;
	}

private:

	size_t _get_next_newsize(uint64_t old_size) {

		if(old_size >= UINT64_MAX) return UINT64_MAX;

		int new_table_size = 4;

		while (1) {
			if(new_table_size > old_size) {
				return new_table_size;
			} else {
				new_table_size *= 2;
			}
		}
	}

	 void _resize() {
		 // 1. 重新分配表: old_size * 2
		 // 2. 把之前所有元素，重现计算hash，放到新的表里边

		 /*
		     Redis中的渐进式rehash

		  	  在数据量比较大的时候 hashtable 的 resize(rehash)过程 会比较耗时, redis使用的是渐进式的rehash：
		  	  	  1. 每个dict有两个table， 其中table[0],是主table (在rehash的过程中属于 old-data 的table)
		  	  	  2. 当需要rehash的时候，table中的 rehashidx 会置成非负
		  	  	  3. 当每次调用find，add，等的操作的时候，会先执行一次rehash，当old-table中的数据都移到new-table中reahsh结束
		  	  	  	  然后把 table[0] 的数据释放掉， 把指针table[0] 指向table[1]的数据
		  	  	  	  这里在rehash的过程中，每rehash一个bucket，就会吧old-data中的bucket数据删除

			  这里有几个问题：
		  	 	 1. rehash过程中，如果有插入，删除，修改数据怎么处理
		  	 	     插入：只在new-table中进行，这样在之后的查找时，需要查找两个table
		  	 	     修改：修改有点复杂，修改的操作是 查找 -> 更新
		  	 	     	 1. 现在老的表里边查找，如果找到了，说明数据还没有移动到new-table中，直接修改entry
		  	 	     	 2，如果没有找到，要么本来没有，要么已经移到new-table中了，那就执行插入操作
		  	 	     	 3. 插入操作，如上所述直接在new-table中找
		  	 	     删除：	删除的话，两个表一起同步删除

		  	 	 2. rehash的过程中会不会出现需要再次扩容的情况
		  	 	 	 可以试想，如果在rehash开始后，一直是insert操作，那当insert的次数到达old-table的bucket个数时，rehash就完成了
		  	 	 	 redis的扩容方式是2的倍数增长，所以应该不会出现，但是它代码里边倒是判断了两次扩容不能重叠进行
		  */

		 Entry* _p_old_buckets = _p_buckets;
		 size_t old_size = _table_size;

		 // 分配空间, 并修改当前空间的大小和阈值
		 _table_size = _get_next_newsize(old_size);
		 _loadfactor_threshold = _table_size / 2;
		 _p_buckets = new Entry[_table_size];

		 cout << "_resize, newsize:" << _table_size << endl;

		 // 移动元素，且重新hash
		 for(size_t i=0; i<old_size; ++i) {

			 Entry old_entry = _p_old_buckets[i];

			 // 找到一个没有使用的位置
			 size_t pos = get_hash_position(old_entry.key);

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
	OpenAddressingHashTable<int, value_t> table;

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
