/*
 * Duff's_device.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: liuyanan
 */


#include <string>
#include <iostream>

using namespace std;

/*
 * unrolling attempts to reduce the overhead of conditional branching needed to check whether a loop is done,
 * by executing a batch of loop bodies per iteration.
 * To handle cases where the number of iterations is not divisible by the unrolled-loop increments,
 * a common technique among assembly language programmers is to jump directly into the middle of the unrolled loop body to handle the remainder.[1]
 * Duff implemented this technique in C by using C's case label fall-through feature to jump into the unrolled body.
 */

void copy_with_loop_unrolling(const char* src, char* dst, int count)
{
	int n = (count + 7) >> 3;	// 要拷贝的不一定是8的倍数，所以先拷贝零头

	cout << "first round with n%8=" << n%8  << ", n=" << n << endl;

	switch (n & 7) {

	case 0: do {*dst++ = *src++; cout << *(src-1);

	case 7:		*dst++ = *src++; cout << *(src-1);
	case 6:		*dst++ = *src++; cout << *(src-1);
	case 5:		*dst++ = *src++; cout << *(src-1);
	case 4:		*dst++ = *src++; cout << *(src-1);
	case 3:		*dst++ = *src++; cout << *(src-1);
	case 2:		*dst++ = *src++; cout << *(src-1);
	case 1:		*dst++ = *src++; cout << *(src-1);

			} while(--n >0);
	}

	cout << endl;
	return;
}


int main(int argc, char **argv) {

	const char* src = "testwithsomecharactorsbalabala";
	char dst[100] = {0};

	copy_with_loop_unrolling(src, dst, strlen(src));

	cout << "src(" << strlen(src) << "):" << src << endl;
	cout << "dst(" << strlen(dst) << "):" << dst << endl;
	bool ret = string(src) ==  string(dst);
	cout << "src==dst ? :" << boolalpha << ret << endl;

	return 0;
}
