#ifndef TLPI_HEAD_H
#define TLPI_HEAD_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "GetNum.h"
#include "ErrorFunctions.h"

typedef enum
{
    FALSE,
    TRUE
}Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))

#endif //TLPI_HEAD_H
