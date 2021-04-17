#include <iostream>
#include <vector>
#include <ctime>

using std::vector;
using std::cin;
using std::cout;

/*
 * 因为题目要求所有的数据都是正整数，所以这种优化才是正确的
 * 假设可以有负数的话，且要求绝对值最大。也可以这样做，我们就要找到 绝对值 最大的数了
 */
long long MaxPairwiseProductFast(const vector<int>& numbers) {
  int n = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < n; ++i)
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;

  int max_index2 = -1;
  for (int j = 0; j < n; ++j)
    if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
      max_index2 = j;

  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

/*
 * long long 是 64bit
 * 1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
 */
long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    std::time_t start, end;

    start = std::time(nullptr);
    long long result1 = MaxPairwiseProduct(vector<int>(200000, 0));
    cout << result1 << ", with time:" << std::time(nullptr)-start << "\n";

    start = std::time(nullptr);
    long long result2 = MaxPairwiseProductFast(vector<int>(200000, 0));
    cout << result2 << ", with time:" << std::time(nullptr)-start << "\n";

    return 0;
}
