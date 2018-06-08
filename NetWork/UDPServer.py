from socket import *

ser_port = 50500
ser_sock = socket(AF_INET, SOCK_DGRAM)

ser_sock.bind(('', ser_port))
print "The udp server is ready to receive"
while True:
	msg, cli_addr = ser_sock.recvfrom(2048)
	print "from client message: %s" % msg
	ret_msg = msg.upper()
	ser_sock.sendto(ret_msg, cli_addr)