/*
 * first_none_repeat_charactor.cpp
 *
 *  Created on: Jul 12, 2021
 *      Author: liuyanan
 */

#include <iostream>
#include <string>


using namespace std;


/*
  题目：
  	  在字符串中找出第一个只出现一次的字符。
  	  比如，输入 "abaccdeff", 则输出 'b'
 */


char first_none_repeat_charactor(const char* p_str)
{
	if(! p_str) {
		return '\0';
	}

	// 先初始化 hash 表
	const int table_size = 256;
	unsigned hash_table[table_size];
	for(unsigned i=0; i<table_size; ++i) {
		hash_table[i] = 0;
	}

	// 把字符串放到hash表中
	const char* p_cursor = p_str;
	//
	// 这里也算是一个考点吧， 为什么不能吧 const 放在 p_cursor 前边
	//	const 直接修饰谁，那谁就是不可变的，
	//		1. p_cursor 是指针，紧挨着放到它前边那p_cursor (即 char* const p_cursor) 指针本身就是不可修改的
	//		2. const 紧挨着放到 *p_cursor 前边 (即 const char *p_cursor)，那 *p_cursor, 也就是指针指向的数据是不可修改的
	//
	// char* const p_cursor = p_str;
	while(*p_cursor != '\0') {
		hash_table[*p_cursor] += 1;
		++p_cursor;
	}

	//
	// 找到第一个元素
	//		注意，我们是在遍历一次 源字符串， 而不是遍历 hash table
	//		因为题目的一个要点是要找  **第一次**  出现的元素
	//
	p_cursor = p_str;
	while(*p_cursor != '\0') {
		if(hash_table[*p_cursor] == 1) {
			return *p_cursor;
		}

		++p_cursor;
	}

	return '\0';
}


int main(int argc, char **argv)
{
	const char* p_str = "zbaccdeff";

	cout << "target charactor of [" << p_str << "], is: " << first_none_repeat_charactor(p_str) << endl;

	return 0;
}
