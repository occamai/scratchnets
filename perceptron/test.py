
def test():
	print('yes')

from ctypes import *
import ctypes
so_file = "./c_perceptron.so"
perceptron_funcs = CDLL(so_file)
Foo = perceptron_funcs.Foo
Foo.argtypes = [POINTER(POINTER(c_ubyte)),POINTER(c_int), POINTER(POINTER(c_ulong))]
mem = POINTER(c_ubyte)()
l = POINTER(c_ulong)()
size = c_int(0)
Foo(byref(mem),byref(size),byref(l))
print(size.value,mem[0],mem[1],mem[2],mem[3])

if __name__ == "__main__":
	test()
