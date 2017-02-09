#! coding:utf8


# Problem 1
def extendList(val, list=[]):
    list.append(val)
    return list


def problem_1():
    list1 = extendList(10)
    list2 = extendList(123, [])
    list3 = extendList('a')

    print "list1 = %s" % list1
    print "list2 = %s" % list2
    print "list3 = %s" % list3


# problem 2
class Parent(object):
    x = 1


class Child_1(Parent):
    pass


class Child_2(Parent):
    pass


def problem_2():
    '''
    The output of the above code will be:

    1 1 1
    1 2 1
    3 2 3
    What confuses or surprises many about this is that the last line of output is 3 2 3 rather than 3 2 1. 
    Why does changing the value of Parent.x also change the value of Child2.x,
     but at the same time not change the value of Child1.x?

    The key to the answer is that, in Python, class variables are internally handled as dictionaries. 
    If a variable name is not found in the dictionary of the current class,
    the class hierarchy (i.e., its parent classes) are searched until the referenced variable name is found
    (if the referenced variable name is not found in the class itself or anywhere in its hierarchy, an AttributeError occurs).

    Therefore, setting x = 1 in the Parent class makes the class variable x (with a value of 1) 
    referenceable in that class and any of its children. That’s why the first print statement outputs 1 1 1.

    Subsequently, if any of its child classes overrides that value (for example, when we execute the statement Child1.x = 2), 
    then the value is changed in that child only. That’s why the second print statement outputs 1 2 1.

    Finally, if the value is then changed in the Parent (for example, when we execute the statement Parent.x = 3), 
    that change is reflected also by any children that have not yet overridden the value (which in this case would be Child2). 
    That’s why the third print statement outputs 3 2 3.

    '''

    print Parent.x, Child_1.x, Child_2.x

    Child_1.x = 2
    print Parent.x, Child_1.x, Child_2.x

    Parent.x = 3
    print Parent.x, Child_1.x, Child_2.x


# problem 3
def div1(x, y):
    print "%s / %s = %s" % (x, y, x / y)


def div2(x, y):
    print "%s // %s = %s" % (x, y, x // y)


def problem_3():
    div1(5, 2)
    div1(5., 2)
    div2(5, 2)
    div2(5., 2)


# problem 4
def problem_4():
    list = ['a', 'b', 'c', 'd', 'e']
    print list[10:]


# problem 5
def problem_5():
    '''
        However, the key thing to understand here is that the statement list = [ [ ] ] * 5 
        does NOT create a list containing 5 distinct lists; 
        rather, it creates a a list of 5 references to the same list. 
        With this understanding, we can better understand the rest of the output.
    '''
    list = [[]] * 5
    print list

    list[0].append(10)
    print list

    list[1].append(20)
    print list

    list.append(30)
    print list


# problem 6
def problem_6():
    '''
        Build a string with the numbers from 0 to 100, "0123456789101112..."

        Note:
            Note that the (`) is a backquote not a regiular single quote ('):
    '''
    print ''.join([`x` for x in xrange(101)])

    print type(1), type(`1`)

if __name__ == '__main__':
    # problem_1()
    # problem_2()
    # problem_3()
    # problem_4()
    # problem_5()
    problem_6()
