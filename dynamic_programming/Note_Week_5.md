Week 5  : Dynamic Programming
======

#### Knapsack

<img src="pics/QQ20160918-0@2x.png" alt="Drawing" style="width: 400px;"  />  <img src="pics/QQ20160918-1@2x.png" alt="Drawing" style="width: 400px;"  />

在后两种的knapsack问题中，greedy algorithm不适用的原因是因为在有了 none-fraction 的限制后，greedy algorithm 会认为问题无解

<img src="pics/QQ20160918-2@2x.png" alt="Drawing" style="width: 400px;"  />  <img src="pics/QQ20160918-3@2x.png" alt="Drawing" style="width: 400px;"  />

#### Knapsack with Repetitions

<img src="pics/QQ20160918-2@2x.png" alt="Drawing" style="width: 400px;"  />

###### Subproblems

这哥们讲的很明白啊，比之前那个讲的要好理解

每个动态规划问题都由许多 subproblem 构成

- greedy algorithm 是正向思维，每次我们找最合适的一个物品，直到填满
- dynamic programming 是逆向思维，也就是，我们先假设一个最优解，然后当我们拿掉一个物品后，就演变成计算W-w<sub>i</sub> 的最优解了
- 第二张图（右图），定义了一个递归问题，每个字问题都是求解一个最优问题

<img src="pics/QQ20160918-5@2x.png" alt="Drawing" style="width: 400px;"  /><img src="pics/QQ20160918-6@2x.png" alt="Drawing" style="width: 400px;"  />

例子如下（右图可以验证代码实现）：

<img src="pics/QQ20160918-7@2x.png" alt="Drawing" style="width: 400px;" /><img src="pics/QQ20160918-8@2x.png" alt="Drawing" style="width: 400px;" />


#### Knapsack without Repetitions
