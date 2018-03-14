#! coding:utf8

'''
基于PB的未来5年股票价格估算
主要适用于金融资产类股票的测试算，我们要假设未来5年企业的ROE是稳定增长的（起码平均值是这样）
'''

book_value_per_share = 6.88
ROE_estimates = 0.11
earn_per_share_estimates = 0.27
year = 5


def get_the_fifth_year_price():
    target_price = book_value_per_share

    for i in xrange(year):
        target_price = target_price * (1 + ROE_estimates) - earn_per_share_estimates

    target_price = round(target_price, 2)
    return target_price


def get_all_five_years_earn():
    target_earn = earn_per_share_estimates * year
    return target_earn


def estimate_fifth_years_value():
    return get_all_five_years_earn() + get_the_fifth_year_price()


def five_year_growth_rate():
    return (estimate_fifth_years_value() - book_value_per_share) / book_value_per_share


def compound_growth_rate():
    return pow((estimate_fifth_years_value() / book_value_per_share), 1.0 / year) - 1


if __name__ == '__main__':

    print 'input'
    print '\tbook_value_per_share', book_value_per_share
    print '\tROE_estimates', ROE_estimates
    print '\tearn_per_share_estimates', earn_per_share_estimates
    print '\tyear_range', year

    print 'output'
    print '\tthe fifth year\'s price is:', get_the_fifth_year_price()
    print '\tall five year\'s earn is:', get_all_five_years_earn()
    print '\tfive year\'s growth rate:%.2f%%' % (five_year_growth_rate() * 100)
    print '\tcompound growth rate:%.2f%%' % (compound_growth_rate() * 100)
