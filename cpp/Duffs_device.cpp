/*
 * Duff's_device.cpp
 *
 *  Created on: Apr 16, 2018
 *      Author: liuyanan
 */


#include <string>
#include <iostream>
#include <map>
#include <chrono>
#include <ctime>

using namespace std;

/*
 * unrolling attempts to reduce the overhead of conditional branching needed to check whether a loop is done,
 * by executing a batch of loop bodies per iteration.
 * To handle cases where the number of iterations is not divisible by the unrolled-loop increments,
 * a common technique among assembly language programmers is to jump directly into the middle of the unrolled loop body to handle the remainder.[1]
 * Duff implemented this technique in C by using C's case label fall-through feature to jump into the unrolled body.
 */


/*
 似乎并没有预期中的那么快，就算普通的loop，不开优化都比他快。
 还是memcpy最快

 测试环境： MacPro
  with compiler optimize:
	time of 0copy_with_memcpy: 822.386ms
	time of 1copy_with_loop: 858.357ms
	time of 2copy_with_loop_unrolling8: 1088.54ms
	time of 3copy_with_loop_unrolling16: 1072.76ms
	time of 4copy_with_loop_unrolling32: 1075.05ms
	time of 6copy_with_loop_unrolling128: 1090.27ms
	time of 6copy_with_loop_unrolling64: 1078.92ms

  without compiler optimize:
	time of 0copy_with_memcpy: 832.854ms
	time of 1copy_with_loop: 1495.85ms
	time of 2copy_with_loop_unrolling8: 2149.03ms
	time of 3copy_with_loop_unrolling16: 2151.2ms
	time of 4copy_with_loop_unrolling32: 2171.57ms
	time of 6copy_with_loop_unrolling128: 2182.47ms
	time of 6copy_with_loop_unrolling64: 2179.28ms
 */

