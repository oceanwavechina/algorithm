/*
 * my_itoa.cpp
 *
 *  Created on: May 7, 2018
 *      Author: liuyanan
 */


#include <iostream>

using namespace std;


char* my_itoa(int number, char* output)
{
	/*
	  	  1. 符号
	  	  2. 等于0的时候的处理
	 */

	if(!output) {
		return NULL;
	}

	int i = 0;
	int n = number;

	if(number < 0) {
		n = -1*number;
		output[i++] = '-';
	} else if (number == 0) {
		output[i++] = '0';
		return output;
	}

	while(n > 0) {
		output[i++] = n % 10 + '0';
		n = n / 10;
	}


	int begin = number >= 0 ? 0 : 1;
	int end =i-1;

	while(begin != end) {
		char tmp = output[begin];
		output[begin] = output[end];
		output[end] = tmp;

		++begin;
		--end;
	}

	return output;
}


int main(int argc, char **argv) {

	int test_case[] = {-1, 0, 122334354, -0, -33334};

	int cnt = sizeof(test_case) /  sizeof(int);

	char output[32] = {0};

	for(int i=0; i< cnt; ++i) {
		memset(output, 0, sizeof(test_case));
		cout << test_case[i] << " -> " << my_itoa(test_case[i], output) << endl;
	}

	return 0;
}
