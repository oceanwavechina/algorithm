/*
 * 04_reverse_integer.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: liuyanan
 */




#include <iostream>

using namespace std;

int reverse(int x) {
	int ret = 0;

	while(x !=0) {
		ret = ret*10 + x%10;

		x = x/10;
	}

	return ret;
}

int main(int argc, char **argv) {

	int num = -321;
	cout << "original number:" << num << endl;

	cout << "after reverse:" << reverse(num) << endl;

	return 0;
}

