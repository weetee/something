#include "apue.h"

static void SigUsr(int);

int main()
{
	if (signal(SIGUSR1, SigUsr) == SIG_ERR)
	{
		err_sys("Can't catch SIGUSR1");
	}
	if (signal(SIGUSR2, SigUsr) == SIG_ERR)
	{
		err_sys("Can't catch SIGUSR2");
	}

	while(1)
	{
		pause();
	}
	exit(0);
}

static void SigUsr(int p_signo)
{
	fprintf(stderr, "in SigUsr\n");
	if (p_signo == SIGUSR1)
	{
		fprintf(stderr, "received SIGUSR1\n");
	}
	else if (p_signo == SIGUSR2)
	{
		fprintf(stderr, "received SIGUSR2\n");
	}
	else
	{
		err_dump("received signal %d\n", p_signo);
	}
}
