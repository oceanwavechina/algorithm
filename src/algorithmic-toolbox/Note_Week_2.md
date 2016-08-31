Week 2
======

Running Time
------------------

在计算时间复杂度时，分为与迭代(即 n )有关和无关的两部分，**之所以更关注n相关的部分，是因为无论常数项有多大，当随着数据量增大，n就会超过它**，已斐波那契数列为例：
<pre><code>
> int fibcurs(int n) {
>     if (n <= 3)
>         return n;
>     else
>         return fibcurs(n-1) + fibcurs(n-2);
> }
</code></pre>

1. if 条件成立时，执行两行语句(if 判断和 return )，这是与 n 无关的， 执行次数为常量:2, 加上else的return语句一共是3次常量执行
2. 计算else中的 两个递归掉用，是与 n 有关的分别是T(n-1)和T(n-2)
3. 即 T(n) = 3 + T(n-1) + T(n-2)
4. 因此，T(n) >= Fn, Fn是数列的值，要知道 fibcurs for 50:20365011074, with time:27seconds, 用递归计算50的数列值需要27秒啊, 这个值20365011074打印出来才知道有多惊人
5. 更恐怖的是计算100的数列值，在1GHz的cpu上需要 **56年**

<br>

Why So Slow?
-------------

我们计算了太多重复的数值，如下图所示

<img src="pics/QQ20160831-0@2x.png" alt="Drawing" style="width: 500px;"  />