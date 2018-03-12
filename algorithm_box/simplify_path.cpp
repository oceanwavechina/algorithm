/*
 * simplify_path.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: liuyanan
 */


/*
	Given an absolute path for a ﬁle (Unix-style), simplify it.
	For example,
		path = "/home/", => "/home"
		path = "/a/./b/../../c/", => "/c"

	Corner Cases:
		1. Did you consider the case where path = "/../"? In this case, you should return "/".
		2. Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
			In this case, you should ignore redundant slashes and return "/home/foo".
 */


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



string simplify_path(const string& path) {

	string ret;

	vector<string> str_vec;

	/* 先分割成子路径
	 * 1. 一个变量存储子路径，一个指针遍历整个路径
	 * 2. 当指针指向的字符是 ‘/’ 时，就要判断当前子路径是否需要压栈了
	 * 3. 在最后，重新组织的时候，要判断栈为空的情况
	 */
	string cur_str;
	for(int i=0; i<path.size(); ++i) {

		if (path[i] != '/') {
			// 找到当前完整子路径
			cur_str += path[i];
		} else {
			// 根据当前子路径，判断压栈还是出栈，还是不做处理
			if (cur_str == ".") {
				cur_str = "";
				continue;
			} else if (cur_str == "..") {
				if (!str_vec.empty()) {
					str_vec.pop_back();
				}
				cur_str = "";
			} else if (!cur_str.empty()) {
				str_vec.push_back(cur_str);
				cur_str = "";
			}
		}
	}

	for(int i=0; i<str_vec.size(); ++i) {
		ret += '/' + str_vec[i];
	}

	if (ret.empty())
		ret = '/';

	return ret;
}


int main(int argc, char **argv) {

	string test_path[] = {
			"/home/",
			"/a/./b/../../c/",
			"/../",
			"/home//foo/"
	};

	for (auto a_path : test_path){
		cout << a_path << "  ==>  " << simplify_path(a_path) << endl;
	}

	return 0;
}
