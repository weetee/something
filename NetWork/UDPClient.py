from socket import *

ser_name = '127.0.0.1'
ser_port = 50500

cli_sock = socket(AF_INET, SOCK_DGRAM)

msg = raw_input('Input some sentence:')
cli_sock.sendto(msg, (ser_name, ser_port))
ret_msg, ser_addr = cli_sock.recvfrom(2048)

print(ret_msg)

cli_sock.close()
