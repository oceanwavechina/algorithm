/*
 * ransom-note.cpp
 *
 *  Created on: Feb 23, 2025
 *      Author: liuyanan
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


/*
    给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
    如果可以，返回 true ；否则返回 false 。
    magazine 中的每个字符只能在 ransomNote 中使用一次。


    示例 1：
        输入：ransomNote = "a", magazine = "b"
        输出：false

    示例 2：
        输入：ransomNote = "aa", magazine = "ab"
        输出：false

    示例 3：
        输入：ransomNote = "aa", magazine = "aab"
        输出：true
 */

bool can_construct(string ransomNote, string magazine) {
    unordered_map<char, int> map;

    for(char ch : magazine) {
        map[ch] += 1;
    }

    for(char ch : ransomNote) {
        map[ch] -= 1;
    }

    for(auto& [k, v] : map) {
        if(v < 0) {
            return false;
        }
    }

    return true;
}


int main(int argc, char **argv) {

    string ransomNote("aa");
    string magazine("ab");

    cout << "can_construct:" << std::boolalpha << can_construct(ransomNote, magazine) << endl;
    return 0;
}
