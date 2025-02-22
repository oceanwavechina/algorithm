/*
 * word-search.cpp
 *
 *  Created on: Feb 22, 2025
 *      Author: liuyanan
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <numeric>
#include <unordered_set>

using namespace std;

/*
    给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

    示例 1：
        输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
        输出：true

    示例 2：
        输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
        输出：true

    示例 3：
        输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
        输出：false
 */


bool dfs(const vector<vector<char>>& board, const string& word, int x, int y, vector<vector<bool>>& visited, int idx) {

    if(word.size() == idx) {
        return true;
    }

    if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || visited[x][y] || board[x][y] !=word[idx]) {
        return false;
    }

    visited[x][y] = true;

    bool found = dfs(board, word, x+1, y, visited, idx+1) ||
                 dfs(board, word, x-1, y, visited, idx+1) ||
                 dfs(board, word, x, y+1, visited, idx+1) ||
                 dfs(board, word, x, y-1, visited, idx+1);


    visited[x][y] = false;

    return found;

}


bool word_search(const vector<vector<char>>& board, const string& word) {

    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(dfs(board, word, i, j, visited, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char **argv) {

    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word("ABCCED");
    string cur;

    cout << std::boolalpha << word_search(board, word) << endl;

    return 0;
}
