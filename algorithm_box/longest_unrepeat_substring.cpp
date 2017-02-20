/*
 * longest_unrepeat_substring.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: liuyanan
 */




/*
 * 给定一个字符串，找出这个字符串中最长的不重复子串。
 * 		比如对于字符串“sadus”，那么返回的结果应该是“sadu”或者“adus”（返回一个即可）；
 * 		对于字符串“acbba”，返回的应是“acb”。
 *
 * 延伸：
 * 		如果有多条长度相等的子串，将其都打印出来
 *
 * NOTE:
 * 		这里的字典，有{char:pos} 和 {pos:char} 两种方式存储, 我觉得用后者要方便些
 */

#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#define OUTPUT_ALL

using namespace std;


string _format_map_iterator(map<int, char>::const_iterator it) {

	stringstream ss;
	ss << "\t{ " << it->first << ", " << it->second << " }" << endl;
	return ss.str();
}

void output_map(const map<int, char>& dict) {
	cout << "dict output:" << endl;
	for(auto it=dict.begin(); it!= dict.end(); it++) {
		cout << _format_map_iterator(it);
	}
}


void del(map<int, char>& dict, int max_index) {

	for(auto it=dict.begin(); it!= dict.end(); ) {
		if (it->first <= max_index) {
			dict.erase(it++);
		} else {
			it++;
		}
	}
}

int find(const map<int, char>& dict, char target) {
	for(auto it=dict.begin(); it!= dict.end(); ++it) {
		if (it->second == target) {
			return it->first;
		}
	}

	return -1;
}

string longest_substr(const string& s) {

	/*
	 * 基本思路就是滑动窗口，从左向右便利一遍。 当窗口宽度达到最大时，记录当时的位置和大小，然后继续向右移动
	 */

	map<int, char> dict;
	int max_size = 0;

#ifndef OUTPUT_ALL
	int start = 0;
#else
	vector<int> ret;
#endif

	for(int i=0; i<s.size(); ++i) {

		int target = find(dict, s[i]);
		if (target != -1) {
			del(dict, target);
		}

		dict[i] = s[i];
		output_map(dict);

		cout << "dict first: " << dict.begin()->second << ", dict size: " << dict.size() << endl << endl << endl;

		if (dict.size() > max_size) {
			max_size = dict.size();
#ifndef OUTPUT_ALL
			start = dict.begin()->first;
#else
			ret.clear();
			ret.push_back(dict.begin()->first);
		} else if (dict.size() == max_size) {
			ret.push_back(dict.begin()->first);
#endif

		}
	}

#ifndef OUTPUT_ALL
	cout << "start pos:" << start << ", substr size:" << max_size << endl;
	return s.substr(start, max_size);
#else
	stringstream ss;
	ss << "all results:" << endl;
	for(auto it=ret.begin(); it!= ret.end(); ++it) {
		cout << "start:" << *it << endl;
		ss << "\t" << s.substr(*it, max_size) << endl;
	}

	return ss.str();
#endif
}


int main(int argc, char **argv) {

	// 对于字符串“abcabcbb”，返回的应是“abc”。
	string s = "abcabcbb";
	cout << "original string:" << s << endl;

	cout << "longest substr:" << longest_substr(s) << endl;


	return 0;
}
