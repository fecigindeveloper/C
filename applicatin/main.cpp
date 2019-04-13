#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main(int args, char argv[] ) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  
  rc = sqlite3_open("test.db", &db);
  
  if( rc ) {  //jika database tidak bisa dibuka maka akan keluar error sqlite3 
    fprintf(stderr, "Can't Open Database ", sqlite3_errmsg(db));
    return(0);
  } else { //jika database berhasil dibuka maka akan ada pesan open successfully
    fprintf(stderr, "Opened database successfully\n");
  }
  sqlite3_close(db);
}
