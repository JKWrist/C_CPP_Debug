CC=gcc
CFLAGS=-DMEMWATCH -DMEMWATCH_STDIO

memtest: memtest.o memwatch.o
	$(CC) -o $@ $^

clean:
	rm memtest *.o *.log 
