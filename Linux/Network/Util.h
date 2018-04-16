#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdarg.h>

static void Terminate()
{
	exit(EXIT_FAILURE);
}

static void OutputMsg(const char *format, va_list lst)
{
	#define BUFF_SIZE 500
	char buf[BUFF_SIZE], usr_msg[BUFF_SIZE];
	vsnprintf(usr_msg, BUFF_SIZE, format, lst);
	snprintf(buf, BUFF_SIZE, "Error: %s", usr_msg);
	fputs(buf, stderr);
	fflush(stderr);
}

static void ExitError(const char *format, ...)
{
	va_list arg_lst;
	va_start(arg_lst, format);
	OutputMsg(format, arg_lst);
	va_end(arg_lst);

	Terminate();
}

#endif //UTIL_H