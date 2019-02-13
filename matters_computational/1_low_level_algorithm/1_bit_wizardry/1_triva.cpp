/*
 * 1_triva.cpp
 *
 *  Created on: Dec 29, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <cmath>

#include "../util.h"

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
void pitfall_cast_pointer_to_int() {
	const char* s = "fad";

	ostringstream oss;
	Formatter formater(__FUNCTION__);

	oss << "sizeof(pointer): " << sizeof s << ", sizeof(int): " << sizeof(int);
	formater << oss;

	/*
	int integer = (int)s;
	cout  << "pointer:" << s<< ", integer:" << integer << endl;
	*/
}


/*
 *	无符号的右移位都好说
 *	如果是有符号的右移，当等于-1的时候，要注意下
 *
 *	如果是左移，超过 k==31 位的时候回变成原来的值
		这可能是因为cpu 做了这个操作 k=k%32 的操作，如果 >0 则进行移位操作

	其中还有正数
	(-22<<26): -1476395008
	(-22<<27): 1342177280
	(-22<<28): -1610612736
	(-22<<29): 1073741824
	(-22<<30): -2147483648
 */
void pitfall_shift_and_division() {
	int a = -1;
	int c = a >> 1;
	int d = a / 2;

	ostringstream oss;
	Formatter formater(__FUNCTION__);

	oss << "(-1>>1): " << c << ", binary: " << binary_str(c);
	formater << oss;
	oss << ", (-1/2): " << d << ", binary: " << binary_str(d);
	formater << oss;

	int e = a << 1;
	int f = a * 2;
	oss << "(-1<<1): " << e << ", binary: " << binary_str(e);
	formater << oss;
	oss<< "(-1*2): " << f << ", binary: " << binary_str(f);
	formater << oss;

	a = -22;
	int g = a >> 1;
	int h = a / 2;
	oss << "(-22<<1): " << g << ", binary: " << binary_str(f);
	formater << oss;
	oss << "(-22*2): " << h << ", binary: " << binary_str(f);
	formater << oss;

	int i = 0;
	string marker;
	while(++i < sizeof(i)*8+5) {
		a = -22;
		(a << i) > 0 ? marker = "\t\t<<--!!!!" : marker = "";

		i >= (sizeof(i) *8) ? marker += "\t\t<<-- shift by i%(sizeof(a)*8)" : marker += "";

		i % (sizeof(i) *8) == 0 ? marker += "\t\t<<-- omit" : marker += "";
		
		oss << "(-22<<" << i << "): " << (a << i) << ",\t\tbinary: " << binary_str(a << i) << marker;
		formater << oss;
	}
}


/*
 * 首先数值的类型是 16bit的，如果是32bit的就不是这个数了，但是一定有这样的结果
 *	-32768 的补码表示 		 是 1...............
 *	-32768 * -1, 的补码表示依然是 1...............
 *	abs(函数对于int所能表示的最小负数，返回也是不对的)
 */
void pitfall_twos_complement() {
	ostringstream oss;
	Formatter formater(__FUNCTION__);

	// short x =-32768;
	int x =-2147483648;
	oss << "x:" << x << ", binary: " << binary_str(x);
	formater << oss;
	if(x < 0)
		x = -x;

	oss << "-x: " << x << ", binary: " << binary_str(x);
	formater << oss;

	oss << "abs(x): " << abs(x) << ", binary: " << binary_str(abs(x)) << "\n";
	formater << oss;


	short s =-32768;
	oss << "s:" << s << ", binary: " << binary_str(s);
	formater << oss;
	if(s < 0)
		s = -s;

	oss << "-s: " << s << ", binary: " << binary_str(s);
	formater << oss;

	oss << "abs(s): " << abs(s) << ", binary: " << binary_str(abs(s));

	formater << oss;
}

/*
 *	对一个数右移k位
 *		如果 k=sizeof(type)， 我们并不会的到0，而是原来的数, cpu会忽略此次运算
 *		所以我们希望得到预期的结果时，要加上shift为0的判断
 */
