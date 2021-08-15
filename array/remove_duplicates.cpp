/*
 * remove_duplicates.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <string>



/*
	问题：
		Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
		Do not allocate extra space for another array, you must do this in place with constant memory.

		For example,
			Given input array A = [1,1,2],
			Your function should return length = 2, and A is now [1,2].

	玩法是：
		1. 用一个指针(下标) left，表示最新的一个不重复的元素。
		2. 另一个指针 cursor 从左到右进行遍历，当发现跟 left 对应的元素不一样则放到 left+1 的 位置
		3. 需要注意的是 left 只有当不重复元素 append 时才向右移动
			而 cursor 是遍历的指针，没检查一个元素就向右移动。

	这个题的延时玩法是允许有两个重复的。
 */


/*
 * return the length of new array
 */
int remove_duplicates(int A[], int len) {
	int l_index = 0;
	int cursor = 0;

	while (cursor < len) {
		if (A[l_index] != A[cursor]) {
			A[++l_index] = A[cursor];
		}
		++cursor;
	}

	++l_index;

	while (l_index < cursor){
		A[l_index++] = 0;
	}

	return l_index+1;
}

int remove_duplicates_2(int A[], int len) {
	int left = 0;

	for (int cursor=1; cursor<len; ++cursor) {
		if (A[left] != A[cursor]) {
			A[++left] = A[cursor];
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
	len = remove_duplicates_2(A, len);
	display(A, len, "after removed:");

	return 0;
}
