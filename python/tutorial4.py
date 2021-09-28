#Lambda expressions tutorial

def func1(x, y) :
    return x(y)

l = lambda a : a + 12
print(func1(l, 19))

print(func1(lambda a : a * 25, 2))

x = lambda a : print(a)
x(12)