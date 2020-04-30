/*
 * @Author: liuyanan 
 * @Date: 2020-04-30 16:04:54 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2020-04-30 17:57:21
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>

/*
    用类似bloom fileter的方法，统计出现频率top n的元素
    http://web.stanford.edu/class/cs168/index.html
    Approximate Heavy Hitters and the Count-Min Sketch.pdf

    这个东西可以当做一个可以计数的hash用，但是空间会降低很多
*/


using namespace std;

typedef string TElement;

#define MAX_BUKETS 2000
#define N_HASH_FUNC 5

class CounterMinSketch {
public:
    CounterMinSketch() {
        for (long i=0; i<N_HASH_FUNC; ++i) {
            memset(_cms[i], 0, MAX_BUKETS * sizeof(long));
        }
    }

    void incre(TElement x) {
        for(long i=0; i<N_HASH_FUNC; ++i) {   
            long l = _get_hash(x, i);
            _cms[i][l] += 1;
        }

    }

    int count(TElement x) {
        long count = LONG_MAX;
        for(long i=0; i<N_HASH_FUNC; ++i) {
            long l = _get_hash(x, i);
            count = min(count, _cms[i][l]);
        }

        return count;
    }

private:
    long _get_hash(TElement content, long idx) {
        return _hash_func(content + to_string(idx)) % MAX_BUKETS;
    }

private:
    // 计数矩阵
    long _cms[N_HASH_FUNC][MAX_BUKETS];
    
    // hash 函数
    std::hash<std::string> _hash_func;
};

int main(int argc, char const *argv[])
{
    ifstream in_file("uids.txt");

    CounterMinSketch counter;

    string line;
    while(getline(in_file, line)) {
        counter.incre(line);
    }

    /*
        在定位前对流状态标志进行清除：
        file1读结束后，eof()返回真值时，file1的错误标志被设置为eofbit，
            于是，后续所有针对file1的操作都不能得到预期的结果，
            比如tellp、tellg、seekg、seekp等，
            因此，在进行其他针对file1的操作前，需要清除该错误标志~~~!
    */
    in_file.clear();
    in_file.seekg(0, ios::beg);

    unordered_set<string> uniq_uids;
    while(getline(in_file, line)) {
        auto ret = uniq_uids.insert(line);
        if(ret.second) {
            cout << "('" << line << "', " << counter.count(line) << ")" << endl;
        }
    }

    return 0;
}
