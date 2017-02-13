/*
 * 02_valid_palindrome.cpp
 *
 *  Created on: Feb 13, 2017
 *      Author: liuyanan
 */


/*
	 Question: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
			 For example, "A man, a plan, a canal: Panama" is a palindrome.
			 "race a car" is not a palindrome.

	 Example Questions Candidate Might Ask:

	 Q: What about an empty string? Is it a valid palindrome?
	 A: For the purpose of this problem, we define empty string as valid palindrome.
 */


#include <iostream>


using namespace std;


bool isPalindrome(string str) {

	int start = 0;
	int end =  str.size();

	while(start <= end) {

		// 跳过所有不检查的字符
		while ( ! isalpha(str[start]) )
			++start;

		while( ! isalpha(str[end]) )
			--end;

		if(tolower(str[start]) == tolower(str[end])) {
			++start;
			--end;
		} else {
			// 只要有一个不一样就结束了
			break;
		}
	}

	if (start >= end)
		return true;
	else
		return false;
}


int main(int argc, char **argv) {

	string input = "A man, a plan, a canal: Panama";
	cout << boolalpha << '<' << input << "> is Palindrome: " << isPalindrome(input) << endl;

	input = "race a car";
	cout << boolalpha << '<' << input << "> is Palindrome: " << isPalindrome(input) << endl;

	return 0;
}

