/*
 * @Author: liuyanan 
 * @Date: 2019-02-16 11:49:20 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-16 12:06:29
 */


#include <iostream>
#include <vector>

using namespace std;


/*
    基本思想：
        每趟把最大的那个赶到最后，
        特点是每次只把相邻的两个数比较，因为只要前边比后边大就进行交换
        所以每趟来说，会有 n 次比较和 m 次交换
*/

void bubble_sort(vector<long>& array)
{
    if(array.empty()) return;

    // 这个for循环的意思是有多少个数我们就需要找多少次最大值
    for(int i=0; i<array.size(); ++i) {
        
        // 这层for循环是找到第 i 个最大的值，放到最后
        for(int j=0; j<(array.size()-(i+1)); ++j) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void display(const string& msg, const vector<long>& array)
{
    cout << msg << ":\t";
    for(auto item : array) {
        cout << item << "\t";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{

    vector<long> array = {7,3,4,1,8,3,6,0,5,2};
    
    display("before sort", array);
    bubble_sort(array);
    display("after  sort", array);
    
    return 0;
}
