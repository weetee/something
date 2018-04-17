#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "./Utils/Util.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
		ExitError("Usage: %s <port>\n", argv[0]);
	int serv_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (serv_sockfd == -1)
		ExitError("socket error");

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	int ret = 0;
	ret = bind(serv_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if (ret == -1)
		ExitError("bind error");
	ret = listen(serv_sockfd, 5);
	if (ret == -1)
		ExitError("listen error");

	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_len;
	int clnt_sockfd = accept(serv_sockfd, (struct sockaddr *)&clnt_addr, &clnt_addr_len);
	if (clnt_sockfd == -1)
		ExitError("accept error");

	char *msg = "hello world";
	write(clnt_sockfd, msg, sizeof(msg));

	close(serv_sockfd);
	close(clnt_sockfd);

	exit(EXIT_SUCCESS);
}
