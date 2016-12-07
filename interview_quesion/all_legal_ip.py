#! coding:utf8

'''
实现一个函数，输入为一个只有数字的字符串，输出所有它加上一些点后可能形成的所有合法的ip字符串数组（任意顺序）

输入： "2502501135"
输出： ["250.250.11.35", "250.250.1.135" .....]
'''


def legal_ip(string):
    try:
        if int(string) < 255 and int(string) >= 0:
            return True
        else:
            return False
    except:
        return False


def get_ips(string):

    ret = []

    for i in xrange(1, 5):
        for j in xrange(1, 5):
            for k in xrange(1, 5):
                if (all([legal_ip(string[0:i]), legal_ip(string[i:-j][0:k]), legal_ip(string[i:-j][k:]), legal_ip(string[-j:])])):

                    ret.append('.'.join([string[0:i], string[i:-j][0:k], string[i:-j][k:], string[-j:]]))
                    print string[0:i], string[i:-j][0:k], string[i:-j][k:], string[-j:]

    return ret

if __name__ == '__main__':
    # print get_ips("2502501135")
    print get_ips("250250")
