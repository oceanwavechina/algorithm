/*
 * bitmap_sort_STL.cpp
 *
 *  Created on: Sep 3, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <bitset>


#define N				1000

char a[N] = {0};

void add(int i) {
	++a[i];
}

void clr(int i) {
	a[i] = 0;
}

int test(int i) {
	return a[i] > 0;
}

void sample() {
	add(3);
	std::cout << "test set:" << test(3) << std::endl;

	clr(3);
	std::cout << "test clr:" << test(3) << std::endl;
}

int main() {
	int i;
	sample();

	// init
	for (i=0; i<N; ++i)
		clr(i);

	// load
	while (std::cin >> i)
		add(i);

	for(i=0; i<N; ++i)
		if(test(i))
			std::cout << i << " with count:" << (int)a[i] << std::endl;

	return 0;
}
