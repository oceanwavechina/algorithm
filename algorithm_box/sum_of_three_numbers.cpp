/*
 * sum_of_three_numbers.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>
#include <tuple>


typedef std::vector<std::tuple<int, int, int>> Result;


Result get_result(std::vector<int> data) {

	Result result;

	std::sort(data.begin(), data.end());


	for(int k=0; k<data.size(); ++k) {

		// 算是基准值，从小到大遍历，而且只遍历负数
		if (data[k]>0)
			break;

		int left = k;
		int right = data.size()-1;

		while(left < right) {
			int sum = data[k] + data[left] + data[right];

			if (sum < 0) {
				// 这是负数的权重太大了，left需要往右移动
				++left;
			} else if (sum > 0) {
				// 这是正数的权重太大了，right需要往左移动
				--right;
			} else {
				// 这是一组结果
				result.emplace_back(std::make_tuple(data[k], data[left], data[right]));
				// 向中间移动
				++left;
				--right;
			}
		}
	}

	return result;
}

void display_result(Result result) {
	for(auto group : result) {
		std::cout << "(" << std::get<0>(group) << "," << std::get<1>(group) << "," << std::get<2>(group) << ")\n";
	}
}

int main() {

	std::vector<int> data = {-2, 1, -1, 2, 1};

	Result result = get_result(data);

	display_result(result);

	return 0;
}
