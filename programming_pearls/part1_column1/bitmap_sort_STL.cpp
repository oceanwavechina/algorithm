/*
 * bitmap_sort_STL.cpp
 *
 *  Created on: Sep 3, 2016
 *      Author: liuyanan
 */

/*
 * c++ 实现的版本更加简洁
 * run with: ./bitmap_sort_STL  < data.txt
 *
 */

#include <iostream>
#include <bitset>

#define N	10000

int main() {
	std::bitset<N> b; // already initiated

	// load
	int i;
	while (std::cin >> i)
		b.set(i);

	for(i=0; i<N; ++i)
		if(b.test(i))
			std::cout << i << std::endl;

	return 0;
}
