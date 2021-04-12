/*
 * memory_pool.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: liuyanan
 */


#include <cstdint>
#include <iostream>
#include <sys/time.h>

using namespace std;


long getCurrentTime()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class CTestClass
{
    char m_chBuf[4096];
};


void sys_call_allcote_memory_test()
{
	long start = getCurrentTime();

	// 当编译时加了优化选项会把下面的操作优化掉
    for(int i=0; i<0x5ffffff; ++i)
    {
        CTestClass *p = new CTestClass;
        delete p;
    }

    cout << "Interval = " << getCurrentTime()-start << " ms" << endl;
}

int main()
{
	// Interval = 6902 ms
	sys_call_allcote_memory_test();

    return 0;
}
