/*
 * 05_strstr.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: liuyanan
 */

#include <iostream>

int strLen(const char *origin) {
	int ret = 0;

	if (!origin)
		return ret;

	while(origin[ret] != '\0')
		++ret;

	return ret;
}

int strStr(const char *origin, const char* substr) {
	if (! origin || ! substr)
		return -1;

	int originLen = strLen(origin);
	int sublen = strLen(substr);

	for(int i=0; i<originLen; ++i){
		int j = 0;
		for(; j<sublen; ++j){

			if (i+j == originLen) return -1;

			if (origin[i+j] != substr[j]) break;
		}

		if (sublen == j) return i;
	}

	return -1;
}


int main(int argc, char **argv) {

	const char *origin = "abcdefghijk";
	const char *substr = "efg";

	std::cout << "origin str:" << origin << std::endl;
	std::cout << "sub str:" << substr << std::endl;

	std::cout << "target index:" << strStr(origin, substr) << std::endl;

	return 0;
}



