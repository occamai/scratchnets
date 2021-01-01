
all: clt_from_uniform

clean:
	rm clt_from_uniform *.o

clt_from_uniform: clt_from_uniform.c ../include/stats.h 
	cc $< -o $@ -I../include
