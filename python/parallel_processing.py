'''
Created on Dec 3, 2018

@author: liuyanan
'''

import multiprocessing as mp
import numpy as np
import time
import timeit

'''
 计算 Count how many numbers exist between a given range in each row
'''


def get_mp_count():
    # 这个方法可以确定启用多少个并行的worker
    print('Number of processors:', mp.cpu_count())


def prepare_data():
    np.random.RandomState(100)
    # arr = np.random.randint(0, 10, size=[200000, 5])
    arr = np.random.randint(0, 10, size=[5, 5])
    data = arr.tolist()
    return data


data = prepare_data()


def worker(row, minimum=4, maximum=8):

    count = 0

    # 其实下边这样的计算是cpu密集型的，切换多个进程并不能加快处理速度
    for n in row:
        if minimum <= n <= maximum:
            count = count + 1

    # 下面这种场景就适合用多进程了
    time.sleep(1)

    return count


def worker2(i, row, minimum=4, maximum=8):
    count = 0
    # 其实下边这样的计算是cpu密集型的，切换多个进程并不能加快处理速度
    for n in row:
        if minimum <= n <= maximum:
            count = count + 1

    # 下面这种场景就适合用多进程了
    time.sleep(1)
    return (i, count)


def without_parallelization():
    result = []
    for row in data:
        result.append(worker(row, 4, 8))

    return result


def parallelizing_with_poolapply():
    with mp.Pool(mp.cpu_count()) as pool:
        result = [pool.apply(worker, args=(row, 4, 8)) for row in data]
        print(result[:10])
        return result


def parallelizing_with_poolmap():
    with mp.Pool(mp.cpu_count()) as pool:
        result = pool.map(worker, [row for row in data])
        print(result[:10])
        return result


def parallelizing_with_poolstarmap():
    with mp.Pool(mp.cpu_count()) as pool:
        result = pool.starmap(worker, [(row, 4, 8) for row in data])
        print(result[:10])
        return result


def parallelizing_with_poolapply_async():
    results = []

    def collect_result(result):
        results.append(result)

    pool = mp.Pool(mp.cpu_count())
    for i, row in enumerate(data):
        pool.apply_async(worker2, args=(i, row, 4, 8), callback=collect_result)
    pool.close()  # 要先close才能join
    pool.join()
    results.sort(key=lambda x: x[0])

    results_final = [r for i, r in results]
    print(results_final[:10])


def parallelizing_with_poolstarmap_async():
    with mp.Pool(mp.cpu_count()) as pool:
        result = pool.starmap_async(worker2, [(i, row, 4, 8) for i, row in enumerate(data)]).get()
        print(result[:10])


if __name__ == '__main__':
    get_mp_count()
    print('without_parallelization', timeit.timeit(stmt=without_parallelization, number=1))
    # print('parallelizing_with_poolapply', timeit.timeit(parallelizing_with_poolapply, number=1))
    print('parallelizing_with_poolmap', timeit.timeit(parallelizing_with_poolmap, number=1))
    print('parallelizing_with_poolstarmap', timeit.timeit(parallelizing_with_poolstarmap, number=1))
    print('parallelizing_with_poolapply_async', timeit.timeit(parallelizing_with_poolapply_async, number=1))
    print('parallelizing_with_poolstarmap_async', timeit.timeit(parallelizing_with_poolstarmap_async, number=1))
