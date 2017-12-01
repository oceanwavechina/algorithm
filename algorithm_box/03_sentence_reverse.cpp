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
	reverse(sentence, 0, sentence.size()-1);

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

	cout << "after reverse sentence_reverse_in_place: " << sentence_reverse_in_place(sentence) << endl;

	return 0;
}
