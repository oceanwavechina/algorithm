// cstdlib的本来面目是C语言中的库stdlib.h。在C++中，C语言中的一些库被进行了重命名，去掉了.h并在库名前加c。
#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)(numbers[i])) * numbers[j] > result) {
        result = ((long long)(numbers[i])) * numbers[j];
      }
    }
  }
  return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
  int n = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < n; ++i)
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1])) {
      std::cout << "first:" << numbers[i];
      max_index1 = i;
    }

  // 目测问题应该出现在这里，在取 次大 的元素时，这个 次大 的元素和 最大的元素是想等的
  // 所以我们改成， 比较元素的位置，而不是元素的值（到此，我还没看答案。。。）
  // 在调试时，把两个元素的位置和值打印出来，会有很大的帮助
  // 这个bug告诉我们，区别两个元素的不仅仅是值，还有它的位置
  int max_index2 = -1;
  for (int j = 0; j < n; ++j)
    //if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))){
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))){
      std::cout << "second:" << numbers[j];
      max_index2 = j;
    }

  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
  // 这个对比测试的想法不错，可以推广到 新老业务逻辑的 对比测试，以及不同环境的对比测试
  while (true) {
    int n = rand() % 10 + 2;
    cout << n << "\n";
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 100000);
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << "\n";
    long long res1 = MaxPairwiseProduct(a);
    long long res2 = MaxPairwiseProductFast(a);
    if (res1 != res2) {
      cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
      break;
    }
    else {
      cout << "OK\n";
    }
  }
  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  long long result = MaxPairwiseProductFast(numbers);
  cout << result << "\n";
  return 0;
}
