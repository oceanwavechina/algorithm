/*
 * class_derive.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: liuyanan
 */


#include <iostream>

using namespace std;

class Base
{
public:
	Base(){}
	virtual ~Base() {
		cout << "Base destructor" << endl;
	}


	// void doSomething() {
	virtual void doSomething() {
		cout << "Base do something" << endl;
	}
};


class Derived : public Base
{
public:
	Derived() {}
	virtual ~Derived() {
		cout << "Derived destructor" << endl;
	}

	void doSomething() {
		cout << "Derived do something" << endl;
	}
};


int main()
{
	Derived *p_1 = new Derived();
	p_1->doSomething();
	delete p_1;

	cout << "\n --------------------------------\n " << endl;

	// 加不加 virtual输出的值是不一样的
	// 看对象是哪个，就是调用哪个的方法
	Base *p_2 = new Derived();
	p_2->doSomething();
	delete p_2;

	return 0;
}
