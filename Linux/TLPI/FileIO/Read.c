#include "../TlpiHead.h"

#ifndef BUF_SIZE
#define BUF_SIZE 10
#endif

int main()
{
	char buf[BUF_SIZE + 1];
	ssize_t read_ret;
	read_ret = read(STDIN_FILENO, buf, BUF_SIZE);
	if (read_ret == -1)
		ErrorExit("read stdin");
	buf[read_ret] = '\0';
	printf("the input is : %s\n", buf);
	exit(EXIT_SUCCESS);
}
