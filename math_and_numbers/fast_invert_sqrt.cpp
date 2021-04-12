/*
 * fast_invert_sqrt.cpp
 *
 *  Created on: Apr 19, 2018
 *      Author: liuyanan
 */

#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <complex>

using namespace std;

float InvSqrt(float x)
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x;       // get bits for floating value
    i = 0x5f3759df - (i>>1); // gives initial guess y0
    x = *(float*)&i;         // convert bits back to float
    x = x*(1.5f-xhalf*x*x);  // Newton step, repeating increases accuracy
    return x;
}

float InvSqrt_improved(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x; // get bits for floating value
	i = 0x5f375a86- (i>>1); // gives initial guess y0
	x = *(float*)&i; // convert bits back to float
	x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
	return x;
}



float STLInVSqrt(float x)
{
	return std::pow(x, -0.5);
}

float Multiply(float x)
{
	return x * (x);
}


int main(int argc, char **argv) {

	typedef float (*sqrt_t)(float);

	map<string, sqrt_t> func_map = {
			{"0_InvSqrt", InvSqrt},
			{"1_STLInVSqrt", STLInVSqrt},
			{"2_Multiply", Multiply},
			{"3_InvSqrt_improved", InvSqrt_improved},
			};

	vector<float> test_cases = {1.0, 2.0, 3.1, 4.3, 45, 67, 222, 9876739, 1938389.0, 384595.999};

	for (auto it : func_map) {
		std::clock_t start = std::clock();
		for (int i=0; i<1000000; ++i){

			for(int j = 0; j< test_cases.size(); ++j) {
				it.second(test_cases[j]);
			}
		}

		std::clock_t end = std::clock();
		std::cout << "time of " << it.first <<": " << 1000.0 * (end-start) / CLOCKS_PER_SEC << "ms" << endl;

	}

	return 0;
}
