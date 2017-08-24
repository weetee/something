#include "apue.h"

static void SingleOutput(char *str);

int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0)
	{
		SingleOutput("output from child\n");
	}
	else
	{
		SingleOutput("output from parent\n");
	}
	exit(0);
}

static void SingleOutput(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL); //设置不使用缓存
	for (prt = str; (c = *ptr++) != 0)
	{
		putc(c, stdout);
	}
}
