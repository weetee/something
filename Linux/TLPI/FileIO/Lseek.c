#include <fcntl.h>
#include "../TlpiHead.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
		UsageError("%s filename\n", argv[0]);

	int fd = open(argv[1], O_RDWR);
	if (fd == -1)
		ErrorExit("open file %s", argv[1]);

	off_t cur_off= lseek(fd, 0, SEEK_CUR);
	if (cur_off == -1)
		ErrorExit("lseek file %s", argv[1]);
	printf("current file offset = %d\n", cur_off);

	off_t new_off = lseek(fd, 3, SEEK_END);
	if (new_off == -1)
		ErrorExit("new lseek file end faild.");
	ssize_t wrt_ret = write(fd, "e", 1);
	if (wrt_ret == -1)
		ErrorExit("write file faild");

	int c_ret = close(fd);
	if (c_ret == -1)
		ErrorExit("close file faild");
	exit(EXIT_SUCCESS);
}