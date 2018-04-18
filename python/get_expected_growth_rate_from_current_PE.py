#! coding:utf8
'''
Created on Apr 18, 2018

@author: liuyanan
'''

from sympy import *

'''
    缘由：
        对于不同的股票，其对应的市盈率也千差万别，有的是 5X, 有的是 40X， 然而，即便是40X的市盈率，依然不影响其上涨,
        这就是其对应的增长率依然能稳稳的实现，所以对于较高的市盈率，我们可以反推其对应的 期望增长率，
        来判断，未来几年能否保持这个增长，从而可以判断，当前的市盈率是高还是低，进而决定有没有投资价值
        通过这种方法判断的，往往比较适合增长类型的企业
    几个概念：
        1. 预估的年限，我们要假定预估未来几年的增长是合理的，像假设20年这样的跨度显然是不合适的，因为20年后企业在不在都不好说，
            这里比价推荐的是3到5年，这个借鉴了杨宝忠老师的预估时间段
        2. 市盈率， 市盈率看成是回本年限。假设PE=5X， 就是说5年回本，平均每年收益15%。这里的收益是指没有增长的，当前是15%，而且以后每年都是15%
            默认，我们选定5和15%最为比较基准
    计算思路
        1. 假定基准PE=5， 且没有增长。则收益率为1/5=20%， 每年都20%的话，只要5年就回本了
        2. 输入的值有
            @cur_yield_rate: 是当前的收益率, 可以取近几年的平均值
            @cur_PE: 当前的市盈率， 由此可以得出当前的收益率为 1/cur_PE
        我们要计算的是在当前收益率的基础上，每年增长多少(x)，可以达到5年回本的效果
        设x=0.08， 即 5年的总收益是0.08 + 0.08*(1+x) + 0.08*(1+x)^2 + 0.08*(1+x)^3 + 0.08*(1+x)^4 = 1
        问题即是求x
'''


def convert_PE_2_growth(PE):
    cur_yield_rate = 1.0 / PE
    print cur_yield_rate
    x = Symbol('x')
    ret = solve(cur_yield_rate * (1.0 + x) + cur_yield_rate * (1.0 + x) ** 2 + cur_yield_rate * (1.0 + x) ** 3 + cur_yield_rate * (1.0 + x) ** 4 + cur_yield_rate * (1.0 + x) ** 4 - 1.0, x)
    answers = [i for i in ret if 'I' not in str(i) and '-' not in str(i)]
    print answers

    for item in answers:
        print 'answer:', item  # , ' : ', cur_yield_rate + cur_yield_rate * (1 + item) + cur_yield_rate * (1 + item) ** 2 + cur_yield_rate * (1 + item) ** 3 + cur_yield_rate * (1 + item) ** 4
        year_earns = []
        for year in xrange(0, 5):
            year_earns.append(cur_yield_rate * (1 + item)**year)
            print "year 1:" + str(year_earns[-1])

        print 'total:', sum(year_earns)


if __name__ == '__main__':
    '''
    天啊，20X 的 PE，要每年57%的增长速度才能保证5年回本，我这个算法是有问题么。。。。。。？？？？？！！！
    30X 的 PE，要每年 76%的增长速度。。。。。。
    TODO: 知道了，这么算除非企业倒闭，不然假设5年还是时间短了，对不对？？？！！
    懵逼了。。。。
    '''
    convert_PE_2_growth(30)
    pass
