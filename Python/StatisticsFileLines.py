#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import os
import os.path

path = input("please input dir name: ")

files = os.listdir(path)

def ReadFile(file):
	f = open(file, 'r')
	


