
import ctypes

DEBUG = 1

class _perceptron(ctypes.Structure):
	_fields_ = [("n_weights", ctypes.c_int),("bias", ctypes.c_float), ("weights", ctypes.POINTER(ctypes.c_float))]

class perceptron():

	def __init__(self):
		self.so_file = "./c_perceptron.so"
		self.perceptron_funcs = ctypes.CDLL(self.so_file)
		self.perceptron_funcs.perceptron_init_from_weights.restype = ctypes.c_int
		self.perceptron_funcs.perceptron_init_from_weights.argtypes = \
   			[ ctypes.POINTER(ctypes.POINTER(_perceptron)), ctypes.c_int, ctypes.c_float, ctypes.POINTER(ctypes.c_float) ]
		self.valid = False

	def init_from_weights_and_bias( self, weights, bias ):

		self.n_weights = len(weights)
		self._weights = (ctypes.c_float * self.n_weights)(*weights)
		if DEBUG>0: print(self._weights, type(self._weights))

		self._bias = ctypes.c_float(bias)

		self.p_inst = ctypes.POINTER(_perceptron)()
		if DEBUG>0: print(self.p_inst,type(self.p_inst))

		ret = self.perceptron_funcs.perceptron_init_from_weights( ctypes.byref(self.p_inst), self.n_weights, self._bias, self._weights)
		if DEBUG>0:
			print("n_weights=",self.p_inst.contents.n_weights)
			print("weights=",[self.p_inst.contents.weights[i] for i in range(self.n_weights)])
			print("bias=",self.p_inst.contents.bias)

		if ret==0:
			self.valid=True
		else:
			print("Underlying c implementation return error=%d" % ret )
			self.valid = False
		
