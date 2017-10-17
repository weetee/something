#!/usr/local/bin/python3
# -*- coding: UTF-8 -*-

usage_str = "Please input userdata filename: "
file_name = input(usage_str)
file_name += ".txt"

usage_str = "Please input savedata filename: "
save_file = input(usage_str)
save_file += ".txt"

def read_file(file_name):
	with open(file_name) as file_obj:
		file_lines = file_obj.readlines()
	return file_lines

def write_file(w_file, data):
	with open(w_file, "w") as file_obj:
		for line in data:
			file_obj.write(line)

file_data = read_file(file_name)
write_file(save_file, file_data)
