/*
 * @Author: liuyanan 
 * @Date: 2019-02-17 16:49:55 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-17 18:18:59
 */

#include <iostream>
#include <vector>

using namespace std;


/*
    基本思想：
        快排的思想不是找最大最小值，而是partition，对给定的范围进行大小整理
        从另一个角度看，可以叫找中间的值
        partition的执行时间一定要是线性的
    
    partition的模式：
    

    选择pivot常用的方法：
        1. Always pick first element as pivot.
        2. Always pick last element as pivot
        3. Pick a random element as pivot.
        4. Pick median as pivot.
*/

long median3(const long& x, const long& y, const long& z) {
    return x<y ? (y<z ? y : (x<z ? z : x)) : (z<y ? y : (z<x ? z : x));
}

void display(const string& msg, const vector<long>& array)
{
    cout << msg << ":\t";
    for(auto item : array) {
        cout << item << "\t";
    }
    cout << endl;
}

u_long lumuto_partition(long* array, size_t low, size_t high)
// 注意这里的 [low，high] 是闭区间
{
    // 选取pivot
    const long pivot = array[high];
    cout << endl << endl;
    cout << "pivot: " << pivot << endl;
    cout << "low: " << low << endl;
    cout << "high: " << high << endl;

    u_long left_boundary = low-1;

    for(int i=low; i<=high-1; ++i) {

        if(array[i] <= pivot) {
            ++left_boundary;
            swap(array[left_boundary], array[i]);
        }
    }

    swap(array[left_boundary+1], array[high]);
    
    return left_boundary+1;

    /*
        当 lumuto_partition  返回的时候有： small <= pivot <= big
        也就是说pivot在它应该在的位置上
    */
}

void quick_sort(long* array, size_t low, size_t high)
{
    if(low < high) {
        u_long pivot_idx = lumuto_partition(array, low, high);
        display("after partition", vector<long>(array, array+7));
        
        /* 
            IMPORTANT:
                这里有个需要注意的重点，就是, 第二次partition的时候不能包括pivot
                因为：
                    第一次partition的时候pivot已经就位了，如果在small(或big)部分再次包含，
                    并且当前部分已经有序了，等下次partition的时候，还是那个pivot，
                    如此就会陷入死循环
            
        */
        // quick_sort(array, low, pivot_idx);
        // quick_sort(array, pivot_idx+1, high);
        quick_sort(array, low, pivot_idx-1);
        quick_sort(array, pivot_idx+1, high);
    }
}

int main(int argc, char const *argv[])
{
    long array[] = {10, 80, 30, 90, 40, 50, 70};
    size_t len = sizeof(array) / sizeof(long);

    cout  << "array len: " << len << endl;

    display("before sort", vector<long>(array, array+len));
    quick_sort(array, 0, len-1);
    display("after  sort", vector<long>(array, array+len));
    
    return 0;
}
