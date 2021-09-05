import ctypes
import unittest
import random
import math

DEBUG = 1

class _perceptron(ctypes.Structure):
	'''This python class maps to the C percpetron structure.'''

	_fields_ = [("n_weights", ctypes.c_int),("bias", ctypes.c_float), ("weights", ctypes.POINTER(ctypes.c_float))]

class perceptron():
	'''This python class maps to the C perceptron object and functions.'''

	def __init__(self):

		# Initialize ctypes
		self.so_file = "./c_perceptron.so"
		self.perceptron_funcs = ctypes.CDLL(self.so_file)

		# Map C function in-out to python
		self.perceptron_funcs.perceptron_init_from_weights.restype = ctypes.c_int
		self.perceptron_funcs.perceptron_init_from_weights.argtypes = \
   			[ ctypes.POINTER(ctypes.POINTER(_perceptron)), ctypes.c_int, ctypes.c_float, ctypes.POINTER(ctypes.c_float) ]

		self.valid = False

	def init_from_weights_and_bias( self, weights, bias ):

		# Prepare arguments
		self._n_weights = len(weights)
		self._weights = (ctypes.c_float * self.n_weights)(*weights)
		self._bias = ctypes.c_float(bias)
		self.p_inst = ctypes.POINTER(_perceptron)()

		# Invoke the C function
		ret = self.perceptron_funcs.perceptron_init_from_weights( ctypes.byref(self.p_inst), self._n_weights, self._bias, self._weights)

		# Validate C function return
		if ret==0:
			self.n_weights = self.p_inst.contents.n_weights
			self.weights= = [self.p_inst.contents.weights[i] for i in range(self.n_weights)]
			self.bias = self.p_inst.contents.bias
			self.valid=True
		else:
			print("Underlying C implementation return error=%d" % ret )
			self.valid = False
			return False

		# Unpack C function return values		
		self.n_weights = self.p_inst.contents.n_weights
		self.weights= = [self.p_inst.contents.weights[i] for i in range(self.n_weights)]
		self.bias = self.p_inst.contents.bias

		return True

class TestPerceptron(unittest.TestCase):
	'''The main unit test for this python module.'''

	def test_init(self):

		# choose random number of weights
		n_weights = int( math.celing( 50 * random.random() ) )
		print("n_weights = ", n_weights )

		# create random weights vector
		weights = [ 

		p = perceptron()
		ret = p.init_from_weights_and_bias(
