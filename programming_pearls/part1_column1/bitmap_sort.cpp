/*
 * bitmap_sort.cpp
 *
 *  Created on: Sep 3, 2016
 *      Author: liuyanan
 */

#include <iostream>
#include <bitset>


#define BITS_PER_WORD	32			// 64bit 机器上也是32位
#define SHIFT			5
#define MASK			0x1F
#define N				1000000

int a[1 + N/BITS_PER_WORD] = {0, 0};

void set(int i) {
	a[i>>SHIFT] |= ( 1<<(i & MASK) );
}

void clr(int i) {
	a[i>>SHIFT] &= ~( 1<<(i & MASK) );
}

int test(int i) {
	return a[i>>SHIFT] & ( 1<<(i & MASK) );
}

void sample() {
	set(3);
	std::cout << "test set:" << test(3) << std::endl;

	clr(3);
	std::cout << "test clr:" << test(3) << std::endl;
}

int main() {
	int i;

	// init
	for (i=0; i<N; ++i)
		clr(i);

	// load
	while (std::cin >> i)
		set(i);

	for(i=0; i<N; ++i)
		if(test(i))
			std::cout << i << std::endl;

	return 0;
}
