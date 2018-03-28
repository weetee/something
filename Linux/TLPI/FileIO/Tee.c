#include <sys/stat.h>
#include <fcntl.h>
#include "../Lib/TlpiHead.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[])
{
	if ((argc != 2 && argc != 3) || strcmp(argv[1], "--help") == 0)
		UsageError("%s [-a] filename\n", argv[0]);

	int out_fd;
	if (strcmp(argv[1], "-a") == 0)
		out_fd = open(argv[2], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	else
		out_fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (out_fd == -1)
		ErrorExit("open file error");

	char buf[BUF_SIZE];
	ssize_t read_ret;
	while ((read_ret = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		if (write(out_fd, buf, read_ret) == -1)
			ErrorExit("write file error");
		if (write(STDOUT_FILENO, buf, read_ret) == -1)
			ErrorExit("write stdout error");
	}

	if (read_ret == -1)
		ErrorExit("read error");

	if (close(out_fd) == -1)
		ErrorExit("close error");

	exit(EXIT_SUCCESS);
}
