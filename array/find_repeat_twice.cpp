/*
 * find_repeat_twice.cpp
 *
 *  Created on: Aug 15, 2021
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>

using namespace std;



/*
	给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
	找到所有出现两次的元素。

	你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

	示例：
		输入: [4,3,2,7,8,2,3,1]

		输出: [2,3]

	玩法是这样的：
		需要对数组进行修改。因为有 1 ≤ a[i] ≤ n， 所以当没有重复元素时，下标 i 和 a[i] 是一对一 的关系。
		当有重复的情况下，就会出现，两个下标 i 和 j 同时对应一个元素 a[i], 也就是一个元素对应两个下标。

		所以我们利用标记的办法，修改这个数组，由条件可知 a[i] - 1 一定是在数组有效下标范围之内的。

		反过来，如果我们以这个 元素本身 作为为下标，那遍历数组时，会出现访问两次相同的下标的情况，

		于是，我们第一次以元素为下标标记对应的数组中的值(取反)，当第二次以该元素为下标访问数组时，会发现数组中的值为负数了。

		这样就找到重复的元素了。
 */


vector<int> find_repeat_twice(vector<int>& data)
{
	vector<int> ret;

	for(auto item : data) {

		int virtual_idx = abs(item);

		if(data[virtual_idx] < 0) {
			ret.push_back(virtual_idx);
		} else {
			data[virtual_idx] *= -1;
		}
	}


	return ret;
}


void display(const vector<int>& data)
{
	cout << "ret: ";

	for(auto item : data) {
		cout << item << " ";
	}

	cout << endl;
}

int main(int argc, char **argv) {

	vector<int> data = {4,3,2,7,8,2,3,1};

	display(find_repeat_twice(data));

	return 0;
}
