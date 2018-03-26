#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "GetNum.h"

static void GnFail(const char *fun_name, const char *msg, const char *arg, const char *name)
{
	fprintf(stderr, "%s error", fun_name);
	if (name != NULL)
		fprintf(stderr, " (in %s)", name);
	fprintf(stderr, ": %s\n", msg);
	if (arg != NULL && *arg != '\0')
		fprintf(stderr, "	offending text: %s\n", arg);

	exit(EXIT_FAILURE);
}

static long GetNum(const char *fun_name, const char *arg, int flags, const char *name)
{
	long ret;
	char *end_ptr;
	int base;

	if (arg == NULL || *arg == '\0')
		GnFail(fun_name, "numm or empty string", arg, name);

	base = (flags & GN_ANY_BASE) ? 0 : (flags & GN_BASE_8) ? 8 : (flags & GN_BASE_16) ? 16 : 10;
	
	errno = 0;
	ret = strtol(arg, &end_ptr, base);
	if (errno != 0)
		GnFail(fun_name, "strtol() failed", arg, name);

	if (*end_ptr != '\0')
		GnFail(fun_name, "nonnumeric characters", arg,name);

	if ((flags & GN_NONNEG) && ret < 0)
		GnFail(fun_name, "negative value not allowed", arg, name);

	if ((flags & GN_GT_0) && ret < 0)
		GnFail(fun_name, "value must be > 0", arg, name);

	return ret;
}

long GetLong(const char *arg, int flags, const char *name)
{
	return GetNum("GetLong", arg, flags, name);
}

int GetInt(const char *arg, int flags, const char *name)
{
	long ret = GetNum("GetInt", arg, flags, name);
	if (ret > INT_MAX || ret < INT_MIN)
		GnFail("GetInt", "Integer out of range", arg, name);

	return (int)ret;
}
