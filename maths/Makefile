
all: unittest

clean:
	rm unittest *.o

unittest: unittest.c ../include/maths.h vector.c matrix.c
	cc $< vector.c matrix.c -o $@ -I../include
