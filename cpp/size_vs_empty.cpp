/*
 * size_vs_empty.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: liuyanan
 */

/*
 * 今天有同事提到，优化代码时将 list.size()==0 改成 list.empty() 后，cpu的使用率从 400% 降到了 60%
 * 而这可能仅仅是c++11之前版本的问题了。。。
 *
 * 如下:
 * http://stackoverflow.com/questions/10065055/why-is-stdlist-bigger-on-c11
 *
 * 在c++98下，安装老版本g++的机器：
 * 		sizeof(list): 16
 * 		size()==0 : 0m0.536s
 * 		empty()	  : 0m0.090s
 *
 * 在c++11下:
 *		sizeof(list): 24
 *		size()==0 : 0m0.153s
 * 		empty()	  : 0m0.148s
 */


#include <iostream>
#include <list>
#include <ctime>
#include <assert.h>

using namespace std;


int main(int argc, char **argv) {

	list<int> a;
	cout <<  "sizeof(list): " << sizeof(a) << endl;
	for(int i=0; i<1000000; ++i) {
		a.push_back(i);
	}

#if 1

	for(long long i=0; i<100; ++i) {
		if(a.size() == 0) {
			cout << endl;
		}
	}
# else

	for(long long i=0; i<100; ++i) {
			if (a.empty()) {
				cout << endl;
			}
		}
#endif

	return 0;
}
