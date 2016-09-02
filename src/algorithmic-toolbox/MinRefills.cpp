/*
 * MinRefills.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: liuyanan
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

long MinRefills(std::vector<long> x, int n, int L) {
	int numRefills=0, currentRefill=0;
	while(currentRefill <= n) {
		int lastRefill = currentRefill;
		// 这里的L是可行驶的最大路程，如果放到 Celebration Party Problem 中就是每个 child 相差的最大值了，
		// 当然，前提是需要对children排序
		while(currentRefill <= n && x[currentRefill + 1] - x[lastRefill] <= L)
			++currentRefill;

		// 当最近的站都不能满足时，说明目标不可达
		if (currentRefill == lastRefill)
			return -1;
		else
			std::cout << x[lastRefill] << "  --  ";

		if (currentRefill <= n)
			++numRefills;
	}

	return numRefills;
}


int main() {
	std::vector<long> stations = {0, 200, 375, 550, 750, 950};
	int n = 4;
	int L = 400;

	std::time_t start, end;
	start = std::time(nullptr);
	std::cout << "MinRefills for: " << display(stations)  << std::endl
			<< "is:" << MinRefills(stations, 4, 400) << std::endl
			<< "with time:" << std::time(nullptr)-start << " seconds\n";
}


