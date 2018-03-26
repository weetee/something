import socket
from time import ctime

# UDP服务器创建流程
# 创建套接字
# 绑定服务器套接字
# 服务器开始循环
# 接收/发送数据
# 关闭服务器套接字

HOST = ''
PORT = 8888
MAX_BUFSIZE = 1024
SOCK_ADDR = (HOST, PORT)

udpsckt = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udpsckt.bind(SOCK_ADDR)

while True:
	print('waiting for message...')
	data, addr = udpsckt.recvfrom(MAX_BUFSIZE)
	print(data)
	print(addr)
	print(ctime())
	udpsckt.sendto(b'[%s] %s' % (bytes(ctime(), 'utf-8'), data), addr)
	print ('...received from and returned to:', addr)

udpsckt.close()
