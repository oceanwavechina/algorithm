/*
 * generate-parentheses.cpp
 *
 *  Created on: Feb 22, 2025
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <sstream>

using namespace std;

/*
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

    示例 1：
        输入：n = 3
        输出：["((()))","(()())","(())()","()(())","()()()"]

    示例 2：
        输入：n = 1
        输出：["()"]

    提示：
        1 <= n <= 8
 */



string display(vector<string> data)
{
    ostringstream oss;

    for(auto i: data) {
        oss << i << ", ";
    }

    return oss.str();
}

bool is_pair(char stack_top, char ch) {
    if(stack_top=='(' && ch==')') {
        return true;
    }

    return false;
}

bool is_valid_parentheses(const std::string& str) {

    stack<char> a_stack;

    for(char ch : str) {

        if(!a_stack.empty() && is_pair(a_stack.top(), ch)) {
            a_stack.pop();
            continue;
        }

        a_stack.push(ch);
    }

    return a_stack.empty();
}

void generate_parentheses_mask(int n) {

    int total = n*2;

    for(size_t mask=0; mask<pow(2, total); ++mask) {

        string str;
        int ones = 0;

        for(size_t i=0; i<total; ++i) {
            if(mask & 1<<i) {
                ones += 1;
                str+='(';
            } else {
                str+=')';
            }

            if(ones == 3 && str.size() == 6) {
                break;
            }
        }

        if(is_valid_parentheses(str)) {
            cout << str << endl;
        }
    }
}

void generate_parentheses_backtracking(int n, string& str) {

    if(str.size() > 6) {
        return;
    }

    if(str.size() == 6 && is_valid_parentheses(str)) {
        cout << str << endl;
        return;
    }

    str.push_back('(');
    cout << str << endl;
    generate_parentheses_backtracking(n, str);
    str.pop_back();
    cout << str << endl;

    str.push_back(')');
    cout << str << endl;
    generate_parentheses_backtracking(n, str);
    str.pop_back();
    cout << str << endl;
}


int main(int argc, char **argv) {

#if 0
    generate_parentheses_mask(3);
#else
    string str;
    generate_parentheses_backtracking(3, str);
#endif

    return 0;
}
