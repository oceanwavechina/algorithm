/*
 * replace_space.cpp
 *
 *  Created on: Sep 12, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <string>

using namespace std;


/*
 问题：
 	 实现一个函数，把字符串中的每个空格替换成 "%20"。
 	 比如：输入 we are happy 输出 we%20are%20happy

 玩法是这样的：
 	 因为替换后，比替换前的长度增加了，所以要先计算出替换后的长度。
 	 然后从后到前依次移动元素，当遇到空格的时候就替换成 %20
 	 (如果替换后长度没有变长，那就没有这么复杂了)

 	 we are happy

 	 we%20are%20happy

 	 所以有两个指针，一个从新长度尾部开始，一个从老长度尾部开始
 */

void replace_space(string& str)
{
	int old_len = str.size();
	int space_cnt = 0;

	// 1. 先计算空格的个数
	for(auto ch : str) {
		if(ch == ' ') {
			++space_cnt;
		}
	}

	// 2. 重新分配空间
	str.resize(str.size() + 2*space_cnt);

	// 3. 从后往前移动
	int new_tail = str.size() - 1;
	int old_tail = old_len - 1;

	/*
	 we are happy
	            ^

 	 we%20are%20happy
                    ^
	 */

	while(old_tail >= 0) {
		if(str[old_tail] != ' ') {
			str[new_tail--] = str[old_tail--];
		} else {
			str[new_tail--] = '0';
			str[new_tail--] = '2';
			str[new_tail--] = '%';
			--old_tail;
		}
	}
}

int main(int argc, char **argv) {

	string str("we are happy");
	cout << "origin str: " << str << endl;

	replace_space(str);

	cout << "after replace: " << str << endl;

	return 0;
}
