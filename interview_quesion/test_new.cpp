/*
 * test_new.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <stdlib.h>

using namespace std;

class A{
public:
	A() {
		cout << "A constructor" << endl;
	}

	~A() {
		cout << "A destructor" << endl;
	}

	void* operator new(size_t size) {
		std::cout<<"call A::operator new"<<std::endl;
		return malloc(size);
	}

};



int main(int argc, char **argv) {


#ifdef TEST_PART
	A* a  = (A*)::operator new(sizeof (A)); // 只分配

	new(a) A();	// 只构造

	a->~A();	// 只析构

	::operator delete(a);	// 只释放
#endif

	A* a = new A;
	delete a;

	return 0;
}




