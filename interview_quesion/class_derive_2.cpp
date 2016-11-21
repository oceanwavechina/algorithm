/*
 * class_derive_2.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: liuyanan
 */




#include <iostream>

using namespace std;

class A
{
public:
	int m_a;
};

class B
{
public:
	int m_b;
};

class C: public A, public B
{
public:
	int m_c;
};

int main()
{
	C c;
	B *pb_1 = &c;

	/*
		0x7fff5057f178
		0x7fff5057f17c
		0x7fff5057f178
		0x7fff5057f178
	 */
	cout << &c << endl;
	cout << pb_1 << endl;
	cout << "is equal:" << (pb_1 ==  &c) << endl;
	cout << (C*)pb_1 << endl;
	cout << static_cast<C*>(pb_1) << endl;
	cout << endl;

	/*
		0x7fff5057f170
		0x7fff5057f170
		0x7fff5057f170
	 */
	A a;
	C *pc_1 = (C*)(&a);
	cout << &a << endl;
	cout << pc_1 << endl;
	cout << (A*)pc_1 << endl;
	cout << endl;

	/*
	 * 1. 以上两个的不同，是因为， 将一个派生类的指针转换成某一个基类指针，
	 * 		编译器会将指针的值便宜到该基类在对象内存中的起始位置
	 *
	 * 2. 为什么 'is equal' 输出的是 1 ?
	 * 		这是因为编译器为大家屏蔽了这种指针的差异， 当编译器发现一个指向派生类的指针和指向某个基类的指针进行 == 运算是，
	 * 		会自动将指针隐式类型提升，以屏蔽多重继承带来的指针差异。
	 * 		因为两个指针做比较，目的通常是判断两个指针是否指向了同一个内存对象实例。
	 */


	/*
		0x7fff5057f168
		0x7fff5057f164
		0x7fff5057f168
	 */
	B b;
	C *pc_2 = (C*)(&b); // 这种虽然强转可以，但是没什么意义
	C *pc_2_t = dynamic_cast<C*>(&b);
	C *pc_2_s = reinterpret_cast<C*>(&b);
	C *pc_2_p = static_cast<C*>(&b);
	cout << &b << endl;
	cout << pc_2 << endl;
	cout << dynamic_cast<B*>(pc_2) << endl;
	cout << endl;

	return 0;
}
