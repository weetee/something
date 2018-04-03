#define _GNU_SOURCE
#include <stdlib.h>
#include "../Lib/TlpiHead.h"

extern char **environ;

int main(int argc, char *argv[])
{
	clearenv(); 	//清空进程环境变量

	for (int i = 1; i < argc; ++i)
	{
		if (putenv(argv[i]) != 0)
			ErrorExit("putenv: %s", argv[i]);
	}

	if (setenv("GREET", "Hello World", 1) == -1)
		ErrorExit("setenv");

	unsetenv("BYE");

	for (char **ep = environ; *ep != NULL; ++ep)
		puts(*ep);

	exit(EXIT_SUCCESS);
}