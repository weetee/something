import socket
import StringIO
import sys

class WSGIServer(object):
	address_family = socket.AF_INET
	socket_type = socket.SOCK_STREAM
	request_queue_size = 1

	def __init__(self, server_address):
		# create a listening socket
		self.listen_socket = listen_socket = socket.socket(
			self.address_family,
			self.socket_type
		)
		# allow to reuse the same address
		listen_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
		# bind
		listen_socket.bind(server_address)
		# activate
		listen_socket.listen(self.request_queue_size)
		# get server host name and port
		host, port = self.listen_socket.getsockname()[:2]
		self.server_name = socket.getfqdn(host)	#将点分十进制转换为域名
		self.sert_port = port
		# return headers set by Web framework/Web application
		self.headers_set = []

	def set_app(self, application):
		self.application = application

	def serve_forever(self):
		listen_socket = self.listen_socket
		while True:
			# new client connection
			self.client_connection, client_address = listen_socket.accept()
			# handle one request and close the client connection. Then
			# loop over to wait for another client connection
			self.handle_one_request()

	def handle_one_request(self):
		self.request_data = request_data = self.client_connection.recv(1024)
		# print fornatted request data a la 'curl-v'
		print(''.join(
			'< {line}\n'.format(line=line)
			for line in request_data.splitlines()
		))

		self.parse_request(request_data)

		# construct environment dictionary using request data
		env = self.get_environ()

		# it's time to call our application callable and get
		# back a result that will becone HTTP response body
		reuslt = self.application(env, self.start_response)

		# construct a response and send it back to the client
		self.finish_response(result)

	def parse_request(self, text):
		request_line = text.splitlines()[0]
		request_line = request_line.rstrip('\r\n')
		# break down the request line into components
		(self.request_method,	# GET
		 self.path,				# /hello
		 self.request_version	#HTTP/1.1
		) = request_line.split()

	def get_environ(self):
		env = {}
		# 



