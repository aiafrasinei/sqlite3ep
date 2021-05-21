#include <stdio.h>
#include "sqlite3.h"

#include "utils.h"

sqlite3* init() {
    int rc; char* zErrMsg = 0;
    sqlite3* db = NULL;

    //rc = sqlite3_open(":memory:", &db);
    rc = sqlite3_open("test.db", &db);
	sql_errcheck(rc, zErrMsg);

    //create tables
    char *sql = "CREATE TABLE sections ( 'ID' INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE, 'NAME' TEXT)";
    sqlite3_exec_ec(db, sql, zErrMsg);

    sql = "CREATE TABLE section_types ( 'ID' INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE, 'TYPE' TEXT)";
	sqlite3_exec_ec(db, sql, zErrMsg);

    sql = "CREATE TABLE value_types ( 'ID' INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE, 'TYPE' TEXT)";
	sqlite3_exec_ec(db, sql, zErrMsg);

    sql = "INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'integer');\
    INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'float');\
    INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'string');";
    sqlite3_exec_ec(db, sql, zErrMsg);

    sql = "CREATE TABLE stacks ( 'ID' INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE, 'NAME' TEXT, 'SECTION_ID' INTEGER)";
    sqlite3_exec_ec(db, sql, zErrMsg);

    sql = "INSERT INTO stacks (ID, NAME, SECTION_ID) VALUES (NULL, 'default', 1)";
    sqlite3_exec_ec(db, sql, zErrMsg);

    sql = "CREATE TABLE stack_data ( 'ID' INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE, 'STACK_ID' INT, 'NAME' TEXT, 'VALUE' TEXT, 'VALUE_TYPE_ID' INTEGER)";
    sqlite3_exec_ec(db, sql, zErrMsg);

    //defaults
    sql = "INSERT INTO sections (ID, NAME) VALUES (NULL, 'default');";
	sqlite3_exec_ec(db, sql, zErrMsg);

    sql = "INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'default');\
    INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'var_decl');\
    INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'if');\
    INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'for');\
    INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'fun_call');\
    INSERT INTO section_types (ID, TYPE) VALUES (NULL, 'fun_decl');";
	sqlite3_exec_ec(db, sql, zErrMsg);

    return db;
}

int main(int argc, char *argv[])
{
    sqlite3 *db = init();

    sqlite3_close(db);
}
