CC=gcc --std=c99 -g

test_circarray: test_circarray.c circarray.o
	$(CC) test_circarray.c circarray.o -o test_circarray

circarray.o: circarray.c circarray.h
	$(CC) -c circarray.c

clean:
	rm -f test_circarray circarray.o 
	rm -rf test_circarray.dSYM
