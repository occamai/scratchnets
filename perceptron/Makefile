
all: unittest c_perceptron.so

clean:
	rm unittest *.so *.o

unittest: unittest.c ../include/perceptron.h ./perceptron.c ../include/maths.h ../maths/vector.c
	gcc $< ./perceptron.c ../maths/vector.c -o $@ -I../include

c_perceptron.so: ../include/perceptron.h ./perceptron.c ../include/maths.h ../maths/vector.c
	gcc -shared -o $@ ./perceptron.c ../maths/vector.c -I../include
