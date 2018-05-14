/*
 * null_and_virtual_func.cpp
 *
 *  Created on: May 14, 2018
 *      Author: liuyanan
 */

#include <iostream>

using namespace std;

/*
 *	TODO: 请从原理和c++的底层实现上解释
 *
 */


class A
{
public:
	void fun() {
		cout << "fun()" << endl;
	}

	virtual void fun1(){
		cout << "virtual fun()" << endl;
	}
};

int main(int argc, char **argv) {

	A* pa = NULL;

	pa->fun();//调用成功

	pa->fun1();//程序崩溃，报错：引发一场，读取访问权限冲突

	return 0;
}
