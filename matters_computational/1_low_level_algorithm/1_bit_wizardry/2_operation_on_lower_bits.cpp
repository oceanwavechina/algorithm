/*
 * @Author: liuyanan 
 * @Date: 2019-02-13 15:54:27 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-13 17:43:10
 */

#include <iostream>
#include <sstream>
#include <cmath>

#include "../util.h"

using namespace std;

class LowestBit{
public:
	/*
		返回最低有效位代表的那个word，也就是只设置不为0的最低有效位的word
        NOTE:
            用的是-x 是x各位取反，然后末位加一，
            这样 最低有效位左边和原来相反，而右边和原来相同
	*/
	void word_of_lowest_one() {
		ostringstream oss;
		Formatter formater(string(typeid(this).name()) + "::" + __FUNCTION__);
		u_long x = 10;
		
        oss	<< "x = " << long(x);
		formater << oss;
        oss	<< "binary = " << binary_str(x);
		formater << oss;

		oss	<< "word of lowest bit = " << (x&-x);
		formater << oss;
        oss	<< "binary = " << binary_str(x&-x);
		formater << oss;
	}

	/*
		把最后出现的一个0置成1
        NOTE:
            注意 +1 和 -1 对二进制的影响
                前者是改变最后一个零，但是把后边的1就置成0了
                后者是改变最后一个壹，但是把后边的0就置成1了
	*/
	void set_lowest_zero() {
		ostringstream oss;
		Formatter formater(string(typeid(this).name()) + "::" + __FUNCTION__);
		
		u_long x = 13;

		oss << "x = " << x;
		formater << oss;
		oss << "binary = " << binary_str(x);
		formater << oss;
		
        oss	<< "after set lowest zero bit = " << (x|(x+1));
		formater << oss;
		oss	<< "binary = " << binary_str(x|(x+1));
		formater << oss;
	}

	/*
		把最后出现一个1置成0
	*/
	void clear_lowest_one() {
		ostringstream oss;
		Formatter formater(string(typeid(this).name()) + "::" + __FUNCTION__);

		u_long x = 10;

		oss	<< "x = " << x;
		formater << oss;
		oss	<< "binary = " << binary_str(x);
		formater << oss;
		
        oss	<< "after clear lowest one bit = " << (x&(x-1));
		formater << oss;
		oss	<< "binary = " << binary_str(x&(x-1));
		formater << oss;
	}

	/*
		返回最地有效位有一个1的索引
	*/
	void counting_the_index_of_the_lowest_one() {
		ostringstream oss;
		Formatter formater(string(typeid(this).name()) + "::" + __FUNCTION__);

		u_long x = 8;
		oss	<< "x = " << x;
		formater << oss;
		oss	<< "binary = " << binary_str(x);
		formater << oss;

		// O(1)时间
		u_long index = x;
		asm("bsfq %0, %0" : "=r" (index) : "0" (index));
		oss	<< "index of " << x << "'s lowest one bit(using asm:'bsfq') = " << (index);
		formater << oss;

		/* O(logn)时间
				这个是二分查找的思想，从高位到低位判断
		 */
		x = 1;
		x &= -x; // 先找到最后一个 1
		index = 0;
		if ( x & 0xffffffff00000000UL ) index += 32;
		if ( x & 0xffff0000ffff0000UL ) index += 16;
		if ( x & 0xff00ff00ff00ff00UL ) index += 8;
		if ( x & 0xf0f0f0f0f0f0f0f0UL ) index += 4;
		if ( x & 0xccccccccccccccccUL ) index += 2;
		if ( x & 0xaaaaaaaaaaaaaaaaUL ) index += 1;

		oss	<< "index of " << x <<"'s lowest one bit(using divide_and_conquer) = " << index;
		formater << oss;
	}

	void test() {
		word_of_lowest_one();
		set_lowest_zero();
		clear_lowest_one();
		counting_the_index_of_the_lowest_one();
	}
};

