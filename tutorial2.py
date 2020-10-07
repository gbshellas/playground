def myfunc():
	""" Short Description.

	This is the documentation for myfunc.
	"""
	print("hello world")

def myfunc2(i: str) -> str:
	return lambda x: x + i




f1 = lambda x: x + 3

print(f1(5))
print(f1(4))
print(f1(1))

myfunc2('hello world')