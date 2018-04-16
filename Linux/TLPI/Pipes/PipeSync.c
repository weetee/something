#include "../Lib/TlpiHead.h"
#include "../Lib/Time.h"

int main(int argc, char *argv[])
{
	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		UsageError("%s sleep-time...\n", argv[0]);

	setbuf(stdout, NULL);

	printf("Start current time[%s]\n", GetCurrentTime("%T"));
	int fds[2];
	int ret = pipe(fds);
	if (ret == -1)
		ErrorExit("pipe error");

	int i = 0;
	for (i = 1; i < argc; ++i)
	{
		switch(fork())
		{
			case -1:
				ErrorExit("fork %d error", i);
			case 0:
				if (close(fds[0]) == -1)
					ErrorExit("close fds 0 error");
				sleep(GetInt(argv[i], GN_NONNEG, "sleep-time"));

				printf("time[%s] Child %d(PID=%ld) closing pipe\n", GetCurrentTime("%T"), i, (long)getpid());
				if (close(fds[1]) == -1)
					ErrorExit("close fds 1 error");
				_exit(EXIT_SUCCESS);
			default:
				break;
		}
	}
	//parent
	if (close(fds[1]) == -1)
		ErrorExit("parent close fds 1 error");
	int dummy;
	if (read(fds[0], &dummy, 1) != 0)
		Fatal("parent didn't get EOF");
	printf("time[%s] parent ready to go\n", GetCurrentTime("%T"));

	exit(EXIT_SUCCESS);
}