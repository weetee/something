#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../Utils/Util.h"

#define BUFF_SIZE	1024

int main(int argc, char *argv[])
{
	if (argc != 3)
		ExitError("Usage : %s <ip> <port>\n", argv[0]);

	int clnt_sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (clnt_sockfd == -1)
		ExitError("socket error");

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if (connect(clnt_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		ExitError("connect error");
	
	char buf[BUFF_SIZE];
	int str_len = 0;
	while (1)
	{
		fputs("input some message: ", stdout);
		fgets(buf, BUFF_SIZE, stdin);
		str_len = write(clnt_sockfd, buf, strlen(buf));
		int recv_len = 0;
		while (recv_len < str_len)
		{
			int recv_cnt = read(clnt_sockfd, &buf[recv_len], BUFF_SIZE-1);
			if (recv_cnt == -1)
				ExitError("read error");
			recv_len += recv_cnt;
		}
		buf[recv_len] = '\0';
		printf("Message from server : %s \n", buf);
	}

	close(clnt_sockfd);
	exit(EXIT_SUCCESS);
}