void copy_with_loop_unrolling8(const char* src, char* dst, int count)
{
	int n = (count + 7) >> 3;	// 这个n是指要循环多少次

	//cout << "first round with n%8=" << n%8  << ", n=" << n << endl;

	// 这个switch里边的值写错了，这个值是第一次进入时的offset
	switch (count & 7) {

	case 0: do {*dst++ = *src++;

	case 7:		*dst++ = *src++;
	case 6:		*dst++ = *src++;
	case 5:		*dst++ = *src++;
	case 4:		*dst++ = *src++;
	case 3:		*dst++ = *src++;
	case 2:		*dst++ = *src++;
	case 1:		*dst++ = *src++;

	default:
		//cout << ", cur swtich=" << n%7 << endl;
		;

			} while(--n >0);
	}

	return;
}
#ifdef TEST_ASSEMBLLY
//void copy_with_loop_unrolling16(const char* src, char* dst, int count)
//{
//	int n = (count + 15) >> 4;
//
//	switch (count & 15) {
//
//	case 0: do {*dst++ = *src++;
//
//	case 15:		*dst++ = *src++;
//	case 14:		*dst++ = *src++;
//	case 13:		*dst++ = *src++;
//	case 12:		*dst++ = *src++;
//	case 11:		*dst++ = *src++;
//	case 10:		*dst++ = *src++;
//	case 9:		*dst++ = *src++;
//	case 8:		*dst++ = *src++;
//
//	case 7:		*dst++ = *src++;
//	case 6:		*dst++ = *src++;
//	case 5:		*dst++ = *src++;
//	case 4:		*dst++ = *src++;
//	case 3:		*dst++ = *src++;
//	case 2:		*dst++ = *src++;
//	case 1:		*dst++ = *src++;
//
//			} while(--n >0);
//	}
//
//	return;
//}
//
//void copy_with_loop_unrolling32(const char* src, char* dst, int count)
//{
//	int n = (count + 31) >> 5;
//
//	switch (count & 31) {
//
//	case 0: do {*dst++ = *src++;
//	case 31:		*dst++ = *src++;
//	case 30:		*dst++ = *src++;
//	case 29:		*dst++ = *src++;
//	case 28:		*dst++ = *src++;
//	case 27:		*dst++ = *src++;
//	case 26:		*dst++ = *src++;
//	case 25:		*dst++ = *src++;
//	case 24:		*dst++ = *src++;
//	case 23:		*dst++ = *src++;
//	case 22:		*dst++ = *src++;
//	case 21:		*dst++ = *src++;
//	case 20:		*dst++ = *src++;
//	case 19:		*dst++ = *src++;
//	case 18:		*dst++ = *src++;
//	case 17:		*dst++ = *src++;
//	case 16:		*dst++ = *src++;
//	case 15:		*dst++ = *src++;
//	case 14:		*dst++ = *src++;
//	case 13:		*dst++ = *src++;
//	case 12:		*dst++ = *src++;
//	case 11:		*dst++ = *src++;
//	case 10:		*dst++ = *src++;
//	case 9:		*dst++ = *src++;
//	case 8:		*dst++ = *src++;
//	case 7:		*dst++ = *src++;
//	case 6:		*dst++ = *src++;
//	case 5:		*dst++ = *src++;
//	case 4:		*dst++ = *src++;
//	case 3:		*dst++ = *src++;
//	case 2:		*dst++ = *src++;
//	case 1:		*dst++ = *src++;
//			} while(--n >0);
//	}
//
//	return;
//}
//
//
//void copy_with_loop_unrolling64(const char* src, char* dst, int count)
//{
//	int n = (count + 63) >> 6;
//
//	switch (count & 63) {
//
//	case 0: do {*dst++ = *src++;
//
//	case 63:		*dst++ = *src++;
//	case 62:		*dst++ = *src++;
//	case 61:		*dst++ = *src++;
//	case 60:		*dst++ = *src++;
//	case 59:		*dst++ = *src++;
//	case 58:		*dst++ = *src++;
//	case 57:		*dst++ = *src++;
//	case 56:		*dst++ = *src++;
//	case 55:		*dst++ = *src++;
//	case 54:		*dst++ = *src++;
//	case 53:		*dst++ = *src++;
//	case 52:		*dst++ = *src++;
//	case 51:		*dst++ = *src++;
//	case 50:		*dst++ = *src++;
//	case 49:		*dst++ = *src++;
//	case 48:		*dst++ = *src++;
//	case 47:		*dst++ = *src++;
//	case 46:		*dst++ = *src++;
//	case 45:		*dst++ = *src++;
//	case 44:		*dst++ = *src++;
//	case 43:		*dst++ = *src++;
//	case 42:		*dst++ = *src++;
//	case 41:		*dst++ = *src++;
//	case 40:		*dst++ = *src++;
//	case 39:		*dst++ = *src++;
//	case 38:		*dst++ = *src++;
//	case 37:		*dst++ = *src++;
//	case 36:		*dst++ = *src++;
//	case 35:		*dst++ = *src++;
//	case 34:		*dst++ = *src++;
//	case 33:		*dst++ = *src++;
//	case 32:		*dst++ = *src++;
//	case 31:		*dst++ = *src++;
//	case 30:		*dst++ = *src++;
//	case 29:		*dst++ = *src++;
//	case 28:		*dst++ = *src++;
//	case 27:		*dst++ = *src++;
//	case 26:		*dst++ = *src++;
//	case 25:		*dst++ = *src++;
//	case 24:		*dst++ = *src++;
//	case 23:		*dst++ = *src++;
//	case 22:		*dst++ = *src++;
//	case 21:		*dst++ = *src++;
//	case 20:		*dst++ = *src++;
//	case 19:		*dst++ = *src++;
//	case 18:		*dst++ = *src++;
//	case 17:		*dst++ = *src++;
//	case 16:		*dst++ = *src++;
//	case 15:		*dst++ = *src++;
//	case 14:		*dst++ = *src++;
//	case 13:		*dst++ = *src++;
//	case 12:		*dst++ = *src++;
//	case 11:		*dst++ = *src++;
//	case 10:		*dst++ = *src++;
//	case 9:		*dst++ = *src++;
//	case 8:		*dst++ = *src++;
//	case 7:		*dst++ = *src++;
//	case 6:		*dst++ = *src++;
//	case 5:		*dst++ = *src++;
//	case 4:		*dst++ = *src++;
//	case 3:		*dst++ = *src++;
//	case 2:		*dst++ = *src++;
//	case 1:		*dst++ = *src++;
//			} while(--n >0);
//	}
//
//	return;
//}
//
//void copy_with_loop_unrolling128(const char* src, char* dst, int count)
//{
//	int n = (count + 127) >> 7;
//
//	switch (count & 127) {
//
//	case 0: do {*dst++ = *src++;
//
//	case 127:		*dst++ = *src++;
//	case 126:		*dst++ = *src++;
//	case 125:		*dst++ = *src++;
//	case 124:		*dst++ = *src++;
//	case 123:		*dst++ = *src++;
//	case 122:		*dst++ = *src++;
//	case 121:		*dst++ = *src++;
//	case 120:		*dst++ = *src++;
//	case 119:		*dst++ = *src++;
//	case 118:		*dst++ = *src++;
//	case 117:		*dst++ = *src++;
//	case 116:		*dst++ = *src++;
//	case 115:		*dst++ = *src++;
//	case 114:		*dst++ = *src++;
//	case 113:		*dst++ = *src++;
//	case 112:		*dst++ = *src++;
//	case 111:		*dst++ = *src++;
//	case 110:		*dst++ = *src++;
//	case 109:		*dst++ = *src++;
//	case 108:		*dst++ = *src++;
//	case 107:		*dst++ = *src++;
//	case 106:		*dst++ = *src++;
//	case 105:		*dst++ = *src++;
//	case 104:		*dst++ = *src++;
//	case 103:		*dst++ = *src++;
//	case 102:		*dst++ = *src++;
//	case 101:		*dst++ = *src++;
//	case 100:		*dst++ = *src++;
//	case 99:		*dst++ = *src++;
//	case 98:		*dst++ = *src++;
//	case 97:		*dst++ = *src++;
//	case 96:		*dst++ = *src++;
//	case 95:		*dst++ = *src++;
//	case 94:		*dst++ = *src++;
//	case 93:		*dst++ = *src++;
//	case 92:		*dst++ = *src++;
//	case 91:		*dst++ = *src++;
//	case 90:		*dst++ = *src++;
//	case 89:		*dst++ = *src++;
//	case 88:		*dst++ = *src++;
//	case 87:		*dst++ = *src++;
//	case 86:		*dst++ = *src++;
//	case 85:		*dst++ = *src++;
//	case 84:		*dst++ = *src++;
//	case 83:		*dst++ = *src++;
//	case 82:		*dst++ = *src++;
//	case 81:		*dst++ = *src++;
//	case 80:		*dst++ = *src++;
//	case 79:		*dst++ = *src++;
//	case 78:		*dst++ = *src++;
//	case 77:		*dst++ = *src++;
//	case 76:		*dst++ = *src++;
//	case 75:		*dst++ = *src++;
//	case 74:		*dst++ = *src++;
//	case 73:		*dst++ = *src++;
//	case 72:		*dst++ = *src++;
//	case 71:		*dst++ = *src++;
//	case 70:		*dst++ = *src++;
//	case 69:		*dst++ = *src++;
//	case 68:		*dst++ = *src++;
//	case 67:		*dst++ = *src++;
//	case 66:		*dst++ = *src++;
//	case 65:		*dst++ = *src++;
//	case 64:		*dst++ = *src++;
//	case 63:		*dst++ = *src++;
//	case 62:		*dst++ = *src++;
//	case 61:		*dst++ = *src++;
//	case 60:		*dst++ = *src++;
//	case 59:		*dst++ = *src++;
//	case 58:		*dst++ = *src++;
//	case 57:		*dst++ = *src++;
//	case 56:		*dst++ = *src++;
//	case 55:		*dst++ = *src++;
//	case 54:		*dst++ = *src++;
//	case 53:		*dst++ = *src++;
//	case 52:		*dst++ = *src++;
//	case 51:		*dst++ = *src++;
//	case 50:		*dst++ = *src++;
//	case 49:		*dst++ = *src++;
//	case 48:		*dst++ = *src++;
//	case 47:		*dst++ = *src++;
//	case 46:		*dst++ = *src++;
//	case 45:		*dst++ = *src++;
//	case 44:		*dst++ = *src++;
//	case 43:		*dst++ = *src++;
//	case 42:		*dst++ = *src++;
//	case 41:		*dst++ = *src++;
//	case 40:		*dst++ = *src++;
//	case 39:		*dst++ = *src++;
//	case 38:		*dst++ = *src++;
//	case 37:		*dst++ = *src++;
//	case 36:		*dst++ = *src++;
//	case 35:		*dst++ = *src++;
//	case 34:		*dst++ = *src++;
//	case 33:		*dst++ = *src++;
//	case 32:		*dst++ = *src++;
//	case 31:		*dst++ = *src++;
//	case 30:		*dst++ = *src++;
//	case 29:		*dst++ = *src++;
//	case 28:		*dst++ = *src++;
//	case 27:		*dst++ = *src++;
//	case 26:		*dst++ = *src++;
//	case 25:		*dst++ = *src++;
//	case 24:		*dst++ = *src++;
//	case 23:		*dst++ = *src++;
//	case 22:		*dst++ = *src++;
//	case 21:		*dst++ = *src++;
//	case 20:		*dst++ = *src++;
//	case 19:		*dst++ = *src++;
//	case 18:		*dst++ = *src++;
//	case 17:		*dst++ = *src++;
//	case 16:		*dst++ = *src++;
//	case 15:		*dst++ = *src++;
//	case 14:		*dst++ = *src++;
//	case 13:		*dst++ = *src++;
//	case 12:		*dst++ = *src++;
//	case 11:		*dst++ = *src++;
//	case 10:		*dst++ = *src++;
//	case 9:		*dst++ = *src++;
//	case 8:		*dst++ = *src++;
//	case 7:		*dst++ = *src++;
//	case 6:		*dst++ = *src++;
//	case 5:		*dst++ = *src++;
//	case 4:		*dst++ = *src++;
//	case 3:		*dst++ = *src++;
//	case 2:		*dst++ = *src++;
//	case 1:		*dst++ = *src++;
//			} while(--n >0);
//	}
//
//	return;
//}

