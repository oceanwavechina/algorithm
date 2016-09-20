/*
 * string_reverse.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: liuyanan
 */


#include <vector>
#include <ctime>
#include <iostream>
#include <sstream>


/*
 * string  的 reverse 和 rotate 是两种不同的操作
 * reverse: abcdefgh  ->   hgfedcba
 * rotate:  abcdefgh  ->   defghabc
 */

template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}

void reverse(std::string& data, int begin, int end) {
	char tmp;

	while(begin < end) {
		tmp = data[end];
		data[end] = data[begin];
		data[begin] = tmp;

		++begin;
		--end;
	}
}

void rotate(std::string& data, int m) {
	int len = data.size();

	// 这里需要注意的是，我每次反转的都是闭区间的，所以要注意边界
	reverse(data, 0, m-1);
	reverse(data, m, len-1);
	reverse(data, 0, len-1);
}

int main() {
	std::string data = "abcdefgh";

	std::time_t start, end;
	start = std::time(nullptr);
	std::cout << "origin string: " << data  << std::endl;
	rotate(data, 1);
	std::cout << "reversed string: " << data << std::endl;
	std::cout << "with time: " << std::time(nullptr)-start << " seconds\n";
}
