#include <fcntl.h>
#include <sys/stat.h>
#include "../Lib/TlpiHead.h"

int main()
{
	int new_fd = open("f_fcntl.txt", O_WRONLY | O_CREAT | O_EXCL, S_IWUSR | S_IRUSR);
	if (new_fd == -1)
		ErrorExit("open file error");
	int flags = fcntl(new_fd, F_GETFL);
	if (flags == -1)
		ErrorExit("fcntl get error");

	int acc_mode = flags & O_ACCMODE;
	if (acc_mode == O_RDONLY || acc_mode == O_RDWR)
		printf("we can read file\n");
	if (acc_mode == O_WRONLY || acc_mode == O_RDWR)
		printf("we can write file\n");

	if (flags & O_APPEND)
		printf("before this file have O_APPEND flag\n");
	
	flags |= O_APPEND;
	if (fcntl(new_fd, F_SETFL, flags) == -1)
		ErrorExit("fcntl set error");
	if (flags & O_APPEND)
		printf("after this file have O_APPEND flag\n");

	if (close(new_fd) == -1)
		ErrorExit("close error");

	exit(EXIT_SUCCESS);
}
