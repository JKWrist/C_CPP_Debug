.PHONY:all,release,debug,clean

all,release:
	gcc test.c -o test.out
	gcc test_fork.c -o test_fork.out

debug:
	gcc -g test.c -o test.out
	gcc -g test_fork.c -o test_fork.out

clean:
	rm -rf *dSYM
	rm *.out