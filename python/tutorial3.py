x = 10
print('the global variable x is ' + str(x))

def func1():
    global x  # setting global variable
    x = 25 #changing global variable value
    print('func1() the global variable x is ' + str(x))

def func2():
    x = 63  #setting local variable value
    print('func2() the variable x is ' + str(x))

func1()
func2()

print('the global variable x is ' + str(x))

mystr = ""