#endif
void copy_with_loop(const char* src, char* dst, int count)
{
	for(int i=0; i<count; ++i) {
		*dst = *src;
	}
}

void copy_with_memcpy(const char* src, char* dst, int count)
{
	memcpy(dst, src, count);
}

//#define TEST_UNROLLING_LOOP
int main(int argc, char **argv) {

#ifdef TEST_UNROLLING_LOOP
	const char* src = "testwithsomecharactorsbalabala";
	char dst[100] = {0};

	copy_with_loop_unrolling(src, dst, strlen(src));

	cout << "src(" << strlen(src) << "):" << src << endl;
	cout << "dst(" << strlen(dst) << "):" << dst << endl;
	bool ret = string(src) ==  string(dst);
	cout << "src==dst ? :" << boolalpha << ret << endl;
#else

	int COUNT = 8*1000*1000*100;

	typedef void (*cpfun)(const char* src, char* dst, int count);

	map<string, cpfun> func_map = {
			{"0copy_with_memcpy", copy_with_memcpy},
			{"1copy_with_loop", copy_with_loop},
			{"2copy_with_loop_unrolling8", copy_with_loop_unrolling8},
#ifdef TEST_ASSEMBLLY
			{"3copy_with_loop_unrolling16", copy_with_loop_unrolling16},
			{"4copy_with_loop_unrolling32", copy_with_loop_unrolling32},
			{"6copy_with_loop_unrolling64", copy_with_loop_unrolling64},
			{"6copy_with_loop_unrolling128", copy_with_loop_unrolling128}
#endif
	};

	for (auto it : func_map) {
		char* src = new char[COUNT];
		char* dst = new char[COUNT];

		std::clock_t start = std::clock();
		it.second(src, dst, COUNT);
		std::clock_t end = std::clock();
		std::cout << "time of " << it.first <<": " << 1000.0 * (end-start) / CLOCKS_PER_SEC << "ms" << endl;

		delete[] src; src = nullptr;
		delete[] dst; dst = nullptr;
	}



#endif
	return 0;
}
