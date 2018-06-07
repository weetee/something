#include "Util.h"
#include <stdarg.h>
#include <string.h>
#include <limits.h>

#define BUFF_SIZE 500

static void Terminate()
{
	exit(EXIT_FAILURE);
}

//发生错误时输出信息
static void OccurFail(const char *fmt, ...)
{
	va_list arg_lst;
	va_start(arg_lst, fmt);

	char msg[BUFF_SIZE];
	vsnprintf(msg, BUFF_SIZE, fmt, arg_lst);
	fputs(msg, stderr);
	fflush(stderr);

	va_end(arg_lst);
	Terminate();
}

static void OutputMsg(const char *format, va_list lst)
{
	char buf[BUFF_SIZE], usr_msg[BUFF_SIZE];
	vsnprintf(usr_msg, BUFF_SIZE, format, lst);
	snprintf(buf, BUFF_SIZE, "Error: %s", usr_msg);
	fputs(buf, stderr);
	fflush(stderr);
}

void ExitError(const char *format, ...)
{
	va_list arg_lst;
	va_start(arg_lst, format);
	OutputMsg(format, arg_lst);
	va_end(arg_lst);

	Terminate();
}

static long GetNum(const char *fun_name, const char *arg, int flags, const char *name)
{
	if (arg == NULL || *arg == '\0')
		OccurFail("%s error: from function %s, arg maybe NULL\n", fun_name, name);

	char *end_ptr;

	int base = (flags & GET_BASE_ANY) ? 0 : ((flags & GET_BASE_8) ? 8 : ((flags & GET_BASE_16) ? 16 : 10));
	long ret_num = strtol(arg, &end_ptr, base);
	if (*end_ptr != '\0')
		OccurFail("GetInt strtol return error\n");
	return ret_num;
}

int GetInt(const char *arg, int flags, const char *name)
{
	long ret = GetNum("GetInt", arg, flags, name);
	if (ret > INT_MAX || ret < INT_MIN)
		OccurFail("GetInt result integer out of range, arg:%s function name:%s\n", arg, name);
	return (int)ret;
}

long GetLong(const char *arg, int flags, const char *name)
{
	return GetNum("GetLong", arg, flags, name);
}