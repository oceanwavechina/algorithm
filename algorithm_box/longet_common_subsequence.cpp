/*
 * longet_common_subsequence.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: liuyanan
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	求最长公共子序列
	Problem: given two strings x and y, ﬁnd the longest common subsequence (LCS) and print its length
	Example:
		– x: ABCBDAB
		– y: BDCABC
		– “BCAB” is the longest subsequence found in both sequences, so the answer is 4

	原理：
		每遍历一边 y 就能确定，x[i] 在y出现的

	参考：
		http://blog.csdn.net/hrn1216/article/details/51534607
 */

#define MAX_SIZE		10

typedef vector<char> LIST;


int D[MAX_SIZE][MAX_SIZE] = {0};

void display_array()
{
	cout << "array:" << endl;
	for(int i=0; i< MAX_SIZE; ++i) {

		for(int j=0; j<MAX_SIZE; ++j)
		{
			cout << D[i][j] << "\t";
		}

		cout << endl;
	}
}


int lcs(LIST x, LIST y)
{

	int max_len = 0;

	display_array();

	/*
	  遍历要从 1 开始，因为需要之前的的数据，故而从[1][1]开始
	 */
	for(int i = 1; i <= x.size(); ++i) {
		for (int j = 1; j <= y.size(); ++j) {
			if (x[i-1] == y[j-1]) {
				D[i][j] = D[i-1][j-1] +1;
				max_len = D[i][j];
			} else {
				D[i][j] = max(D[i-1][j], D[i][j-1]);
			}
		}
	}

	display_array();

	return max_len;
}

void print_lcs_string(LIST x, int len_x, size_t len_y)
{
	int i = len_x;
	int j = len_y;
	int k = 0;

	int path[MAX_SIZE] = {0};

	while(D[i][j]) {
		if(D[i][j]==D[i-1][j])
			i--;
		else if(D[i][j]==D[i][j-1])
			j--;
		else{
			path[k++]=i-1;
			i--;j--;
		}
	}

	for(int i=k-1;i>=0;i--)
	    printf("%c",x[path[i]]);
	    printf("\n");
}

int main(int argc, char **argv) {

	LIST x = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
	LIST y = {'B', 'D', 'C', 'A', 'B', 'C'};

	int len = lcs(x, y);
	std::cout << "len of lcs:" << len << std::endl;

	print_lcs_string(x, (int)x.size(), (int)y.size());

	return 1;
}
