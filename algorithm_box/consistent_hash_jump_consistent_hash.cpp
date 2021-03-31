/*
 * jump_consistent_hash.cpp
 *
 *  Created on: Mar 31, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;


/*
	A Fast, Minimal Memory, Consistent Hash Algorithm
		https://arxiv.org/pdf/1406.2294.pdf

	jump consistent hash 的推导过程
		https://zhuanlan.zhihu.com/p/104124045

	这里用到的一个技巧就是单当 srand() 中的种子固定时，每次生成的随机数的序列是相同的

	hash 本身的性质就是要将 key 散列的均匀； 而一致性hash，除了分布均匀之外，还要满足节点修改时的一致性，即：
		which says that when the number of buckets is increased,
		objects move only from old buckets to new buckets,
		thus doing no unnecessary rearrangement.

		也就是说，新加节点后，为了满足均匀的性质，势必会有一些key会移动。而一致性保证的是，key只是从旧的bucket中到新的bucket中的移动
		而不是大部分key都要动一下，最好的是，每个旧bucket中有小部分key分配到新的bucket中
		也就是说，在新加了bucket之后，对于原来的key，在hash之后要么不动，要么分到新的bucket，而不是在老的bucket之间移动
		有如下递归关系

		========================================================
			假设ch(n) 函数的值域是 [0, n-1)

			ch(key, 1) = 0

						 | -> ch(key, n-1)
			ch(key, n) = |
						 | -> n-1
		========================================================
 */


unsigned int ch_consistent_without_uniformity(unsigned int key, unsigned int n)
{
	/*
	  如何做到一致性的？
	  	  1. 首先，对于给定的key，每次调用该函数，生成的随机序列都会一样的,
	  	  	  也就是返回的id的值，**取决于调用rand()的次数**，而不会rand()本身

	  	  2. 根据1的性质， 当n不变时，我们得到的hash结果永远是相同的

	  	  3. 要保证一致性，我们只需要控制rand()的 **调用次数是单调递增(不必是严格递增)** 的就可以

	  	  4. 如下while循环，当 n(桶的个数) 变化时，rand()的调用次数，要么和之前一样，要么会增加
	  	  	  至于增加多少次，我们并不关心，因为次数一旦确定，那下次肯定还是这个次数
	  	  	  所以是满足函数返回值是满足上边的递归公式的
	 */

    srand(key);
    unsigned int id = 0;
    unsigned int fence = rand();
    while (n > fence)
    {
        id = fence;
        fence = id + rand();
    }

    return id;
}

int32_t JumpConsistentHash(uint64_t key, int32_t num_buckets)
{
	int64_t b = 1, j = 0;

	while (j < num_buckets) {
		b = j;
		key = key * 2862933555777941757ULL + 1;
		j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));
	}

	return b;
}

void test_jump_hash(size_t bucket_cnt)
{
	ostringstream oss;
	oss << "bucket_size: " << bucket_cnt << "\n";

	map<int32_t/*hash*/, vector<uint64_t>/*key*/> hashes;

	for(uint64_t key = 0; key < 100; ++key) {
		//oss << "\t" << "key:" << key << ", hash:" << JumpConsistentHash(key, bucket_cnt);
		hashes[JumpConsistentHash(key, bucket_cnt)].push_back(key);
	}

	for (auto item : hashes) {

		oss << "\thash:" << item.first << ", keys:";

		for(auto key : item.second) {
			oss << key << ",";
		}
		oss << "\n";

	}
	oss << "\n";

	cout << oss.str() << endl;
}

void test_srand(int round)
{
	/*
		If rand() is used before any calls to srand(), rand() behaves as if it was seeded with srand(1).
		Each time rand() is seeded with the same seed, it must produce the same sequence of values.
		srand() is not guaranteed to be thread-safe.
	 */

	srand(1);

	cout << "srand(1), round:" << round << ", rand numbers:";
	for(int i=0; i<10; ++i) {
		cout << rand() << ",";
	}
	cout << "\n" << endl;
}


int main(int argc, char **argv)
{
	for(size_t cnt=0; cnt<10; ++cnt) {
		test_jump_hash(cnt);
	}

	for(int i=0; i<10; ++i) {
		test_srand(i);
	}
}

