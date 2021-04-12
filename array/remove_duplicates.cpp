/*
 * remove_duplicates.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <string>


/*
 * return the length of new array
 */
int remove_duplicates(int A[], int len) {
	int l_index = 0;
	int r_index = 0;

	while (r_index < len) {
		if (A[l_index] != A[r_index]) {
			A[++l_index] = A[r_index];
		}
		++r_index;
	}

	++l_index;

	while (l_index < r_index){
		A[l_index++] = 0;
	}

	return l_index+1;
}

int remove_duplicates_2(int A[], int len) {
	int left = 0;

	for (int i=1; i<len; ++i) {
		if (A[left] != A[i]) {
			A[++left] = A[i];
		}
	}

	return left + 1;
}


int remove_duplicates_allow_twice(int A[], int len) {

	/*
	 * 技巧就是：
	 * 		我们不需要比较左边指针和右边指针的数据是否相等，因为是有序的，只要比较左边指针前一个和右边指针就好
	 *
	 * 有个注意的点就是起始位置的设置，即，左右指针从什么地方开始
	 *
	 */

	int left = 1;
	int ALLOW_MAX_DUPLICATE=3;

	for (int i=2; i<len; ++i) {
		if(A[left-(ALLOW_MAX_DUPLICATE-1)] != A[i]) {
			A[++left] = A[i];
		}
	}

	return left + 1;
}


void display(int A[], int len, const std::string& msg) {

	std::cout << msg;

	int i = 0;
	while ( i < len) {
		std::cout << A[i++];
	}

	std::cout << std::endl;
}


int main(int argc, char **argv) {

	int A[] = {1, 2, 3, 3, 4, 4, 4, 4, 4, 5, 6, 7, 7, 7, 8};

	int len = sizeof A / sizeof(int);


	display(A, len, "original array:");
	//len = remove_duplicates_2(A, len);
	len = remove_duplicates_allow_twice(A, len);
	display(A, len, "after removed:");

	return 0;
}
