#include "utils.h"


void sql_errcheck_msg(int rc, char *zErrMsg, char *msg)
{
	if (rc != SQLITE_OK) {
		printf("Exit code: %d  SQL error: %s\n", rc, zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		printf("%s\n", msg);
	}
}

void sql_errcheck(int rc, char *zErrMsg)
{
	if (rc != SQLITE_OK) {
		printf("Exit code: %d  SQL error: %s\n", rc, zErrMsg);
		sqlite3_free(zErrMsg);
	}
}

int sqlite3_exec_ec(sqlite3* db, char *sql, char* zErrMsg)
{
	int rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
	sql_errcheck(rc, zErrMsg);

	return rc;
}
