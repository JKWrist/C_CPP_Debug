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
	test_C(3);	/* ����������ý����¶δ��� */
}

void test_C(int c)
{
	char *p = (char *)c;
	*p = 'A';   /* �������c����һ�����õĵ�ֵַ����������䵼�¶δ��� */
	printf("%d: %s %d\n", c, __FUNCTION__, __LINE__);
}

/* SIGSEGV�źŵĴ�����������ջ����ӡ�����ĵ��ù�ϵ */
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

	/* ����SIGSEGV�źŵĴ����� */
	signal(SIGSEGV, DebugBacktrace);

	test_A(1);
	test_C(&a);
	return 0;
}

