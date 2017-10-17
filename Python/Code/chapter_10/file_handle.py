#!/usr/local/bin/python3
# -*- coding: UTF-8 -*-

usage_str = "Please input userdata filename: "
file_name = input(usage_str)
file_name += ".txt"


def file_handle(file_name):
	with open(file_name) as file_obj:
		for line in file_obj:
			print(line.rstrip())

file_handle(file_name)
