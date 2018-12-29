/*
 * 1_triva.cpp
 *
 *  Created on: Dec 29, 2018
 *      Author: liuyanan
 */

#include <iostream>

using namespace std;


/*
	 数据的有效位的地址也是从低到高增长的是小端
	 这个顺序的最小单位是 byte
 */
union EndianCheck{
	int i;
	char ch;
};
void is_little_endian() {
	EndianCheck a;
	a.i = 1;
	if(a.ch ==1) {
		cout << "little endian" << endl;
	} else {
		cout << "big endian" << endl;
	}
}


/*
 *  在64位机上 int也是32位的，比pointor的数据小
 *  所以这是一个坑
 */
void cast_pointer_to_int() {
	const char* s = "fad";
	cout << "sizeof(pointer): " << sizeof s << ", sizeof(int)" << sizeof(int) << endl;

	//int integer = (int)s;
	// cout  << "pointer:" << s<< ", integer:" << integer << endl;
}


/*
 *	无符号的右移位都好说
 *	如果是有符号的右移，当等于-1的时候，要注意下
 *
 *	如果是左移，超过31位的时候回变成原来的值
 */
void shift_and_division() {
	int a = -1;
	int c = a >> 1;
	int d = a / 2;

	cout << "(-1>>1): " << c << ", (-1/2): " << d << endl;

	int e = a << 1;
	int f = a * 2;
	cout << "(-1<<1): " << e << ", (-1*2): " << f << endl;

	a = -22;
	int g = a >> 1;
	int h = a / 2;
	cout << "(-22<<1): " << g << ", (-22*2): " << h << endl;

	int i = 0;
	while(++i < 33) {
		a = -22;
		cout << "(-22<<" << i << "): " << (a << i) <<  endl;
	}
}


int main(int argc, char **argv) {
	is_little_endian();
	cast_pointer_to_int();
	shift_and_division();

	return 0;
}
