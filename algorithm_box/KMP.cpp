/*
 * @Author: liuyanan 
 * @Date: 2020-05-04 17:49:02 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2020-05-04 20:15:01
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    详解见 KMP.md
*/

int kmp(const string& str, const string& pattern, const vector<int>& next) 
{
    int i=0, j=0;
    
    while (i < str.length() && j < pattern.length()) {

        if(j == -1 || str[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    
    if(j == pattern.length()) {
        return i-j;
    } else {
        return -1;
    }
}

void get_next(const string& pattern, vector<int>& next)
{
    next.resize(pattern.length() + 1);

    next[0] = -1;
    int i = 0, j = -1;
    
    while (i < pattern.length()) {

        if(j == -1 || pattern[i] ==  pattern[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    
}

int main(int argc, char const *argv[])
{
    const string str = "abbaabbaaba";
    const string pattern = "abbaaba";
    
    cout << "string : " << str << "\n";
    cout << "pattern: " << pattern << "\n";

    vector<int> next;

    get_next(pattern, next);

    int pos = kmp(str, pattern, next);
    
    cout << "pos:" << pos << endl;

    return 0;
}
