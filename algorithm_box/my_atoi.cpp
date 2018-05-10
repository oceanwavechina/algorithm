/*
 * my_atoi.cpp
 *
 *  Created on: May 7, 2018
 *      Author: liuyanan
 */


#include <iostream>

using namespace std;


int my_atoi(const char* str)
{
	int ret = 0;
	int sign = 1;

	/*
	  	  1. 是否为空
	  	  2. 判断符号
	  	  3. 前置空格的处理
	 */

	if(! str) {
		return 0;
	}

	// 跳过空格
	while(*str == ' ') {
		++str;
	}

	// 判断符号
	if(*str == '-') {
		sign *= -1;
		++str;
	}
	if(*str == '+') {
		++str;
	}

	while(*str >= '0' && *str <= '9') {
		ret = ret * 10 + (*str-'0');
		++str;
	}

	return ret * sign;
}


int main(int argc, char **argv) {

	const char* test_case[] = {
			"   -12x23",
			"a123",
			NULL,
			"",
			"9484904",
			"9840  3",
	};

	int size = sizeof(test_case) / sizeof( char* );
	for(int i = 0; i < size; ++i) {
		if(test_case[i]) {
			cout << "\"" << test_case[i] << "\"  ->  ";
		} else {
			cout << "\"NULL\"  ->  ";
		}

		cout << my_atoi(test_case[i]) << endl;
	}


	return 0;
}
