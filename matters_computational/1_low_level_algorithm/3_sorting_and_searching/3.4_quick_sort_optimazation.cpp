/*
 * @Author: liuyanan 
 * @Date: 2019-02-18 10:48:52 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-18 17:13:06
 */


#include <iostream>
#include <vector>
#include <random>

using namespace std;


/*
    quick sort 在现实使用中的优化：
        1. 对于小数量的数组（小于一定阈值的），使用 selecttion sort
        2. TODO: 递归调用的时候，递归元素较少的那个partition
                // 这个优化不适用于pivot选取begin或end元素的情况
                // 比较适合随机选取和选取中间的情况
*/


void display(const string& msg, const vector<long>& array)
{
    cout << msg << ":\n\t";
    for(auto item : array) {
        cout << item << "\t";
    }
    cout << endl;
}

void display(const string& msg, long* array, size_t low, size_t high)
{
    cout << msg << ":\n\t";
    for(size_t i=low; i<=high; ++i) {
        cout << array[i] << "\t";
    }
    cout << endl;
}

void selection_sort(long* array, size_t low, size_t high)
{
    for(size_t i=low; i<high; ++i) {

        size_t min_idx = i;

        for(size_t j=i+1; j<=high; ++j) {
            if(array[min_idx] > array[j]) {
                min_idx = j;
            }
        }

        if(min_idx != i) {
            swap(array[min_idx], array[i]);
        }
    }

    display("after using selection sort", array, low, high);
}

u_long lumuto_partition(long* array, size_t low, size_t high)
// 注意这里的 [low，high] 是闭区间
{
    // 选取pivot
    // const long pivot = array[high];
    const long pivot = array[high];

    cout << endl << endl;
    display("using partition sort", array, low, high);
    cout << "pivot: " << pivot << endl;
    cout << "low: " << low << endl;
    cout << "high: " << high << endl;
    // display("using partition", array, low, high);

    u_long left_boundary = low - 1;

    for(int i=low; i<=high-1; ++i) {

        if(array[i] <= pivot) {
            ++left_boundary;
            swap(array[left_boundary], array[i]);
        }
    }

    left_boundary += 1;

    swap(array[left_boundary], array[high]);
    
    cout << "after partition" << endl;
    display("  low", array, low, left_boundary-1);
    cout << "  pivot:" << array[left_boundary] << endl;
    display("  high", array, left_boundary+1, high);
    cout << endl;

    return left_boundary;

    /*
        当 lumuto_partition  返回的时候有： small <= pivot <= big
        也就是说pivot在它应该在的位置上
    */
}

void quick_sort(long* array, size_t low, size_t high)
{
    while(low < high) {
        
        if(high-low < 8) {    
            selection_sort(array, low, high);
            return;
        }

        u_long pivot_idx = lumuto_partition(array, low, high);

        quick_sort(array, low, pivot_idx-1);

        // 这里怎么回事?? 
        // 这是因为low 到pivot之间的数据已经排好序了，low要往右移
        low = pivot_idx + 1;

        quick_sort(array, pivot_idx+1, high);

        high = pivot_idx - 1;

/*
        TODO:
        cout << "before apply quick sort, low=" << low <<", pivot_dix=" << pivot_idx << ", high=" << high << endl;

        size_t ln = pivot_idx - low;
        size_t hn = high - pivot_idx;
        
        // 当时边界的时候，hn或是ln是一个很大的数（有符号的负数）
        // 正好会执行对面的调用
        cout << "ln:" << ln << ", hn:" << hn << endl;

        // 如果使用了小区间递归的优化，那partition的时候不能选用最后为pivot的方案
        if(ln < hn) {
            cout << "recursive call quick sort in low [" << low << "," << pivot_idx-1 << "]"  
            << ", low_len=" << ln << endl;
            quick_sort(array, low, pivot_idx-1);

            //  忘记了更新low，high，在上一句的quick_sort()执行完后，low，high，已经变了
            //    下次执行的时候有可能执行的是selection_sort，
            //    所以我们要为selection sort准备参数
            
            low = pivot_idx + 1;

        } else {
            cout << "apply quick sort in high [" << pivot_idx+1 << "," << high << "]"
            << ", low_len=" << ln << endl;
            quick_sort(array, pivot_idx+1, high);

            high = pivot_idx - 1;
        }
*/
    }
}

int main(int argc, char const *argv[])
{
    long array1[] = {10, 80, 30, 90, 40, 50, 70};
    long array[] = {10, 80, 30, 90, 40, 50, 70, 9, 4, 7, 23, 89, 100, 99, 201};
    size_t len = sizeof(array) / sizeof(long);

    cout  << "array len: " << len << endl;

    for(int i=0; i<1000; ++i) {
        display("before sort", vector<long>(array, array+len));
        quick_sort(array, 0, len-1);
        display("after  sort", vector<long>(array, array+len));
    }
    
    return 0;
}
