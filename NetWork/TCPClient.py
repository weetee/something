from socket import *

ser_name = '127.0.0.1'
ser_port = 50500

cli_sock = socket(AF_INET, SOCK_STREAM)
cli_sock.connect((ser_name, ser_port))

msg = raw_input('Input some sentence:')
cli_sock.send(msg)
ret_msg = cli_sock.recv(1024)
print 'From Server: ', ret_msg
cli_sock.close()