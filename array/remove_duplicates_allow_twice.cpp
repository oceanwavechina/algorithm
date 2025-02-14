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
		Given a sorted array, remove the duplicates in place, BUT duplicates are allowed at most twice?
		Do not allocate extra space for another array, you must do this in place with constant memory.

		For example:
			Given sorted array A = [1, 1, 1, 2, 2, 3],
			Your function should return length = 5, and A is now [1, 1, 2, 2, 3]

 */


int remove_duplicates_allow_twice(int A[], int len) {

	/*
	 * 技巧就是：
	 * 		我们不需要比较左边指针和右边指针的数据是否相等，因为是有序的，只要比较左边指针前一个和右边指针就好
	 *
	 * 有个注意的点就是起始位置的设置，即，左右指针从什么地方开始
	 *
	 */

	int left = 1;
	int ALLOW_MAX_DUPLICATE = 2;

	for (int cursor=2; cursor<len; ++cursor) {
		if(A[left-(ALLOW_MAX_DUPLICATE-1)] != A[cursor]) {
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
	len = remove_duplicates_allow_twice(A, len);
	display(A, len, "after removed:");

	return 0;
}










/*
    这个是 remove_duplicates.cpp 一个延时题，思路是这样的：

        因为数组是有序的， 所以在给定一个元素(其下标用left 表示) 跟 cursor 判断的时候，就会出现两种情况：
            1. 相等
            2. 不相等

        如果不相等，那就好办了，直接把 cursor 放到 left+1 的位置上。

        如果相等，我们就要判断下 是 <=2 次相等，还是 >2 次相等。也就是我们允许 <=2 次相等的。

           left
            V
        ∆ ∆ ∆ ∆ ∆ ∆ ∆ ∆ ∆ ∆ .... ∆ ∆ ∆ ∆
                    ^
                  cursor

        如上图，假设 a[left] 和 a[cursor] 一样的话，最多也会允许 a[left-1] 和 a[cursor] 对应的元素一样。但是 a[left-2] 就不能再和 a[curosr] 一样了。

        根据递推关系，
            1. 假设到left 这个位置都是满足条件的，则有 a[left-1] == a[left] 和 a[left-1] != a[left] 两种情况。

            2. 这样我们只需要保证 a[left-1] 和 a[cursor] 不一样就可以了，因为我们允许 a[left] == a[left-1]

                也就是有， 如果 a[left-1] == a[cursor], 那么与之对应的如下两种情况都是正确的：
                    1)  a[left-1] == a[left]        // 两个重复的
                    2)  a[left-1] != a[left]        // 都是惟一的

            3. 所以当 a[left-1] == a[cursor] 时，是满足条件的，但是left 不能再向右移动了。因为我们最多允许两个重复的。
                left 右移的条件是 a[left-1] == a[cursor]
 */
