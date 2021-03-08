/*
 * valid_parentheses.cpp
 *
 *  Created on: Mar 8, 2021
 *      Author: liuyanan
 */


#include <string>
#include <iostream>
#include <stack>
#include <set>
#include <map>

using namespace std;


/*
  问题：
  	  给定一段代码，判断里边的括号(大括号，小括号，中括号)时候匹配，语法正确

  	  比如 if(factors[i] > 0)) 是错误的， 而 if(factors[i] > 0) 是正确的
 */



bool is_valid_parentheses(const string& content)
{
	static const std::map<char, char> LR_PAIRS = { {'(', ')'}, {'{', '}'}, {'[', ']'} };
	static const std::map<char, char> RL_PAIRS = { {')', '('}, {'}', '{'}, {']', '['} };

	stack<char> symbol_stack;

	for(auto c : content) {
		if(LR_PAIRS.find(c) != LR_PAIRS.end()) {

			// 发现括号左括号
			symbol_stack.push(c);

		} else if(RL_PAIRS.find(c) != RL_PAIRS.end()) {

			// 发现右括号
			if(symbol_stack.empty() || symbol_stack.top() != RL_PAIRS.find(c)->second) {
				return false;
			} else {
				symbol_stack.pop();
			}

		} else {
			// 其余字符，跳过
		}
	}

	return symbol_stack.empty();
}


int main(int argc, char **argv)
{

	string valid_string = "for(size_t i=0; i<factors.size(); ++i) {"
	    "total_factor += factors[i];"
	    "if(factors[i] > 0) {"
	        "oss << factors[i] << \",\";"
	    "}"
	"}";

	string invalid_string = "for(size_t i=0; i<factors.size(); ++i) {"
		"total_factor += factors[i];"
		"if(factors[[i] > 0) {"
			"oss << factors[i] << \",\";"
		"}"
	"}";

	 assert(is_valid_parentheses(valid_string) == true);
	 assert(is_valid_parentheses(invalid_string) == false);

	cout << "test ok" << endl;
	return 0;
}
