import socket

# UDP客户端
# 创建套接字
# 通信循环
# 发送/接收数据
# 关闭套接字

HOST = '192.168.0.155'
PORT = 8888
MAX_BUFSIZE = 1024
SOCK_ADDR = (HOST, PORT)

udp_cli_sckt = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
	data = input('your data: ')
	if not data:
		break
	udp_cli_sckt.sendto(data.encode('utf-8'), SOCK_ADDR)
	data, addr = udp_cli_sckt.recvfrom(MAX_BUFSIZE)
	if not data:
		break
	print(data.decode('utf-8'))

udp_cli_sckt.close()
