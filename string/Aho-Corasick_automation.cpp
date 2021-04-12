/*
 * @Author: liuyanan 
 * @Date: 2020-05-05 16:41:33 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2020-05-05 18:22:56
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

/*
    doc: https://www.cnblogs.com/nullzx/p/7499397.html

    Note:
        1. fail 节点本身所在的string的后缀 与 fail节点指向的string的前缀有最长的公共节点
             这和KMP中的思想是一致的

    // TODO: 支持中文，可能要children修改成可变的
 */

using namespace std;

// 只能处理英文的自动机
#define ASCII 128

typedef unordered_map<string, vector<int>> TACRet;

class Node {
public:
    Node () : children(ASCII, nullptr) { }
    
    // 如果该节点是终点，即，
    // 从根节点到此节点表示了一个完成的模式串，则str != null, 且str就表示该模式串
    string str;

    // 所有可能出现的子节点，最大可能有128个，因为只有英文字符， 即所有子节点
    vector<Node*> children;

    // 当前node的 孩子节点不能匹配文本串时，下一个应该查找的节点
    Node* fail;

    bool is_word() {
        // 只有当前Node为终点时，其str才会有值
        return !str.empty();
    }
};

class AhoCorasicAutomation {
public:
    AhoCorasicAutomation(vector<string> dict) {
        _p_root = new Node();
        _dictionary = dict;
        build_trie_tree();
        build_AC_from_trie();
    }

    //  仅仅创建trie tree
    void build_trie_tree() {
        for(auto word : _dictionary) {
            Node* p_cur = _p_root;

            // 这个for循环生成每个wor的分支
            for(int i=0; i<word.length(); ++i) {
                
                char ch = word[i];

                // 比较children的ch， 因为root不存储任何字符信息
                if(p_cur->children[ch] == nullptr) {
                    p_cur->children[ch] = new Node();
                }
                p_cur = p_cur->children[ch];
            }

            // 当结尾时，设置当前node的str为完整的pattern str
            p_cur->str = word;
        }
    }

    // 主要是查找和设置fail跳转节点
    void build_AC_from_trie() {
        queue<Node*> node_queue;

        // 单独处理根节点的孩子节点，因为要在queue中添加初始的元素
        for(auto item : _p_root->children) {
            if(item != nullptr) {
                item->fail = _p_root;
                node_queue.push(item);
            }
        }

        while (! node_queue.empty()) {

            // 从队列中出队一个字母
            Node* p = node_queue.front(); node_queue.pop();

            
            for(int i=0; i<p->children.size(); ++i) {
                if(p->children[i] != nullptr) {
                    /*孩子节点入队*/
                    node_queue.push(p->children[i]);

                    Node* p_fail_to = p->fail;
                    while (true) {
                        // 指向根节点
                        if(p_fail_to == nullptr) {
                            p->children[i]->fail = _p_root;
                            break;
                        }

                        // TODO: ??
                        // 有公共前缀
                        if(p_fail_to->children[i] != nullptr) {
                            p->children[i]->fail = p_fail_to->children[i];
                            break;
                        } else {
                            // 继续向上寻找
                            p_fail_to = p_fail_to->fail;
                        }
                    }
                }
            }
        }   
    }

    TACRet find(string text) {

        TACRet result;
        
        for(auto item : _dictionary) {
            result[item] = vector<int>();
        }

        Node* p_cur = _p_root;
        int i = 0;

        while (i < text.length()) {
            char ch = text[i];

            // 文本中的字符和AC自动机中的字符比较
            if(p_cur->children[ch] != nullptr) {
                p_cur = p_cur->children[ch];

                if(p_cur->is_word()) {
                    result[p_cur->str].push_back(i-p_cur->str.length()+1);
                }

                if(p_cur->fail != nullptr && p_cur->fail->is_word()) {
                    result[p_cur->fail->str].push_back(i-p_cur->fail->str.length() + 1);
                }

                // 下一个字符
                ++i;

            } else {
                p_cur = p_cur->fail;

                if(p_cur == nullptr) {
                    p_cur = _p_root;
                    ++i;
                }
            }
        }

        return result;   
    }

private:
    // trie 树的根节点
    Node* _p_root;
    
    // 字典
    vector<string> _dictionary;
};


int main(int argc, char const *argv[])
{
    //vector<string> dict = {"abcdef", "abhab", "bcd", "cde", "cdfkcdf"};
    // string text = "bcabcdebcedfabcdefababkabhabk";
    
    vector<string> dict = {"a", "aa", "ab", "ababa","ababb","aba","abb","a","b","b$","ba","baba","babb","ba","bb"};    
    string text = "aabababb$";

    AhoCorasicAutomation ac_automation(dict);

    TACRet result = ac_automation.find(text);

    cout << "result: ";
    for(auto item : result) {
        cout << item.first << ":(";
        for(auto pos : item.second) {
            cout << pos << ",";
        }
        cout << ") \t";
    }

    return 0;
}
