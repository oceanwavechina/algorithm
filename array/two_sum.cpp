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
#include <list>

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


tuple<int, int> tow_number_hash(vector<int> numbers, int target) {

	// O(n) runtime, O(n) space – Hash table

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

vector< pair<int , int> > all_pairs_of_specific_sum(const vector<int>& numbers, int target)
{
	vector< pair<int , int> > ret;

	unordered_map<int/*num*/, list<int>/*positions*/ > unmatched;

	for(int i=0; i< numbers.size(); ++i) {
		auto another_it = unmatched.find(target - numbers[i]);

		if(another_it != unmatched.end()) {
			list<int>& positions = another_it->second;
			if(positions.empty()) {
				positions.push_back(i);
			} else {
				ret.push_back(make_pair(i, positions.front()));
				positions.pop_front();
			}
		} else {
			unmatched[numbers[i]].push_back(i);
		}
	}

	return ret;
}

tuple<int, int> tow_number_tow_pointor(vector<int> numbers, int target) {

	// 两指针的方法需要排序，也就改变了原来的位置，所以用这个方法实现不了
	// 可以定义一个新的结构体，把位置信息带上，不过既然有hash的方法了，干嘛还这么麻烦

	return make_tuple(-1, -1);
}


int main(int argc, char **argv) {
	vector<int> numbers = {1, 5, 3, 4, 9, 6, 7};
	int target = 11;

	cout << "input numbers: " << display(numbers) << endl;
	cout << "target sum: " << target << endl;

	tuple<int, int> solution = tow_number_hash(numbers, target);

	cout << "solution: " << get<0>(solution) << ", " << get<1>(solution) << endl;

	vector< pair<int , int> > all_paires = all_pairs_of_specific_sum(numbers, target);
	cout << "all_pairs: ";
	for(auto apair : all_paires) {
		cout << apair.first << "_" << apair.second << ", ";
	}
	cout << endl;

	return 0;
}
