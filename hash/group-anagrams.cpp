/*
 * group-anagrams.cpp
 *
 *  Created on: Feb 23, 2025
 *      Author: liuyanan
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
    给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

    字母异位词 是由重新排列源单词的所有字母得到的一个新单词。


    示例 1:
        输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
        输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

    示例 2:
        输入: strs = [""]
        输出: [[""]]

    示例 3:
        输入: strs = ["a"]
        输出: [["a"]]
 */


vector<vector<string>> group_anagrams(const vector<string>& strs) {

    vector<vector<string>> ret;
    unordered_map<string, vector<string>> map;

    for(const string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        map[key].push_back(str);
    }


    for(auto& [k, v] : map) {
        ret.push_back({v.begin(), v.end()});
    }

    return ret;
}


int main(int argc, char **argv) {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ret = group_anagrams(strs);

    for(auto& list : ret) {
        ostringstream oss;
        for(auto& item : list) {
            oss << item << ",";
        }
        cout << oss.str() << endl;
    }

    return 0;
}
