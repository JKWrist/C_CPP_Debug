CC=gcc
CFLAGS=-g -O0
LDFLAGS=-rdynamic

segfault: segfault.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f segfault *.o
