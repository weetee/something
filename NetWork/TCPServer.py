from socket import *

ser_port = 50500

ser_sock = socket(AF_INET, SOCK_STREAM)
ser_sock.bind(('', ser_port))
ser_sock.listen(1)

print 'The tcp server is ready to receive'
while True:
	con_sock, addr = ser_sock.accept()
	msg = con_sock.recv(1024)
	ret_msg = msg.upper()
	con_sock.send(ret_msg)
	con_sock.close()