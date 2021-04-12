/*
 * search_in_rotated_sorted_array.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: liuyanan
 */


#include <iostream>
#include <string>


/*
    return the the index of the target value
    给定一没有重复元素的旋转数组（它对应的原数组是有序的），求给定元素在旋转数组内的下标（不存在的返回-1）。

    例如
        有序数组为｛0，1，2，4，5，6，7｝，它的一个旋转数组为｛4，5，6，7，0，1，2｝。
        元素6在旋转数组内，返回2
        元素3不在旋转数组内，返回-1

    思路：
        可以看出中间位置两段起码有一个是有序的（不是左边，就是右边），那么就可以在有序的范围内使用二分查找；如果不再有序范围内，就到另一半去找。

    刚开始看代码时，总是不明白，为啥用用 if (A[left] < A[middle]){} else {}, 这种结构
    疑问是：只查找有序的数组吗，要是不再有序的一边呢
        这是因为二分查找只适用于有序数组，而旋转数组的特性就是二分后，肯定有一边是有序的，
        所以每次只查找有序的部分，如果目标元素在无序部分，那就把无序部分继续二分
 */
int find_in_rotated_sorted_array(int A[], int len, int target) {

    int ret = -1;
    int left = 0;
    int right = len-1;

    // 这里不是 < ， 而是 <=, 当left==right时，也在合法的查找范围内
    while (left <= right) {
        int middle = left + (right-left) / 2;

        if (target == A[middle]){
            ret = middle;
            break;
        }

        if (A[left] < A[middle]) {
            /*
             * 注意这里的left和right与target比较时，需要加等号，而middle不用，因为上边已经加过了
             */
            if (target >= A[left] && target < A[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        } else {
            if (target > A[middle] && target <= A[right]) {
                left = middle + 1;
            } else {
                right = middle -1;
            }
        }
    }

    return ret;
}


void display(int A[], int len, const std::string& msg) {

    std::cout << msg;

    int i = 0;
    while ( i < len) {
        std::cout << A[i++];
    }

    std::cout << std::endl;
}


int main(int argc, char **argv) {

    int A[] = {4,5,6,7,0,1,2};

    int pos = -1;
    int len = sizeof (A) / sizeof(int);

    display(A, len, "original array:");
    //len = remove_duplicates_2(A, len);
    pos = find_in_rotated_sorted_array(A, len, 6);
    std::cout << "target index:" << pos << std::endl;

    return 0;
}



