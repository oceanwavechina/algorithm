/*
 * test_new.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <stdlib.h>

using namespace std;

#define TEST_PART

class A{
public:
	A() {
		cout << "A constructor" << endl;
	}

	~A() {
		cout << "A destructor" << endl;
	}

	void test_call_delete_inside(){
		delete this;
	}

#ifndef TEST_PART
	void* operator new(size_t size) {
		std::cout<<"call A::operator new"<<std::endl;
		return malloc(size);
	}
#endif

};



int main(int argc, char **argv) {


#ifdef TEST_PART

	cout << "---------------- start -----------------" << endl;

	A* a  = (A*)::operator new(sizeof (A)); // 只分配, not constructor called

	cout << "------------------ 1 -------------------" << endl;

	new(a) A();	// 只构造, 在上一步分配的对象上调用构造函数

	cout << "------------------ 2 ------------------" << endl;

	a->~A();	// 只析构, 调用析构函数

	cout << "------------------ 3 ------------------" << endl;

	::operator delete(a);	// 只释放

	cout << "---------------- end -----------------" << endl << endl;
#endif

	A* a_1 = new A;
#if 0
	delete a_1;
#else
	a_1->test_call_delete_inside();
#endif

	return 0;
}




