/*
 * longest_common_prefix.cpp
 *
 *  Created on: Aug 8, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

/*
描述
	给你一个长度为 nn 的字符串数组 strsstrs , 编写一个函数来查找字符串数组中的最长公共前缀，返回这个公共前缀。

示例1
	输入：
		["abca","abc","abca","abc","abcc"]
	返回值：
		"abc"

玩法是这样的：
	我们先以第一个 str 作为结果（因为是最长公共前缀，如果第一个是最短的一个字符串，那就更好了）
	然后依次看看这个str 中的每一个字符是否在其他字符串的同样位置出现，只有没有出现，那就结束了

 */


string longest_common_prefix(const vector<string>& vec_str)
{
	if(vec_str.empty()) {
		return string("");
	}

	string ret;

	for(int i=0; i<vec_str[0].size(); ++i) {

		for(int j=1; j<vec_str.size(); ++j) {

			if(i>=vec_str[j].size() || vec_str[0][i] != vec_str[j][i]) {
				return ret;
			}
		}

		ret += vec_str[0][i]; 
	}

	return ret;
}

int main(int argc, char **argv) {

	vector<string> vec_str = {"abca","abc","abca","abc","abcc"};

	cout << "longest common prefix:" << longest_common_prefix(vec_str) << endl;


	return 0;
}
