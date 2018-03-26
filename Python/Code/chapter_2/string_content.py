#!/usr/local/bin/python3
# -*- conding: UTF-8 -*-

first_str = "\thello"
last_str = "python\n"

full_str = first_str + " " + last_str

#full_str = full_str.rstrip()	#删除字符串末尾空白
#full_str = full_str.lstrip()	#删除字符串开头空白
full_str = full_str.strip()	#删除两端的空白

num = 20
full_str = full_str + " " + str(num)	#str将非字符串值表示为字符串

print(full_str.title())
print(full_str.lower())
print(full_str.upper())
print(full_str)
