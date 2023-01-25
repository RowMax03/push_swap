CC=gcc
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

push_swap: push_swap.o
	gcc -o push_swap push_swap.o

clean:
	rm -f *.o
