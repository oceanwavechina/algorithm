/*
 * bloom_filter.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

#define MAX_SIZE		10000000

/*
 * 容器越大，正确率越高
 */
//#define MAX_SIZE		10

using namespace std;

typedef void (*pFun)( );

class BloomFilter{

public:
	BloomFilter() {
		hash_func[0] = APHash;
		hash_func[1] = SDBMHash;
		hash_func[2] = RSHash;
	}

	void add(string key) {
		for(auto func : hash_func) {
			size_t val = func(key.c_str()) % MAX_SIZE;
			_bitset.set(val);
		}
	}

	bool exist(string key) {
		for(auto func : hash_func) {
			size_t val = func(key.c_str()) % MAX_SIZE;
			if (!_bitset.test(val)) return false;
		}

		return true;
	}

private:
	bitset<MAX_SIZE> _bitset;
	size_t (*hash_func[3])(const char *name);


private:
	template<class T>
	static size_t APHash(const T *str)
	{
		size_t hash = 0;
		size_t ch;
		for (long i = 0; (ch = (size_t)*str++); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}


	template<class T>
	static size_t SDBMHash(const T *str)
	{
		size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;
		}
		return hash;
	}


	template<class T>
	static size_t RSHash(const T *str)
	{
		size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};




int main(int argc, char **argv) {

	BloomFilter filter;

	vector<string> data = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"};
	for (auto str : data) {
		filter.add(str);
	}

	data.push_back("n");
	data.push_back("o");
	data.push_back("p");
	data.push_back("qfdasfadadsas1243132428439fadsfafsafdsafsasaf");

	for (auto str : data) {
		if (filter.exist(str)) {
			cout << str << " exist" << endl;
		} else {
			cout << str << " not exist" << endl;
		}

	}

	return 0;
}
