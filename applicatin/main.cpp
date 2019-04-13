#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(int args, char argv[] ) {
  //OPEN database
  sqlite3 *db;
  char *msgError = 0;
  int rc;
  
  OepnData = sqlite3_open("test.db", &db);
  
  if( OepnData ) {  //jika database tidak bisa dibuka maka akan keluar error sqlite3 
    fprintf(stderr, "database tidak dapat dibuka  ", sqlite3_errmsg(db));
    return(0);
  } else { //jika database berhasil dibuka maka akan ada pesan open successfully
    fprintf(stderr, "Opened database successfully\n");
  }
  //code open database selesai
  
  //code create table
  sql = "CREATE TABLE COMPANY("
    ID INT PRIMARY KEY NOT NULL,
    NAME TEXT NOT NULL,
    ADDRESS CHAR(50),
    SALARY REAL
  );";
  
  /*Execute SQL statement */
  exeSQL = sqlite3_exec(db, sql, callback, 0, &msgError);
  
  if(exeSQL != SQLITE_OK) {
    fprintf(stderr, "SQL error %s ",msgError);
    
  } else {
    fprintf(stderr, "table berhasil dibuat");
  }
  sqlite3_close(db);
  return 0;
}
