#!/usr/local/bin/python3
# -*- conding: UTF-8 -*-

user_names = []
name = input("Input your name: ")
user_names.append(name)

user_names.insert(0, "li")
user_names.insert(0, "wang")
user_names.insert(0, "ran")

for n in user_names:
	print(n)

#del user_names[-1]
#del_name = user_names.pop()
del_name = "li"
user_names.remove(del_name)
print("del name :", del_name)

print("\tother:")
for n in user_names:
	print(n)
