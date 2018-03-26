import socket

HOST = '192.168.0.155'
PORT = 8888
MAX_BUFFSIZE = 1024
SOCK_ADDR = (HOST, PORT)

clisckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clisckt.connect(SOCK_ADDR)

while True:
	data = input('your data: ')
	if not data:
		break
	clisckt.send(data.encode('utf-8'))
	data = clisckt.recv(MAX_BUFFSIZE)
	if not data:
		break
	print(data.decode('utf-8'))

clisckt.close()
