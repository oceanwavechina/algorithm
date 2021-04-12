/*
 * PointsCoverSorted.cpp
 *
 *  Created on: Sep 2, 2016
 *      Author: liuyanan
 *
 */


/*
 * Greedy Algorithm
 *
 * Description: 1. 这个问题是，对于有序的数据，在给定单位长度的情况下，我们根据这个长度将数据分组，使得分组最少，
 *  				我们的结果不是确定的分组而是，找到相对应的区间
 *  			 2. 实际的问题，数据一般都不会排序，所以排序是第一步
 *
 */

#include <vector>
#include <ctime>
#include <iostream>
#include <sstream>

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}

std::string display_group(std::vector<std::pair<float, float>> groups) {
	std::stringstream ss;
	ss << std::endl;
	for (auto group : groups) {
		ss << '{' << group.first << ',' << group.second << '}' << '-';
	}
	ss << std::endl;

	return ss.str();
}


std::vector<std::pair<float, float>> PointsCoverSorted(std::vector<float> x) {
	std::vector<std::pair<float, float>> R;
	int i=1;
	int n = x.size();
	float l, r; // 注意这里的的左值和右值不是下标，而是数具区间

	std::vector<float> sub_section;
	while(i < n) {
		sub_section.clear();

		l = x[i];
		r = x[i] + 1; // 这里的 1 指的是区间的长度，和坐标无关， 不能写成 r = x[i+1]

		R.push_back({l, r});

		++i; // 移动到下一个区间

		while ( i<=n && x[i]<= r) {
			++i;
		}
	}

	return R;
}


int main() {
	// 这里的类型
	std::vector<float> r = {5, 5.2, 5.8, 6, 7};

	std::time_t start, end;
	start = std::time(nullptr);
	std::cout << "PointsCoverSorted for: " << display(r)  << std::endl
			<< "is:" << display_group(PointsCoverSorted(r)) << std::endl
			<< "with time:" << std::time(nullptr)-start << " seconds\n";
}
