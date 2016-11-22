/*
 * selection_sort.cpp
 *
 *  Created on: Sep 8, 2016
 *      Author: liuyanan
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <cstdint>

/*
 * 练习 递归 与 迭代 的相互转换
 */

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


/*
 * 递归与循环是等价的：
 * 		1. 找到循环的条件即可
 */
void recusive_selection_sort(std::vector<int>& data, int position) {

	if (position == data.size()) {
		return;
	}

	int tmp;
	for(int i=position; i<data.size(); ++i) {
		if (data[i] < data[position]) {
			tmp = data[position];
			data[position] = data[i];
			data[i] = tmp;
		}
	}
	std::cout  << "position=" << position << std::endl;

	recusive_selection_sort(data, ++position);
}


void iteration_selection_sort(std::vector<int>& data, int position) {
	int tmp;

	for(int i=0; i< data.size(); ++i) {
		for(int j=i; j<data.size(); ++j) {
			if (data[j] < data[i]) {
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
		std::cout  << "position=" << i << std::endl;
	}
}



int main() {

	std::vector<int> data = {8, 4, 2, 5, 2};

	std::cout << "original data: " << display(data) << std::endl;

//	recusive_selection_sort(data, 0);
	iteration_selection_sort(data, 0);

	std::cout << "sorted data: " << display(data) << std::endl;

	return 0;
}
