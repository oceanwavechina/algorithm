/*
 * find_the_first_missing_number.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


/*
	首先看看题目要求：
		给定一个无序的整数数组，怎么找到第一个大于0，并且不在此数组的整数。

		比如: [1,2,0], 返回3
			[3,4,-1,1], 返回2
			[1, 5, 3, 4, 2], 返回6
			[100, 3, 2, 1, 6,8, 5], 返回4。


		要求使用O(1)空间和O(n)时间。
 */


long find_the_first_missing_number(vector<long>& data)
{
	for(int i=0; i<data.size(); ++i) {

		// 注意这里的判断是 data[i] != i-1 而不是 data[i] != i
		// 因为题目要求的是找 大于0 的整数
		if(data[i] >= 0 && data[i] < data.size() && data[i] != i-1) {
			long target_pos = data[i] - 1;
			if(target_pos >= 0 && target_pos < data.size()) {
				swap(data[i], data[target_pos]);
			}
		}
	}

	int idx = 0;

	do {
		if(idx + 1 == data.size()) {
			break;
		}
		if(data[idx] != data[idx+1] - 1) {
			break;
		}

		++idx;
	} while(idx < data.size());

	return data[idx] + 1;
}


string format(const vector<long>& data)
{
	ostringstream oss;
	for(auto n : data) {
		oss << n << ", ";
	}

	return oss.str();
}

int main(int argc, char **argv) {

	vector<vector<long>> vecs = {
			{1,2,0},
			{3,4,-1,1},
			{1, 5, 3, 4, 2},
			{100, 3, 2, 1, 6, 8, 5},
	};

	for(int i=0; i< vecs.size(); ++i) {

		long ret = find_the_first_missing_number(vecs[i]);

		cout << "the first missing number of [" << format(vecs[i]) << "] is: " << ret << endl;
	}


	return 0;
}










/*

    玩法是这样的：
        1. 在给定数组大小的范围内，把每个数放到它应该在的位置。
            如果不在这个范围内，则不动
        2. 都遍历一遍，放完后，在从头找。

    网上都是这种算法，但是这样是有问题的，比如 {102, 99, 77, 66} 这个例子
    找出来的结果是不对的，因为数组元素每个都大于数组的下标范围。

    所以这个算法应该还有个限制：
        ** 在此数组下标范围内的** 第一个缺失的数字
    否则这个算法就是错的。
 */
