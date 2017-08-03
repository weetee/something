#!/usr/local/bin/python3
# -*- conding: UTF-8 -*-

def fib(num):
	a, b = 1, 1
	while (a < num):
		print(a, end=' ')
		a, b = b, a+b
	print()


if __name__ == "__main__":
	fib(100)
