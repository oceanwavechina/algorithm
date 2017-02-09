/*
 * strstr.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: liuyanan
 */


#include <iostream>


size_t _strlen(char* str) {
	if (str == NULL) {
		return 0;
	}

#if 0

	int len = 0;
	while(*(str++) != '\0') {
		++len;
	}

	return len;

#else

	char* start = str;
	while(*str++ != '\0');
	return str-start-1;

#endif
}

size_t _strstr(char* origin_str, char* sub_str) {
	if (origin_str == NULL || sub_str == NULL) {
		return NULL;
	}

	int origin_len = _strlen(origin_str);
	int sub_len = _strlen(sub_str);

	for (int i=0; i<=origin_len-sub_len; ++i) {

		int k = i;
		for(int j=0; j<sub_len; ++j) {
			if ( *(origin_str+k) == *(sub_str+j) ) {
				++k;
			} else {
				break;
			}
		}

		if (k-i == sub_len)
			return i;

	}

	return NULL;
}


int main(int argc, char **argv) {

	std::cout << _strlen("test") << std::endl;

	std::cout << _strstr("test", "st") << std::endl;

	return 0;
}