/*
    以最低有效位为中心，左右分别置零或置1
*/
class CreatingATransitionAtTheLowestOne{
public:

    /*
        从最低有效位到最高有效位都置成1，其余置成0
        Example: 00110100 --> 11111100
            1. -x = (11001011 + 1)
                  = 11001100
            2.  x = 00110100
            3. 此时只要 或运算 就行了
        NOTE:
            这个要点在取负数，因为取负数，是“各位取反，然后末位加1”，
            这样最低有效位到末位都是0的形式保持不变，
            与原数取“或”后，最低有效位到头位都变成1了
        EXTENTION:
            根据例子可以知道如果用异或也可以区分左右两边，
            只不过最低有效位被分到0那边了
    */
    void lowest_one_10edge() {
        ostringstream oss;
		Formatter formater(string(typeid(this).name()) + "::" + __FUNCTION__);
		
		u_long x = 52;

		oss << "x = " << x;
		formater << oss;
		oss << "binary = " << binary_str(x);
		formater << oss;
		oss	<< "after 10edge = " << (x|-x);
		formater << oss;
		oss	<< "binary = " << binary_str(x|-x);
		formater << oss;        
    }


    /*
        这个是以最低有效位为中心，转换成000...1111的形式
        Example: 00110100 --> 00000111
            1. x-1 = 00110 0 11
            2.   x = 00110 1 00
            3. 可以看到此时 左右两部分分别是相同和相异的关系，在应用异或运算就行了
        NOTE:
            这个是利用 
            1. x-1 是会把最低有效位置成0，而到末位都置成1
        EXTENTION:
            根据例子可以知道如果用异或也可以区分左右两边，
            只不过最低有效位被分到1那边了
    */
    void lowest_one_01edge() {
        ostringstream oss;
		Formatter formater(string(typeid(this).name()) + "::" + __FUNCTION__);
		
		u_long x = 52;

		oss << "x = " << x;
		formater << oss;
		oss << "binary = " << binary_str(x);
		formater << oss;
		oss	<< "after 10edge = " << (x^(x-1));
		formater << oss;
		oss	<< "binary = " << binary_str(x^(x-1));
		formater << oss;        
    }

    /*
        找到 从末位开始两个数字的最长公共 bits
        Example: 
            x = 0 0 110100
            y = 0 0 110100
        相匹配的部分是最右边的部分
    */
    void isolating_the_lowest_run_of_matching_bits() {
        ostringstream oss;
		Formatter formater(string(typeid(this).name()) + "::" + __FUNCTION__);
		
		u_long x = 52;   // 0 0 110100
        u_long y = 116;  // 0 1 110100

		oss << "x = " << x;
		formater << oss;
		oss << "binary = " << binary_str(x);
		formater << oss;

        oss << "y = " << y;
		formater << oss;
		oss << "binary = " << binary_str(y);
		formater << oss;

        /*

        步骤:
            重点是计算掩码
            1. 先找到最低不同的那一位
            2. 计算掩码
            3. 根据掩码找到x,y最低相同的部分

            init:
                x = 00110100
                y = 01110100
            x ^= y:
                x = 01000000
            x &= -x:
               -x = 11000000
              x & = 01000000
            x -= 1:
                x = 00111111
            x & y :
                x = 00110100
        */

        x ^= y;
        x &= -x;
        x -= 1;
        x &= y;

		oss	<< "the lowest matching bits is: " << x;
		formater << oss;
		oss	<< "binary = " << binary_str(x);
		formater << oss;                
    }

    void test() {
		lowest_one_10edge();
        lowest_one_01edge();
        isolating_the_lowest_run_of_matching_bits();
	}
};

int main(int argc, char const *argv[])
{
    LowestBit lowest_bit;
	lowest_bit.test();

    cout << endl;
    
    CreatingATransitionAtTheLowestOne create_transition;
    create_transition.test();
    
    return 0;
}
