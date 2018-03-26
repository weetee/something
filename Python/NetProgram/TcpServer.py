import socket
from time import ctime

HOST = ''
PORT = 8888
MAX_BUFFSIZE = 1024
SOCK_ADDR = (HOST, PORT)

sckt = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sckt.bind(SOCK_ADDR)
sckt.listen(5)

try:
	while True:
		print("waiting for connection ...")
		clisckt, cliaddr = sckt.accept()
		print("connection from: ", cliaddr)
		# 开始接收数据
		while True:
			data = clisckt.recv(MAX_BUFFSIZE)
			if not data:
				break

			clisckt.send(b'[%s] %s' % (bytes(ctime(), 'utf-8'), data))

		clisckt.close()
except (EOFError, KeyboardInterrupt):
	print("server end~!")
	sckt.close()
