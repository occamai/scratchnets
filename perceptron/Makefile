
all: perceptron

clean:
	rm perceptron *.o

perceptron: perceptron.c ../include/maths.h ../maths/vector.c
	cc $< ../maths/vector.c -o $@ -I../include
