/*
 * class_derive_3.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: liuyanan
 */




#include <iostream>

using namespace std;

class A
{
public:
	A():m_a(0){};

public:
	int m_a;
};

class B: public A
{
public:
	B():m_a(1){
		A::m_a = 2;
	};

public:
	int m_a;
};

int main()
{
	A a;
	B b;

	cout << "a.m_a = " << a.m_a << ", &a.m_a = " << &a.m_a << endl;
	cout << "b.m_a = " << b.m_a << ", &b.m_a = " << &b.m_a  << endl;
	cout << "b.A::m_a = " << b.A::m_a << ", &a.A::m_a = " << &b.A::m_a  << endl;

	return 0;
}
