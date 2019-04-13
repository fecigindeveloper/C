#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(int args, char argv[] ) {
  //OPEN database
  sqlite3 *db;
  char *msgError = 0;
  int rc;
  
  rc = sqlite3_open("test.db", &db);
  
  if( rc ) {  //jika database tidak bisa dibuka maka akan keluar error sqlite3 
    fprintf(stderr, "database tidak dapat dibuka  ", sqlite3_errmsg(db));
    return(0);
  } else { //jika database berhasil dibuka maka akan ada pesan open successfully
    fprintf(stderr, "Opened database successfully\n");
  }
  sqlite3_close(db);
  //code open database selesai
  
  //code create table
  sql = "CREATE TABLE COMPANY("
    ID INT PRIMARY KEY NOT NULL,
    NAME TEXT NOT NULL,
    ADDRESS CHAR(50),
    SALARY REAL
  );";
  
  /*Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &msgError);
  
  if(rc != SQLITE_OK) {
    fprintf(stderr, "SQL error %s ",msgError);
  }
    
}
