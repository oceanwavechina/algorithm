/*
 * Problem1.cpp
 *
 *  Created on: Sep 3, 2016
 *      Author: liuyanan
 *     Problem: implement a sort in a language with libraries for representing and sorting sets
 */

#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

#include <stdlib.h>


/*
 * run with: $ ./Problem1 < data.txt
 */

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}

// 因为set本身就是有序的：contains a sorted set of unique objects of type Key。
// 						Sets are usually implemented as red-black trees
int cpp_sort() {

	std::set<int> S;

	// load data from std::cin
	int a;
	while(std::cin >> a)
		S.insert(a);

	std::cout << "after sort by cpp_set data:" << display(S) << std::endl;

	return 0;
}

int compare(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;

	return (arg1 > arg2) - (arg1 < arg2);
}

/*
 * sizeof 的实现, 用到的是指针加一后，增量是该数据类型的长度
 *		#define sizeof_v(var) ( (size_t) ( (char*)( &(var)+1 ) - (char*)&(var) ) )
 *		#define sizeof_t(type) ( (size_t) ((type*)0 + 1) )
 *
 * 注意括号，也就是强转的是哪个指针
 */
int c_sort() {
	int index = 0;
	int S[50] = {0};
	int size = sizeof S / sizeof *S;

	int a;
	while(std::cin >> a) {
		S[index] = a;
		++index;
	}

	qsort(S, size, sizeof(int), compare);

	for (int i = 0; i < size; i++) {
		printf("%d ", S[i]);
	}
	printf("\n");

	printf("sizeof (char*)0+1=%lu\n", ((size_t)((char*)0+1)));
	printf("sizeof (int*)0+1=%lu\n", ((size_t)((int*)0+1)));
	printf("sizeof (long*)0+1=%lu\n", ((size_t)((long*)0+1)));
	printf("sizeof (long long*)0+1=%lu\n", ((size_t)((long long*)0+1)));

	printf("max number=%hu\n", (short unsigned)(-1));

	return 0;
}

int main() {
	// cpp_sort();
	c_sort();
}
