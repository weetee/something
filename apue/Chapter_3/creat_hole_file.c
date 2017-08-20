#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;

	if ((fd = open("hole_file.txt", O_RDWR|O_CREAT|O_TRUNC, FILE_MODE)) < 0)
	{
		err_sys("creat file error");
	}
	if (write(fd, buf1, 10) != 10)
	{
		err_sys("buf1 write error");
	}

	if (lseek(fd, 10000, SEEK_SET) == -1)
	{
		err_sys("lseek error");
	}

	if (write(fd, buf2, 10) != 10)
	{
		err_sys("buf2 write error");
	}

	lseek(fd, 0, SEEK_SET);
	int n;
	char buf[4096];
	while ((n = read(fd, buf, 4096)) > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
		{
			err_sys("write stdout error");
		}
	}
	printf("\n");
	exit(0);
}
