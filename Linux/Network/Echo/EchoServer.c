#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../Utils/Util.h"

#define BUFF_SIZE	1024

int main(int argc, char *argv[])
{
	if (argc != 2)
		ExitError("Usage : %s <port> \n", argv[0]);

	int serv_sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sockfd == -1)
		ExitError("socket error");
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	int ret = 0;

	ret =  bind(serv_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if (ret == -1)
		ExitError("bind error");
	ret = listen(serv_sockfd, 5);
	if (ret == -1)
		ExitError("listen error");

	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_len = sizeof(clnt_addr);
	int con_sockfd;
	char buf[BUFF_SIZE];
	ssize_t str_len;
	while (1)
	{
		con_sockfd = accept(serv_sockfd, (struct sockaddr *)&clnt_addr, &clnt_addr_len);
		if (con_sockfd == -1)
			ExitError("accept error");
		printf("Connected client fd[%d] \n", con_sockfd);
		
		while ((str_len = read(con_sockfd, buf, BUFF_SIZE)) != 0)
		{
			if (str_len == -1)
				ExitError("read error");
			write(con_sockfd, buf, str_len);
		}
		close(con_sockfd);
	}

	ret = close(serv_sockfd);
	if (ret == -1)
		ExitError("close error");
	printf("server exit\n");
	exit(EXIT_SUCCESS);
}