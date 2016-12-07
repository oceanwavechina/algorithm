/*
 * class_derive.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: liuyanan
 */


#include <iostream>

using namespace std;

int i=0;

class Base
{
public:
	Base(){}
	virtual ~Base() {
		cout << "Base destructor" << endl;
	}


	//void doSomething() {
	virtual void doSomething() {
		cout << "Base do something" << endl;
	}
};


class Derived : public Base
{
public:
	Derived() {
		_counter = ++i;
		cout << "construct:" << _counter << endl;
	}
	virtual ~Derived() {
		cout << "Derived destructor: " << _counter << endl;
	}

	void doSomething() {
		cout << "Derived do something" << endl;
	}

private:
	// 对象创建和销毁的顺序
	int _counter;
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

	Derived a[10];

//	Derived* b = new Derived[3];


	return 0;
}
