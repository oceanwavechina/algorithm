/*
 * sentence_reverse.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: liuyanan
 */


/*
 * 哎，这些代码都是调试出来的。。。。
 */

/*
	Question: Given an input string s, reverse the string word by word.

	For example, given s = "the sky is blue", return "blue is sky the".
 */


#include <iostream>
#include <unordered_map>
#include <sstream>
#include <cstring>
#include <stack>

using namespace std;


string sentence_reverse_with_dict(string& sentence) {

	/*
	 * 利用一个字典存储每个单词的顺序和起始位置
	 */
	unordered_map<int, int> word_position; // <order_number, position>

	int order = 0;
	int i = 0;
	while(sentence[i] != '\0') {

		if (sentence[i] != ' ' and (i == 0 or sentence[i-1] == ' ')) {
			word_position[order++] = i;
		}

		++i;
	}

	stringstream ss;
	for (i = word_position.size()-1; i>=0; --i) {
		int j = word_position[i];
		while(sentence[j] != ' ' and sentence[j] != '\0') {
			ss << sentence[j++];
		}
		ss << ' ';
	}

	return ss.str();
}

string sentence_reverse_with_stack(string& sentence) {
	/*
	 * 因为有 反转 二字，所以自然而然想到栈实现
	 */

	stack<int> word_positions_stack;	//记录每个单词的起始位置

	for(int i = 0; i < sentence.size()-1; ++i) {
		if (i == 0) {
			word_positions_stack.push(i);
		} else if (i-1 > 0 && sentence[i-1] == ' ' ) {
			word_positions_stack.push(i);
			//std::cout << sentence[i] << std::endl;
		}
	}

	stringstream ss;

	while(!word_positions_stack.empty()) {
		int pos = word_positions_stack.top();
		word_positions_stack.pop();

		int i = pos;
		while(sentence[i] != ' ' && sentence[i] != '\0') {
			ss << sentence[i];
			++i;
		}


		if (word_positions_stack.size() > 0) {
			ss << ' ';
		}
	}

	return ss.str();
}

/* ******************************  in place reverse  ****************************** */

void reverse(string& str, int start, int end) {

	char tmp;

	while(start < end) {
		tmp = str[start];
		str[start]= str[end];
		str[end]= tmp;

		++start;
		--end;
	}

}


string sentence_reverse_in_place(string& sentence) {
	// 两次反转法，见 <<编程珠玑>>
	reverse(sentence, 0, (int)sentence.size()-1);

	int start = 0;
	int end = 0;
	int i = 0;
	while(sentence[i] != '\0') {

		while(sentence[i] == ' ') {
			++i;
		}
		start = i;

		while(sentence[i] != ' ' and sentence[i] != '\0') {
			i++;
		}
		end = i-1;

		reverse(sentence, start, end);
	}

	return sentence;
}


int main(int argc, char **argv) {

	string sentence = "the sky is blue";
	cout << "input string: <" << sentence << '>' << endl;
	cout << "after reverse sentence_reverse_with_dict: " << sentence_reverse_with_dict(sentence) << endl;

	sentence = "the sky is blue";
	cout << "after reverse sentence_reverse_in_place: " << sentence_reverse_in_place(sentence) << endl;

	sentence = "the sky is blue";
	cout << "after reverse sentence_reverse_with_stack: " << sentence_reverse_with_stack(sentence) << endl;

	return 0;
}
