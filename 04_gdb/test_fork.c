#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/****************************************************************
 *  函数名称：查看有几个 “-” 输出,行缓冲
 *  创建日期：2022-07-16 18:59:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	int i;
	
	for(i = 0; i < 2; i++)
	{
		fork();
		printf("-");
		printf("ppid=%d, pid=%d, i=%d", getppid(), getpid(), i);
	}
	wait(NULL);
	wait(NULL);
	//printf("\n");
}

/*
-ppid=14230, pid=20356, i=0
-ppid=20356, pid=20359, i=1
-ppid=20356, pid=20358, i=0
-ppid=20358, pid=20360, i=1
-ppid=20356, pid=20358, i=0
-ppid=20356, pid=20358, i=1
-ppid=14230, pid=20356, i=0
-ppid=14230, pid=20356, i=1
*/

/****************************************************************
 *  函数名称：如何去掉行缓冲带来的影响
 *  创建日期：2022-07-16 18:59:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
	int i;
	
	for(i = 0; i < 2; i++)
	{
		fork();
		printf("-\n");
		printf("ppid=%d, pid=%d, i=%d \n", getppid(), getpid(), i);
	}
	wait(NULL);
	wait(NULL);
	printf("\n");
}

/****************************************************************
 *  函数名称：查看进程状态
 *  创建日期：2022-07-16 18:59:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
	int i;
	
	for(i = 0; i < 2; i++)
	{
		fork();
		printf("-");
		//printf("ppid=%d, pid=%d, i=%d \n", getppid(), getpid(), i);
		printf("ppid=%d, pid=%d, i=%d", getppid(), getpid(), i);
	}

	wait(NULL);
	wait(NULL);

	printf("\n");
}


int main(void)
{
	test01();

	// test02();

	// test03();
	return 0;
}