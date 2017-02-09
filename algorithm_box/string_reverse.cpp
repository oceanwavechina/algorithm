/*
 * Reverse_String.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: liuyanan
 */



#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * Write a function that takes a string as input and returns the string reversed.
     * Example:
     * Given s = "hello", return "olleh".
     */
	string reverseString(string s) {
    	int right = s.length()-1;
    	int left = 0;
    	char t;

    	while (left < right) {
    		t = s[left];
    		s[left] = s[right];
    		s[right] = t;

    		++left;
    		--right;
    	}

    	return s;
    }



};


int main() {
	Solution s = Solution();
	std::cout << s.reverseString("hello");
}
