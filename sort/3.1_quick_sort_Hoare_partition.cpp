/*
 * @Author: liuyanan 
 * @Date: 2019-02-16 15:14:45 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-02-17 18:47:44
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
        lumuto_partition
            在根据pivotpartition的时候，把pivot也放到了最终的位置
            其方法:
                是从做到右的单一方向，不断比较和交换，来找到pivot的位置
        hoare_partition
            单纯的依照某个pivot进行partition，并没有把pivot放到最终的位置
            其方法:
                是从左右向中间的两个方向上， 同时根据pivot进行交换整理，
                目的不是找到pivot的位置，只是划分small和big两部分

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

u_long hoare_partition(long* array, size_t low, size_t high)
// 注意这里的[low, high]是闭区间的
// 这个函数返回的是pivot元素的index
{
    // 选取pivot
    // {10, 80, 30, 90, 40, 50, 70}
    const long v = median3(array[0], array[low + (high-low)/2], array[high]);

    cout << "median:" << v << endl;

    // 两个指针都越界了，注意后边的处理
    u_long left = low - 1;
    u_long right = high + 1;

    while(1) {
        // 当这个loop退出的时候，left_idx对应的元素就是需要放到右边的
        do{ ++left; } while(array[left] < v);
        
        // 当这个loop退出的时候，right_idx对应的元素就是需要放到左边的
        do{ --right;} while(array[right] > v);

        /* 
        注意这里的处理，
            pivot只是一个虚拟存在的比较对象
            我们并没有把pivot放到最终的位置上
         */
        if(left < right) {
            swap(array[left], array[right]);
        } else {
            return right;
        }
    }
}

void quick_sort(long* array, size_t low, size_t high)
{
    if(low < high) {
        u_long pivot_idx = hoare_partition(array, low, high);
    
        display("after parition array", vector<long>(array, array+7));
        cout << "after parition pivot index: " << pivot_idx << ", pivot value: " << array[pivot_idx] << endl;

        /*
        IMPORTANT：
            注意这里的区间，下一次递归时，p并没有被排除（即，第一行不是p-1）
            这是因为当hoare_partition结束时，
            只能保证a[p…j]中的每一个元素都小于或等于a[j+1…r]中的元素，其所选取的主元并没有就位。
            也就是 j 或 j+1 并不是pivot
        */        
        quick_sort(array, low, pivot_idx);
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
