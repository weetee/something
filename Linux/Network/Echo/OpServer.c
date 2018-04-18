#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include "../Utils/Util.h"

int main(int argc, char *argv[])
{
	if (argc !=2 || strcmp(argv[1], "--help") == 0 )
		ExitError("Usage: %s <port>\n", argv[0]);
	int serv_sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sockfd == -1)
		ExitError("socket error");

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htnol(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	int ret = bind(serv_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if (ret == -1)
		ExitError("bind error");
	ret = listen(serv_sockfd, 5);
	if (ret == -1)
		ExitError("listen error");

	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_len = sizeof(clnt_addr);
	int clnt_sockfd;

	if (close(serv_sockfd) == -1)
		ExitError("close error");
	exit(EXIT_SUCCESS);
}
