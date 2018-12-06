'''
Created on Dec 6, 2018

@author: liuyanan

@src: https://www.machinelearningplus.com/python/python-regex-tutorial-examples/

'''
import re


text = '''101 COM    Computers
205 MAT   Mathematics
189 ENG   English'''


def re_split():

    text_withtab = '''the\ttab    example'''

    print('text: ', text)
    print('text_withtab: ', text_withtab)

    """ 1. split 吧匹配的字符串作为 delimiter 对text进行分割"""
    # split 1
    print('re.split(): ', re.split('\s+', text))

    # split 2
    # \s 是匹配所有空白字符(包括\t，\n); + 是匹配最少一个或多个空白字符
    regex_allspace = re.compile('\s+')
    print('regex_obj.split(): ', regex_allspace.split(text))

    regex_space_only = re.compile('\s')
    print('regex_withspace_only_obj.split(): ', regex_space_only.split(text_withtab), '\n')


re_split()


def re_findall():
    """findall 根据匹配规则，把出现的元素，按list返回"""
    # 查找所有 数
    regex_num = re.compile('\d+')
    print('findall_num: ', regex_num.findall(text))

    # 查找所有 单个数字
    regex_num_apparence = re.compile('\d')
    print('findall_numapparence: ', regex_num_apparence.findall(text), '\n')


re_findall()


def re_search_vs_match():
    """ search VS match"""
    # search 返回的是匹配成功的第一次出现的子串的开始和结束的位置
    text2 = """COM    Computers
    205 MAT   Mathematics 189"""
    print('text2: ', text2)
    regex_num = re.compile('\d+')
    s = regex_num.search(text2)
    print('search starting pos: ', s.start())
    print('search ending pos: ', s.end())
    print('substr: ', text2[s.start():s.end()])
    print('substr: ', s.group())

    # match 要求被匹配的substr出现在text的开始
    m = regex_num.match(text2)
    print('match text2: ', m)

    m = regex_num.match(text)
    print('match text: ', m, m.group())

    regex_one_num = re.compile('\d')
    m = regex_one_num.match(text)
    print('match text: ', m, m.group(), '\n')


re_search_vs_match()


def re_substitute():
    """ 字符串的替换"""
    # text 中既有空格又有tab
    text = """101   COM \t  Computers
205   MAT \t  Mathematics
189   ENG  \t  English"""
    print(text)

    # 把多个空格替换成一个空格, 原有的text没有改变
    regex = re.compile('\s+')
    print('substitute result: ', regex.sub(' ', text))
    print('after substitute: ', text)

    # 被替换的字符排除\n,  排除的语法是(?!\n)
    regex = re.compile('(?!\n)\s+')
    print('substitute without \\n result: ', regex.sub(' ', text), '\n')


re_substitute()


def groups():
    """ 找到所有匹配的子串 """
    text = """101   COM   Computers
205   MAT   Mathematics
189   ENG    English"""

    # 方法一， 每个字段分开找
    print('all course num: ', re.findall('[0-9]+', text))
    # {} 里指定的是重复的次数, 语法是{min, max}
    print('all course code: ', re.findall('[A-Z]{3}', text))
    # 一定要指定最小长度，不然会吧course code 也会过滤出来
    print('all course name: ', re.findall('[A-Za-z]{4,}', text))

    # 方法二， group方法
    # group中的每个元素用()包起来，还要注意每个元素之间的空字符 \s*
    regex_group = re.compile('([0-9]+)\s*([A-Z]{3,})\s*([A-Za-z]{4,})')
    print('course by group: ', regex_group.findall(text), '\n')


groups()


def greedy():
    text = "< body>Regex Greedy Matching Example < /body>"
    # 匹配整个tag，也就是最后一个>
    print('greedy findall: ', re.findall('<.*>', text))

    # 匹配最近的 >
    print('lazy findall: ', re.findall('<.*?>', text))
    # 取出两个tag之间的内容
    print('lazy findall: ', re.findall('<.*?>(.*)<.*?>', text))


greedy()


def example():
    text = 'machinelearningplus.com'
    # 分割成单个字符
    print('split per charac: ', re.findall('.', text))

    # 每3个一组分割
    print('split per 3 charac: ', re.findall('...', text))

    # 只查找某个元素
    print('except for one: ', re.findall('\.', text))
    print('except for some: ', re.findall('\.|c|s', text))

    # 排除某个元素
    print('except it: ', re.findall('[^\.]', text))

    # 所有数字
    text = '01, Jan 2015'
    print('any num: ', re.findall('\d+', text))
    # 除了数字
    print('excpet num: ', re.findall('\D+', text))
    # 除了数字
    print('excpet num: ', re.findall('\w+', text))

    # 所有出现的连续的字母
    print('conti chara: ', re.findall('[A-Za-z]+', text))

    # 匹配n次, 这个是找到2个连续，或是3，或是4个连续的
    text = '01, Jan 128 2015'
    print('match n times: ', re.findall('\d{4}', text))
    print('match n times: ', re.findall('\d{2,4}', text))

    # 匹配任意次数的出现的情况
    print('occur any time: ', re.findall(r'co+l', 'cooool'))

    # 要么不出现，要么出现1次
    print('zero or one time: ', re.findall(r'colou?r', 'colour'))
    print('zero or one time: ', re.findall(r'colou?r', 'color'))

    # 边界
    print('boundary: ', re.findall(r'\btoy', 'play toy broke toys'))
    print('boundary: ', re.findall(r'toy\b', 'play toy broke toys with atoy'))
    print('boundary: ', re.findall(r'\btoy\b', 'play toy broke toys with atoy'))


example()
