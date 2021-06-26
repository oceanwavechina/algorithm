/*
 * none_make_team.cpp
 *
 *  Created on: Mar 12, 2021
 *      Author: liuyanan
 */


#include <iostream>
#include <algorithm>

using namespace std;


/*
	在ACM竞赛中，一支队伍由三名队员组成，现在有N+M名学生，其中有N名学生擅长算法，剩下M名学生擅长编程，
	这些学生要参加ACM竞赛，他们的教练要求每支队伍至少有一名擅长算法和一名擅长编程的学生，
	那么这些学生最多可以组成多少支队伍？

	输入： 输入两个整数M，N，其中1<N,M<10000000

	输出：最多可以组成的队伍数
 */

long make_team(long M, long N)
{
	int cnt = 0;

	while( (M+N) >=3 && M >= 1 && N >= 1) {
		--M;
		--N;

		if(M > N) {
			--M;
			++cnt;
		} else {
			--N;
			++cnt;
		}
	}

	return cnt;
}

int main(int argc, char **argv)
{
	cout << "team cnt:" << make_team(23, 34) << endl;

}
