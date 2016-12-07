#! coding:utf8

'''
实现一个函数，输入为一个只有数字的字符串，输出所有它加上一些点后可能形成的所有合法的ip字符串数组（任意顺序）

输入： "2502501135"
输出： ["250.250.11.35", "250.250.1.135" .....]
'''


def legal_ip(str):
    try:
        if int(str) < 255:
            return True
        else:
            return False
    except:
        return False


def get_ips(str):

    ret = []

    for i in xrange(1, 5):
        for j in xrange(1, 5):
            for k in xrange(1, 5):
                if (all([legal_ip(str[0:i]), legal_ip(str[i:-j][0:k]), legal_ip(str[i:-j][k:]), legal_ip(str[-j:])])):
                    ret.append('.'.join([str[0:i].lstrip('0'), str[i:-j][0:k].lstrip('0'), str[i:-j][k:].lstrip('0'), str[-j:].lstrip('0')]))
                    # print str[0:i], str[i:-j][0:k], str[i:-j][k:], str[-j:]

    return ret

if __name__ == '__main__':
    print get_ips("2502501135")
