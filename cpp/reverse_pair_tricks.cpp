/*
 * reverse_pair_tricks.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <utility>

using namespace std;

/*
 *	利用了变量内存布局的特点，来交换顺序, 也就是把两个部分的名称换了，而原来的数据并没有移动
 *
 *	原始的
 *				 first		second
 *				 (float)	(int)
 *				|——————————|——————|
 *				|  1.34    |  5   |
 *				|——————————|——————|
 *	转换后的		  second	first
 *				  (float)	(int)
 *
 *	需要注意的是
 *		1. 这样的技巧只适用于POD类型的结构，也就是只有数据成员，没有c++虚函数表引入的类型
 *
 *
 */

template <class Pair>
struct Reverse
{
	typedef typename Pair::first_type second_type;	// 这里的second_type只是命名不同，实际上还是原始的first_type;
	typedef typename Pair::second_type first_type;

//#define HAS_VIRTUAL_FUC
#ifdef HAS_VIRTUAL_FUC
	virtual  void dummy(){};
#endif

//#define TEST_ORDER
#ifdef TEST_ORDER
	// 如果是相同的类型，顺序反了，那不会反转； 如果是不同类型，那可能就转义乱了
	first_type first;
	second_type second;
#else
	second_type second;	// 这里的名称变了，但是实际上对应的是内存中first那个成员，而且类型也是原来的first成员
	first_type first;
#endif
};

template <class Pair>
Reverse<Pair> &mutate(Pair &p)
{
	return reinterpret_cast<Reverse<Pair> &> (p);
}


int main(int argc, char **argv) {

#ifdef TEST_ORDER
	pair<int, int> p(7, 8);
#else
	pair<double, int> p(1.34, 5);
#endif

	cout << "p.first: " << p.first << ", p.second: " << p.second << endl;
	cout << "mutate(p).first: " << mutate(p).first << ", mutate(p).second: " << mutate(p).second << endl;

	return 0;
}
