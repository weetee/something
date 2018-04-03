#include <setjmp.h>
#include "../Lib/TlpiHead.h"

static jmp_buf env;

static void Func2()
{
	longjmp(env, 2);
}

static void Func1(int argc)
{
	if (argc == 1)
		longjmp(env, 1);
	Func2();
}

int main(int argc, char *argv[])
{
	switch (setjmp(env))
	{
		case 0:
			printf("Calling Func1() after initial setjmp()\n");
			Func1(argc);
			break;
		case 1:
			printf("jumped back from Func1()\n");
			break;
		case 2:
			printf("jumped back from Func2()\n");
			break;
	}
	exit(EXIT_SUCCESS);
}