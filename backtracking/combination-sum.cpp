#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <numeric>
#include <unordered_set>

using namespace std;

/*
    给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
    你可以按 任意顺序 返回这些组合。
    candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

    对于给定的输入，保证和为 target 的不同组合数少于 150 个。

    示例 1：
        输入：candidates = [2,3,6,7], target = 7
        输出：[[2,2,3],[7]]
        解释：
        2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
        7 也是一个候选， 7 = 7 。
        仅有这两种组合。

    示例 2：
        输入: candidates = [2,3,5], target = 8
        输出: [[2,2,2,2],[2,3,3],[3,5]]

    示例 3：
        输入: candidates = [2], target = 1
        输出: []


    提示：
        1 <= candidates.length <= 30
        2 <= candidates[i] <= 40
        candidates 的所有元素 互不相同
        1 <= target <= 40
 */



string display(vector<int> data)
{
    ostringstream oss;

    for(auto i: data) {
        oss << i << ", ";
    }

    return oss.str();
}

unordered_set<string> result;

void combination_sum(const vector<int>& candidates, const int target, vector<int>& cur, int idx) {

    int sum = accumulate(cur.begin(), cur.end(), 0);
    if(sum > target) {
        return;
    }

    if(sum == target) {
        string ret = display(cur);
        if(result.insert(ret).second) {
            cout << ret << endl;
        }
        return;
    }

    for(int i=idx; i<candidates.size(); ++i) {
        if(!cur.empty() && candidates[i] < cur.back()) {
            // 去重
            continue;
        }
        cur.push_back(candidates[i]);
        combination_sum(candidates, target, cur, idx);
        cur.pop_back();
    }
}

int main(int argc, char **argv) {

    vector<int> nums = {2,3,5};
    std::cout << "original data: " << display(nums) << std::endl;

#if 1
    vector<int> current;
    int target = 8;
    combination_sum(nums, target, current, 0);
#else
    generate_combinations_mask(nums);
#endif

    return 0;
}


/*
  from deepseek:
      现在，具体的实现步骤可能是这样的：

1. 确定数组的长度n。

2. 计算总共有2^n个子集，包括空集。

3. 遍历每个可能的子集，即从0到2^n -1的每个数。

4. 对于每个数，将其转换为二进制，然后检查每一位是否为1。每一位对应数组中的一个元素，如果该位是1，就将对应的元素加入到当前子集的字符串中。

5. 将生成的字符串收集起来，最后返回所有字符串的列表。

例如，数组是[1,2,3]，每个子集的二进制位数是3位：

- i=0 → 000 → 空 → 输出空字符串

- i=1 → 001 → 第一个元素 → 1

- i=2 → 010 → 第二个元素 → 2

- i=3 → 011 → 第一、二元素 → 12

- i=4 → 100 → 第三个元素 →3

- i=5 → 101 → 1和3 →13

- i=6 → 110 →2和3 →23

- i=7 →111 →全部 →123

所以总共有8个子集，对应的字符串如上述。那例子中的输出是12、23、13、123、1、2、3、空。
但按照这个顺序的话，可能遍历的顺序是按照i的顺序，比如i=0是空，然后是1，2，3，4等。
但例子中的输出可能没有按照i的顺序排列。不过不管顺序如何，只要所有可能的组合都被生成即可。
 */
