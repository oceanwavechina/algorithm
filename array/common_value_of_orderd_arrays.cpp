/*
 * common_value_of_orderd_arrays.cpp
 *
 *  Created on: Aug 28, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*
	给出 N 个均为 严格递增排列 的整数数组比如： arr1，arr2 和 arr3。
		返回一个由 仅 在这些数组中 同时出现 的整数所构成的有序数组。

	示例：
		输入: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
		输出: [1,5]
		解释: 只有 1 和 5 同时在这三个数组中出现.


	玩法是这样的：
		每个数组一个游标，其中以第一个数组的游标为基准，
		其它数组中比基准元素小的往后移，直到大于等于基准，如果都跟基准相等，那就是公共元素，
		否则，大家一起往后移动，直到有一个结束


			1    2    3    4    5    6    10
				 ^

			1    2    5    7    9
				 ^

			1    3    4    5    8    10
			^
 */


using Array = vector<long>;

void display(const Array& arr, const string& msg)
{
	cout << msg << ":";

	for(auto item : arr) {
		cout << item << ", ";
	}

	cout << endl;
}

Array commonValues(vector<Array> arr_vec)
{
	Array ret;

	if(arr_vec.size() <= 1){
		return ret;
	}

	Array cursors(arr_vec.size(), 0);

	for(int i=0; i<arr_vec[0].size(); ++i) {

		int base = arr_vec[0][i];	// 第一个数组中的元素算基准

		int equal_counter = 0;	// 除第一个数组之外的数组中，有几个跟 base 相等


		// 依次遍历所有数组
		for(int idx = 1; idx < arr_vec.size(); ++idx) {

			// 当前数组的位置
			const Array& cur_arr = arr_vec[idx];
			long& cursor = cursors[idx];

			// cout << "idx: " << idx << ", cursor: " << cursor << endl;

			// 比 base 小的都跳过
			while(cur_arr[cursor] < base && cursor < cur_arr.size()) {
				++cursor;

				if(cursor == cur_arr.size()) {
					// 有一个数组遍历完了，提前结束
					cout << "we will return, at index: " << idx << ", cursor: " << cursor << endl;
					return ret;
				}
			}

			// 当前数组有一样的，算一个
			if(cur_arr[cursor] == base) {
				++equal_counter;
			}
		}

		// 要是都跟 base 一样，那就是公共元素了
		if(equal_counter == arr_vec.size() - 1) {
			ret.push_back(base);
		}

		equal_counter = 0;
	}

	return ret;
}


int main(int argc, char **argv) {

	vector<Array> arr_vec = {
			{1,2,3,4,5,6,10},
			{1,2,5,7,9},
			{1,3,4,5,8,10},
	};

	Array ret = commonValues(arr_vec);

	display(ret, "ret");

	return 0;
}
