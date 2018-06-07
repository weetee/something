#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>

// GetInt GetLong 参数base的值
#define GET_BASE_ANY 0000
#define GET_BASE_8	 0100
#define GET_BASE_10	 0200
#define GET_BASE_16  0400

void ExitError(const char *format, ...);

int GetInt(const char *arg, int flags, const char *name);

long GetLong(const char *arg, int flags, const char *name);

#endif //UTIL_H
