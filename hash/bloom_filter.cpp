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
#include <cmath>


/*

	https://dadario.com.br/cryptographic-and-non-cryptographic-hash-functions/

	容器越大，正确率越高
	# CS168: The Modern Algorithmic Toolbox Lecture #1: Introduction and Consistent Hashing
 	 bloomfilter 还可以用来减少数据传输的场景里。 比如与其传输具体的数据，我们可以传输bloomfileter的值来进行同步

 	bloomfilter
		https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/

 		如果filter中有，说明数据大概率出现了，
 		如果filter中没有，那数据指定没有

 		1. Bloom filters MIGHT BE generate some False(错误的) Positive(filter中已经存在) results.
 			False positive means, it might tell that given username is already taken but actually it’s not.
 				(也就是 filter 认为数据已经存在了，实际上并没有)

 		2. Bloom filters NEVER generate false negative result
 			也就是不会出现: filter 认为没有 但是实际上却有

 */

/*42亿多*/
#define MAX_SIZE		UINT32_MAX

using namespace std;

typedef void (*pFun)( );

class BloomFilter{

public:
	BloomFilter() {
		hash_func[0] = APHash;
		hash_func[1] = SDBMHash;
		hash_func[2] = RSHash;

		// 在堆里边申请空间，栈的话有限制，直接崩溃
		p_bitset =  new bitset<MAX_SIZE>;
	}

	long cal_array_length(long estimated_element_cnt, float expected_false_positive_probability) {
		/*
		 m = - (n * ln(p)) / (ln(2) ^ 2)

		 参考基准： 1亿元素，要求错误率在万分之一，需要 1917011675 bit, 大约 228 MB
		 */

		long array_size = - (estimated_element_cnt * logf(expected_false_positive_probability)) / (pow(logf(2), 2));

		cout << "need_size:" << array_size << endl;

		return array_size;
	}

	void add(string key) {
		for(auto func : hash_func) {
			size_t val = func(key.c_str()) % MAX_SIZE;
			p_bitset->set(val);
		}
	}

	bool exist(string key) {
		for(auto func : hash_func) {
			size_t val = func(key.c_str()) % MAX_SIZE;
			if (!p_bitset->test(val)) return false;
		}

		return true;
	}

private:
	// bitset<1917011675> _bitset;	// 直接崩溃，栈空间限制

	bitset<MAX_SIZE>* p_bitset;
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

	filter.cal_array_length(1000000000, 0.0001);

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
