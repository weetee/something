#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
		ExitError("Usage: %s <ip> <port>\n", argv[0]);

	int clnt_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (clnt_sockfd == -1)
		ExitError("socket error");

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(argv[2]);

	int ret = 0;
	ret = connect(clnt_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if (ret == -1)
		ExitError("connect error");

	char msg[1024];
	ssize_t str_len = read(clnt_sockfd, msg, sizeof(msg) - 1);
	if (str_len == -1)
		ExitError("read error");
	printf("Message from server : %s \n", msg);
	close(clnt_sockfd);

	exit(EXIT_SUCCESS);
}