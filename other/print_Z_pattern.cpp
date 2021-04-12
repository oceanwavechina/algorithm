/*
 * @Author: liuyanan 
 * @Date: 2019-01-09 11:31:52 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-01-09 13:20:32
 */

/*
    打印 Z 型

    TestCase
        Input: N = 5
        Output: 
        1 2 3 4 5 
              4
            3
          2
        1 2 3 4 5
*/

#include <iostream>
using namespace std;

void print_z_pattern(uint16_t size) {
    uint16_t num = 0;

    // 打印第一行
    while(num < size) {
        cout << ++num << " ";
    }
    cout << "\n";
    
    // 打印斜线
    num = 4;
    while(num > 0) {
        /*
            2*(num-1) -1, 其中 2*(num-1) 是空格和数字的总数，
            再减一就是要打印的空格数
        */
        for(int i=0; i <= 2*(num-1) -1; ++i) {
            cout << " ";
        }
        cout << num--;
        if(num != 0) {
            cout << "\n";
        }
    }

    // 打印最后一行, 最后一行要先打印空格，在打印数字
    num = 1;
    while(num < 5) {
        cout << " " << ++num;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    print_z_pattern(5);
    return 0;
}
