#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>
 
void test_A(int a);
void test_B(int b);
void test_C(int c);

void test_A(int a)
{
	printf("%d: %s %d\n", a, __FUNCTION__, __LINE__);
	test_B(2);
}

void test_B(int b)
{
	printf("%d: %s %d\n", b, __FUNCTION__, __LINE__);
	test_C(3);	/* 这个函数调用将导致段错误 */
}

void test_C(int c)
{
	char *p = (char *)c;
	*p = 'A';   /* 如果参数c不是一个可用的地址值，则这条语句导致段错误 */
	printf("%d: %s %d\n", c, __FUNCTION__, __LINE__);
}

/* SIGSEGV信号的处理函数，回溯栈，打印函数的调用关系 */
void DebugBacktrace(void)
{
#define SIZE 100
	void *array[SIZE];
	int size, i;
	char **strings;
	fprintf (stderr, "\nSegmentation fault\n");
	size = backtrace (array, SIZE);
	fprintf (stderr, "Backtrace (%d deep):\n", size);
	strings = backtrace_symbols (array, size);
	for (i = 0; i < size; i++)
		fprintf (stderr, "%d: %s\n", i, strings[i]);
	free (strings);
	exit(-1);
}

int main(int argc, char **argv)
{
	char a;

	/* 设置SIGSEGV信号的处理函数 */
	signal(SIGSEGV, DebugBacktrace);

	test_A(1);
	test_C(&a);
	return 0;
}

