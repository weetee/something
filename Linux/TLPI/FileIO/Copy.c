#include <sys/stat.h>
#include <fcntl.h>
#include "../TlpiHead.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char **argv)
{
	int in_fd, out_fd;
	char buf[BUF_SIZE];
	if (argc != 3 || strcmp(argv[1], "--help") == 0)
		UsageError("%s old_file new_file\n", argv[0]);

	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
		ErrorExit("open file %s", argv[1]);

	int open_flags = O_CREAT | O_WRONLY | O_TRUNC;
	mode_t file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	out_fd = open(argv[2], open_flags, file_perms);
	if (out_fd == -1)
		ErrorExit("open file %s", argv[2]);

	ssize_t num_read;
	while ((num_read = read(in_fd, buf, BUF_SIZE)) > 0)
	{
		if (write(out_fd, buf, num_read) != num_read)
			Fatal("couldn't write whole buffer");
	}
	if (num_read == -1)
		ErrorExit("read");
	if (close(in_fd) == -1)
		ErrorExit("close input");
	if (close(out_fd) == -1)
		ErrorExit("close output");

	exit(EXIT_SUCCESS);
}