#include <stdarg.h>
#include "ErrorFunctions.h"
#include "TlpiHead.h"
#include "enames.c.inc"

static void Terminate(Boolean use_exit3)
{
	char *str;
	str = getenv("EF_DUMPCORE");

	if (str != NULL && *str != '\0')
		abort();
	else if (use_exit3)
		exit(EXIT_FAILURE);
	else
		_exit(EXIT_FAILURE);
}

static void OutputError(Boolean use_err, int err, Boolean flush_stdout, const char *format, va_list ap)
{
	#define BUFF_SIZE 500
	char buf[BUFF_SIZE], user_msg[BUFF_SIZE], err_txt[BUFF_SIZE];
	vsnprintf(user_msg, BUFF_SIZE, format, ap);
	if (use_err)
		snprintf(err_txt, BUFF_SIZE, " [%s %s]", (err > 0 && err <= MAX_ENAME) ? ename[err] : "?unknown?", strerror(err));
	else
		snprintf(err_txt, BUFF_SIZE, ":");

	snprintf(buf, BUFF_SIZE, "Error%s %s\n", err_txt, user_msg);
	if (flush_stdout)
		fflush(stdout);
	fputs(buf, stderr);
	fflush(stderr);
}

void ErrorMsg(const char *format, ...)
{
	va_list arg_list;
	int save_errno;

	save_errno = errno;

	va_start(arg_list, format);
	OutputError(TRUE, errno, TRUE, format, arg_list);
	va_end(arg_list);

	errno = save_errno;
}

void ErrorExit(const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);
	OutputError(TRUE, errno, TRUE, format, arg_list);
	va_end(arg_list);

	Terminate(TRUE);
}

void ErrorExitNoRefresh(const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);
	OutputError(TRUE, errno, FALSE, format, arg_list);
	va_end(arg_list);

	Terminate(FALSE);
}

void ErrorExitNum(int errnum, const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);
	OutputError(TRUE, errnum, TRUE, format, arg_list);
	va_end(arg_list);

	Terminate(TRUE);
}

void Fatal(const char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);
	OutputError(FALSE, 0, TRUE, format, arg_list);
	va_end(arg_list);

	Terminate(TRUE);
}

void UsageError(const char *format, ...)
{
	va_list arg_list;
	
	fflush(stdout);

	fprintf(stderr, "Usage: ");
	va_start(arg_list, format);
	vfprintf(stderr, format, arg_list);
	va_end(arg_list);

	fflush(stderr);
	exit(EXIT_FAILURE);
}

void CmdLineError(const char *format, ...)
{
	va_list arg_list;

	fflush(stdout);

	fprintf(stderr, "Command-line usage error: ");
	va_start(arg_list, format);
	vfprintf(stderr, format, arg_list);
	va_end(arg_list);

	fflush(stderr);
	exit(EXIT_FAILURE);
}
