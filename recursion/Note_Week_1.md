Week 1
======

Testing techniques
------------------

In the previous section, we've already done some testing and fixed some mistakes. In general, you should test your problem on the following groups of tests before submitting:

1. A few small manual tests.
2. A test for each possible type of answer (smallest answer, biggest answer, answer doesn't exist, etc.)
3. Test for time/memory limit: generate a test with the largest possible size of input ("max test"), run your program, measure time and memory consumption.
*(我想很多时候都不会有这个测试，但是往往这个测试是最有意思的, 更加奇葩的是往往面试的时候还特别爱问，重点是真正到了编码实现的时候，很多人都不会关心这个)*
4. Tests for corner cases:
    * Smallest possible "n": the length of the input sequence or string, the number of queries, etc.
    * Equal numbers, equal letters in the string, more generally, equal objects in the input. Any two objects that are not restricted to be different in the problem statement can be equal.
    * Largest numbers in the input allowed by the problem statement - for example, to test for integer overflow.
    * Degenerate cases like empty set, three points on one line, a tree which consists of just one chain of nodes.

If after all of that you're sure that all answers are correct, but your solution is not accepted in the testing system, and you don't know what is the test case where your solution fails, there's the last resort called stress testing - **a very efficient technique that will find you a test case for which your solution fails probably in 95% of cases not covered by the previously mentioned test types**.
*(对比测试，这个挺有意思的，mark下)*

A stress test consists of four parts:

1. The solution you want to test.
2. A different, possibly trivial and very slow, but easy to implement and obviously correct solution to the problem.
3. A test generator.
4. An infinite loop in which a new test is generated, it is fed into both solutions, then the results are compared, and if they differ, the test and both answers are output, and the program stops, otherwise the loop repeats.

**The idea behind stress testing is that if you have two correct solutions, and the answer to the problem is unique, then for any possible test case they are guaranteed to give the same answer.** If, however, at least one of the solutions is incorrect, then with very high probability there exists a test on which their answers differ. The only case when it is not so is when there is a common mistake in both solutions, but that is very unlikely (unless the mistake is somewhere in the input/output routines which are common to both solutions - check for that separately). Indeed, if one solution is correct and the other is wrong, then there obviously exists a test case on which they differ. If both are wrong, but the bugs are different, then most probably there exists a test on which one solution gives a correct answer and another gives wrong answer, so they differ.

Don't expect stress testing to be the silver bullet. For example, it won't detect the problems your solution has with time limit or memory limit, because you will generate smaller tests because of the second, "trivial" solution, which would run too slow on those. Also, you probably won't detect the integer overflow problems, because you'll generate only small numbers, or because you'll have integer overflow problems in both solutions. You should really first test for all of those separately, before implementing a stress test.


