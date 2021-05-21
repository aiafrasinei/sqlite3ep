#ifndef SQLITE3EP_UTILS_H_INCLUDED
#define SQLITE3EP_UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"


//sql related
void sql_errcheck_msg(int rc, char *zErrMsg, char *msg);

void sql_errcheck(int rc, char *zErrMsg);

int sqlite3_exec_ec(sqlite3* db, char *sql, char* zErrMsg);

#endif
