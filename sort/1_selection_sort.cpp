/*
 * @Author: liuyanan 
 * @Date: 2019-02-15 17:39:33 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-16 11:54:37
 */


#include <iostream>
#include <vector>

using namespace std;

/*
    基本思想：
        选择排序是每次找最小的元素，放到前边
            每趟比较多次，把最小的那个记录下来，最后交换一次
            n 次比较，1次交换
        VS 冒泡排序
            冒泡是把最大的赶到最后
            n 次比较，n次交换

        1. 从第一个元素开始，遍历数组，找到最小的那个元素
        2. 和第一个元素交换
        3. 对剩下的元素执行 1，2 步的操作
*/

void selection_sort(vector<long>& array)
{
    if(array.empty()) return;

    for(int i = 0; i< array.size(); ++i) {
        
        // 第一个元素
        auto min_idx = i;

        // 从它后边找，找到比它还小的
        for(int j=i+1; j<array.size(); ++j) {
            min_idx = array[min_idx] < array[j] ? min_idx : j;
        }

        // 把小元素放到前边
        swap(array[i], array[min_idx]);
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
    selection_sort(array);
    display("after  sort", array);
    
    return 0;
}
