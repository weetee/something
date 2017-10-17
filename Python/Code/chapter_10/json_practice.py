#!/usr/local/bin/python3
# -*- coding: UTF-8 -*-

import json

numbers = []
def read_data():
	usage_str = "Input some numbers: "
	while True:
		number = input(usage_str)
		if number == "q":
			break
		number = int(number)
		numbers.append(number)

	usage_str = "Input a save file: "
	file_name = input(usage_str)
	return file_name

def write_json(file_name, data):
	with open(file_name, "w") as file_obj:
		json.dump(numbers, file_obj)

def read_json(file_name):
	with open(file_name) as file_obj:
		data = json.load(file_obj)
	return data

file_name = read_data()
write_json(file_name, numbers)
file_data = read_json(file_name)
print(file_data)
