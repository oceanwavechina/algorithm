/*
 * 01_two_sum.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: liuyanan
 */


#include <iostream>
#include <tuple>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

/*
 * Question:
	Given an array of integers, find two numbers such that they add up to a specific target number.

	The function twoSum should return indices of the two numbers such that they add up to the target,
	where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.
 */


template <typename T>
std::string display(T val) {
	std::stringstream ss;
	for (auto v : val) {
		ss << v << ' ';
	}

	return ss.str();
}


tuple<int, int> tow_number(vector<int> numbers, int target) {

	unordered_map<int, int> visited;

	for(int i=0; i<numbers.size(); ++i) {
		auto another = visited.find(target-numbers[i]);
		if(another != visited.end()){
			return make_tuple(another->second, i);
		} else {
			visited[numbers[i]] = i;
		}
	}

	return make_tuple(-1, -1);
}


int main(int argc, char **argv) {
	vector<int> numbers = {1, 5, 3, 4, 9, 6, 7};
	int target = 11;

	cout << "input numbers: " << display(numbers) << endl;
	cout << "target sum: " << target << endl;

	tuple<int, int> solution = tow_number(numbers, target);

	cout << "solution: " << get<0>(solution) << ", " << get<1>(solution) << endl;

	return 0;
}
