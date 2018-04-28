#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#if linux
#define limpabuffer() __fpurge(stdin)
#define limpatela() system("clear")
#define pausa() getchar()

#elif WIN32
#define limpabuffer() fflush(stdin)
#define limpatela() system("cls")
#define pausa() system("pause")
#endif

int main(int argc, char* argv[]){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   rc = sqlite3_open("test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_close(db);

}
