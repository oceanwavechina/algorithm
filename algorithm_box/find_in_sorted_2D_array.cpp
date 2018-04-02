/*
 * find_in_sorted_2D_array.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: liuyanan
 */

#include <iostream>

using namespace std;

/*
 	 问题
 	 	 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 	 	 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

	思路
		如果从左上角(即[0][0]) 或是 右下角(即[n][n])的位置, 开始找，那就同时存在两条可遍历的分支了，所以没法实现
		如果从[0][n] 或是 [n][0] 的位置开始，则一个路径是递增的，另一个是递减的，就可以通过路径切换来查找了

 	 注
 	 	 这样的二维数组，就是一个 杨氏矩阵 (Young tableaus)

 	 	 https://articles.leetcode.com/searching-2d-sorted-matrix-part-ii/
 */

#define SIZE	4

bool exist_by_step_wise(int A[SIZE][SIZE], int value)
{
	// 这种方法的最坏时间复杂度是2n

	int row=0;
	int col=SIZE-1;
	bool ret = false;

	int check_count = 0;
	while(row <SIZE && col >=0) {
		if(A[row][col] == value) {
			ret = true;
			break;
		} else if (value < A[row][col]) {
			++check_count;
			--col;
		} else {
			++check_count;
			++row;
		}
	}

	cout << "checked: " << check_count << " elements" << endl;

	return ret;
}

int main(int argc, char **argv) {

	int A[SIZE][SIZE] = { {1,2,8,9},
				  	  	  {2,4,9,12},
						  {4,7,10,13},
						  {6,8,11,15}
						};

	cout << "array:" << endl;
	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<SIZE; ++j){
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	int value = 7;
	while(1){
		cout << "input target value(-1 for exit): ";
		cin >> value;
		if (value == -1)
			return 0;

		bool exist = exist_by_step_wise(A, value);

		if (exist)
			cout << "value: " << value << " exist" << endl;
		else
			cout << "value: " << value << " not exist" << endl;
	}
	return 0;
}
