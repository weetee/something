#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include "../Utils/Util.h"

#define BUF_SIZE 2
#define EPOLL_SIZE 50

int main(int argc, char *argv[])
{
	if (argc != 2 || (strcmp(argv[1], "--help") == 0))
		ExitError("Usage: %s <port>\n", argv[0]);
	int serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		ExitError("socket error\n");

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	int port = GetInt(argv[1], GET_BASE_10, "main");
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		ExitError("bind error\n");
	if (listen(serv_sock, 5) == -1)
		ExitError("listen error\n");

	int ep_fd = epoll_create(EPOLL_SIZE);
	if (ep_fd == -1)
		ExitError("epoll_create error\n");
	
	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = serv_sock;
	if (epoll_ctl(ep_fd, EPOLL_CTL_ADD, serv_sock, &event) == -1)
		ExitError("epoll_ctl error\n");

	struct epoll_event *ep_event;	//保存epoll_wait中发生的事件
	ep_event = (struct epoll_event *)malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

	int clnt_sock;
	struct sockaddr_in clnt_adr;
	socklen_t clnt_adr_len = sizeof(clnt_adr);

	int ep_cnt = 0;
	char buf[BUF_SIZE];
	int i;
	int recv_len = 0;
	while (1)
	{
		ep_cnt = epoll_wait(ep_fd, ep_event, EPOLL_SIZE, -1);
		if (ep_cnt == -1)
		{
			printf("epoll_wait error\n");
			break;
		}
		printf("epoll wait\n");
		for (i = 0; i < ep_cnt; ++i)
		{
			if (ep_event[i].data.fd == serv_sock)
			{
				clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_len);
				if (clnt_sock == -1)
				{
					printf("accept error\n");
					continue;
				}
				event.events = EPOLLIN; 	//默认条件触发
				event.data.fd = clnt_sock;
				if (epoll_ctl(ep_fd, EPOLL_CTL_ADD, clnt_sock, &event) == -1)
				{
					printf("epoll_ctl error client sockfd:%d \n", clnt_sock);
					continue;
				}
				printf("connected client: %d\n", clnt_sock);
			}
			else
			{
				recv_len = read(ep_event[i].data.fd, buf, BUF_SIZE);
				if (recv_len == 0)
				{
					epoll_ctl(ep_fd, EPOLL_CTL_DEL, ep_event[i].data.fd, NULL);
					close(ep_event[i].data.fd);
					printf("closed client: %d\n", ep_event[i].data.fd);
				}
				else
				{
					write(ep_event[i].data.fd, buf, recv_len);
				}
			}
		}
	}

	close(serv_sock);
	close(ep_fd);

	exit(EXIT_SUCCESS);
}
