/*
 * 1_triva.cpp
 *
 *  Created on: Dec 29, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <cmath>

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


/*
 * 首先数值的类型是 16bit的，如果是32bit的就不是这个数了，但是一定有这样的结果
 *	-32768 的补码表示 		 是 1...............
 *	-32768 * -1, 的补码表示依然是 1...............
 */
void pitfall_twos_complement() {
	ostringstream oss;

	short x =-32768;
	oss << "x:" << x;
	if((signed)x < 0)
		// x = -x;
		x = x*-1;

	oss << ", -x:" << x << ", abs(x):" << abs(x);
	cout << oss.str() << endl;
}

/*
 *	对一个数右移k位
 *		如果 k=sizeof(type)， 我们并不会的到0，而是原来的数, cpu会忽略此次运算
 *		所以我们希望得到预期的结果时，要加上shift为0的判断
 */
void shift_max() {
	typedef unsigned long TYPE;
	TYPE num = ~0;
	TYPE shift = 0;
	TYPE t = num >> (8*sizeof(TYPE) - shift);
	cout << num << " shift " << (8*sizeof(TYPE) - shift) << " bit:" << t << endl;

	shift = 1;
	t = num >> (8*sizeof(TYPE) - shift);
	cout << num << " shift " << (8*sizeof(TYPE) - shift) << " bit:" << t << endl;

	shift = 0;
	if(shift == 0) {
		t = 0;
		cout << num << " shift " << (8*sizeof(TYPE) - shift) << " bit with fix:" << t << endl;
	}

}

void short_cut() {
	int a = 0;
	int b = 1;

	// 判断a, b 中至少有一个是0
	cout << "( " << a << "," << b << " ): at least has one 0: " << (! (a&b)) << endl;

	// 判断a,b中都为0
	cout << "( " << a << "," << b << " ): both are 0: " << ((a|b)==0) << endl;
	a = 0;
	b = 0;
	int c = 0;
	cout << "( " << a << "," << b << "," << c << " ): both are 0: " << ((a|b|c)==0) << endl;

	// 只有一个是0
	cout << "( " << a << "," << b << " ): exactly has one 0: " << ((!a)^(!b)) << endl;
	a = 1;
	b = 0;
	cout << "( " << a << "," << b << " ): exactly has one 0: " << ((!a)^(!b)) << endl;
}

void next_or_previous_even_or_odd_value() {
	u_long x = 7;

	cout << "x:" << x;

	cout << "\n\tnext_even of x:" << (x+2-(x&1));
	cout << "\n\tpre_even of x:" << (x-2+(x&1));

	cout << "\n\tnext_odd of x:" << (x+1+(x&1));
	cout << "\n\tpre_odd of x:" << (x-1-(x&1));
	
	cout << endl;
}

/*
	用整形做乘法容易溢出，浮点数表示的范围比较大
*/
void integer_versus_float_multiplication() {
	uint32_t i = 111111111;
	uint64_t i_64 = 111111111;
	float f = 111111111;
	cout << "uint32_t " << i  << " x " << i << " = " << i*i << endl;
	cout << "float " << f  << " x " << f << " = " << f*f << endl;
}

int main(int argc, char **argv) {
	is_little_endian();
	cast_pointer_to_int();
	shift_and_division();
	pitfall_twos_complement();
	shift_max();
	short_cut();
	next_or_previous_even_or_odd_value();
	integer_versus_float_multiplication();

	return 0;
}
