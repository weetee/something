#include "Time.h"

#define BUF_SIZE 1024

char *GetCurrentTime(const char *fmt)
{
	time_t now = time(NULL);
	struct tm *s_tm;
	s_tm = localtime(&now);
	if (s_tm == NULL)
		return NULL;

	static char buf[BUF_SIZE];
	size_t len = strftime(buf, BUF_SIZE, (fmt != NULL) ? fmt : "%c", s_tm);
	return (len == 0) ? NULL : buf;
}
