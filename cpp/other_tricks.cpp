/*
 * other_tricks.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: liuyanan
 */


#include <iostream>

using namespace std;


/*
 *	#	把(literal)参数转换字符常量
 *	## 	把两个常量拼接
 */

#define watch(x) cout << (#x) << " is: " << (x) << endl

#define CATE_NUM_FIVE	"num_5"
#define CATE_NUM_SEX	"num_6"

#define CATE_BUILDER(A,B) A##B



int main(int argc, char **argv) {

	int a = 0;
	watch(a);

	cout << "target category: " << CATE_BUILDER(CATE_NUM, _FIVE) << endl;

	return 0;
}
