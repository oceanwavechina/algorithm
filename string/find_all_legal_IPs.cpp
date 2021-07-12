/*
 * find_all_legal_IPs.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: liuyanan
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


/*
  	  给定一个数字组成的字符串，找出所有可以组成的有效的IP
  	  比如：17210412 可以找到 172.10.4.12, 172.10.41.2, 172.104.1.2 .......

  	  思路：
  	  	  这个类似于从数组中找到和为S的三个数的问题。
  	  	  因为每个ip有四个字断，也就是3个点。
  	  	  两个指针，指向前后两个点，中间一个指针，是中间的点。
  	  	  先在给定的前后两个点的情况下，遍历中间的点，找到所有符合条件的ip，
  	  	  然后分别移动前后两个指针，在遍历中间的点，在O(n^2)的复杂度下解决

			  start	  middle    end
			    V		 V		 V
			172  .  10   .    4  .   12
			 ^		^		  ^		 ^
		   part1   part2    part3  part4
 */


typedef vector<string> StrVec;


bool is_legal_field(const string& str){

	// 位数是否有效
	if (str.empty() || str.size() >3 || str[0] == '0') {
		return false;
	}

	// 数值是否有效
	int value = -1;
	stringstream ss;
	ss << str;
	ss >> value;
	if (value < 0 || value > 255) {
		return false;
	}

	return true;
}

string substr(const string& str, size_t start, size_t end)
{
	// [...) 左闭右开区间
	if (start > end) {
		cout << "error substr pos, start:" << start << ", end:" << end << endl;
	}

	return str.substr(start, end-start);
}

StrVec find_all_legal_ips(const string& str)
{
	StrVec ret;

	if (str.size() < 4) {
		return ret;
	}

	int start = 1;
	int end = str.size();
	string ip;

	string part1 = substr(str, 0, start);
	string part4 = substr(str, end-1, (size_t)str.size());

	while(is_legal_field(part1) && is_legal_field(part4) ) {

		int middle = start;

		while(middle < end) {
			string part2 = substr(str, start, middle);
			string part3 = substr(str, middle, end-1);
			if (is_legal_field(part2) && is_legal_field(part3)) {

				ip = part1 + "." + part2 + "." + part3 + "." + part4;
				ret.push_back(ip);
			}

			++middle;
		}

		if (start < 3) {
			++start;
		} else if (str.size() - end < 3) {
			--end;
		} else {
			break;
		}

		part1 = substr(str, 0, start);
		part4 = substr(str, end-1, (size_t)str.size());
	}

	return ret;
}

int main(int argc, char **argv) {

	string str = "17210412";
	StrVec ips = find_all_legal_ips(str);

	for(auto ip : ips) {
		cout << ip << endl;
	}

	return 0;
}