void pitfall_shift_max() {

	ostringstream oss;
	Formatter formater(__FUNCTION__);

	typedef unsigned long TYPE;
	TYPE num = ~0;
	TYPE shift = 0;
	TYPE t = num >> (8*sizeof(TYPE) - shift);
	oss << num << " shift " << (8*sizeof(TYPE) - shift) << " bit: " << t << ", binary:" << binary_str(t);
	formater << oss;

	shift = 1;
	t = num >> (8*sizeof(TYPE) - shift);
	oss << num << " shift " << (8*sizeof(TYPE) - shift) << " bit: " << t << ", binary:" << binary_str(t);
	formater << oss;

	shift = 0;
	if(shift == 0) {
		t = 0;
		oss << num << " shift " << (8*sizeof(TYPE) - shift) << " bit with fix: " << t << ", binary:" << binary_str(t);
		formater << oss;
	}
}

void short_cut() {
	ostringstream oss;
	Formatter formater(__FUNCTION__);
	
	int a = 0;
	int b = 1;

	// 判断a, b 中至少有一个是0
	oss << "( " << a << "," << b << " ): at least has one 0: " << (! (a&b));
	formater << oss;

	// 判断a,b中都为0
	oss << "( " << a << "," << b << " ): both are 0: " << ((a|b)==0);
	formater << oss;
	a = 0;
	b = 0;
	int c = 0;
	oss << "( " << a << "," << b << "," << c << " ): both are 0: " << ((a|b|c)==0);
	formater << oss;

	// 只有一个是0
	oss << "( " << a << "," << b << " ): exactly has one 0: " << ((!a)^(!b));
	formater << oss;
	a = 1;
	b = 0;
	oss << "( " << a << "," << b << " ): exactly has one 0: " << ((!a)^(!b));
	formater << oss;
}

void next_or_previous_even_or_odd_value() {
	ostringstream oss;
	Formatter formater(__FUNCTION__);

	u_long x = 7;

	oss << "x:" << x;
	formater << oss;

	oss << "next_even of x:" << (x+2-(x&1));
	formater << oss;
	
	oss << "pre_even of x:" << (x-2+(x&1));
	formater << oss;

	oss << "next_odd of x:" << (x+1+(x&1));
	formater << oss;
	
	oss << "pre_odd of x:" << (x-1-(x&1));
	formater << oss;
}

/*
	用整形做乘法容易溢出，浮点数表示的范围比较大

	111111111 * 111111111 = 12345678987654321
*/
void integer_versus_float_multiplication() {
	ostringstream oss;
	Formatter formater(__FUNCTION__);
	
	uint32_t i = 111111111;
	oss << "uint32_t " << i  << " x " << i << " = " << i*i;
	formater << oss;

	
	oss.precision(53);
	float f = 111111111;
	oss << "float " << f  << " x " << f << " = " << f*f;
	formater << oss;

	float d = 111111111;
	oss << "double " << d  << " x " << d << " = " << d*d;
	formater << oss;

	uint64_t i_64 = 111111111;
	oss << "uint64_t (" << i  << " x " << i << ")% 2**32 = " << ((i*i)%long(pow(2,32)));
	formater << oss;
}

void is_power_of_2() {
	/*
		判断一个数是不是2的幂
		NOTE:
			利用率 x-1 会把最低有效位到末位的0，全置成1
			而把最低有效位置成0
	*/
	ostringstream oss;
	Formatter formater(__FUNCTION__);

	int64_t num = 1024;
	oss << num << " is power of 2: " << !(num & (num-1));
	formater << oss;

	num = -1024;
	oss << num << " is power of 2: " << !(num & (num-1));
	formater << oss;

	num = 0;
	oss << num << " is power of 2: " << !(num & (num-1));
	formater << oss;

}

int main(int argc, char **argv) {
	is_little_endian();
	
	// 位运算中存在的坑
	pitfall_cast_pointer_to_int();
	pitfall_shift_and_division();
	pitfall_twos_complement();
	pitfall_shift_max();
	
	// 常用的简便判断
	short_cut();
	
	// 查找下一个奇数或偶数
	next_or_previous_even_or_odd_value();
	integer_versus_float_multiplication();

	// 判断是不是2的幂
	is_power_of_2();
	
	return 0;
}
