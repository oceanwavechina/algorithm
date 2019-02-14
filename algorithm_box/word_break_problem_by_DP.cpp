/*
 * @Author: liuyanan 
 * @Date: 2019-02-14 11:00:57 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-14 16:01:10
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
    Question：
        给定一个字典和一个字符串， 检查改字符串能不能被分割成一组单词
    Example:
        1.  给定字典如下:
                { i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango}
        
            对于给定的字符串 ilikesamsung
                可以被分割为： i like sam sung 或是 i like samsung
        
        2.  给定字典：
                {aaa, aaaa}
            对于给定的字符串 aaaaaaa
                可以被分割成 aaa aaaa 或 aaaa aaa
        
        2.  给定字典：
                {ab,cde,ee,cd,fg}
            对于给定的字符串 abcdeefg
                可以被分割成 ab cd ee fg

    思路:
        1. 如果 从第 0到i的字符可以被分割，那这些字符都应该在字典中
        2. 但是0到i个字符不一定都是以0开始的子串存在的，可能是1或2开始的
        3. 所以我们要从0到i，每个字符作为子串其实来判断是不是在字典中
        4. 同理，如果0到n-1可分割，那就要以0到n-1的字符为首字符都检查一次
*/

bool contain_in_dict(const string& substr, const unordered_set<string>& dict)
{
    /*
        判断一个子串在不在字典中
    */

    // cout << substr << " -> ";
    for(string word : dict) {
        if(substr == word) {
            // cout << substr << endl;
            return true;
        }
    }
    // cout << endl;
    return false;
}

bool word_break(const string& str, const unordered_set<string>& dict)
{
    /*
    对于给定的字符串 abcdeefg
       可以被分割成 ab cd ee fg
    */

   size_t size = str.size();

    vector<bool> wb(size+1, false);

    for(int i=0; i<size; ++i) {
        for(int j=0; j<=i; ++j) {
            // 注意这里substr的用法，第二个参数是个数，不是位置
            if(contain_in_dict(str.substr(j,i-j+1), dict)) {
                wb[i+1] = true;
            }
        }
    }

    cout << "string: _\t";
    for(char c : str) {
        cout << c << "\t";
    }
    cout  << endl;

    cout << "mark  : ";
    for(auto b : wb) {
        cout << b << "\t";
    }
    cout  << endl;

    return wb[size];
}


int main(int argc, char const *argv[])
{
    unordered_set<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    string str = "ilikesamsung";
    bool can_split = word_break(str, dict);
    cout << "string \"" << str << "\" can be split:" << can_split << endl;
    
    dict = {"ab","cde","ee","cd","fg"};
    str = "abcdeefg";
    can_split = word_break(str, dict);
    cout << "string \"" << str << "\" can be split:" << can_split << endl;
    
    return 0;
}
