/*
 * question_tricks.cpp
 *
 *  Created on: May 6, 2018
 *      Author: liuyanan
 */


#include <iostream>
#include <string>

using namespace std;


/* *******************************  call function before main ******************************* */
int func(const string& str="default") { cout << str << endl;  return 0;}

class GlobalObj {
public:
	GlobalObj() { func("in constructor of GlobalObj"); }
};

class StaticObj {
public:
	static int _static_var;
};

// 定义的顺序，决定了调用的顺序
GlobalObj g_glocal_obj;
int StaticObj::_static_var = func("in static member init");




int main(int argc, char **argv) {

	cout << "this is main" << endl;

	return 0;
}
