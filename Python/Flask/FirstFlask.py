#!/usr/bin/python
# -*- coding: UTF-8 -*-

from flask import Flask, render_template
from flask_script import Manager

app = Flask(__name__)
mgr = Manager(app)

@app.route('/') #修饰器，把index()函数注册为程序根地址的处理程序
def index():
	return render_template('index.html')	#返回值称为响应

@app.route('/user/<name>')
def user(name):
	return render_template('user.html', name=name)

if __name__ == '__main__':
	mgr.run()