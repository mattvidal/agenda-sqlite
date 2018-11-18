#include "interface.h"
#include "func_bd.h"

void main(void)
{
    setlocale(LC_ALL, "portuguese");

    //declarações de variáveis
    sqlite3 *db;
    int rc; // código de retorno
    sqlite3_stmt *stmt;
    int op;


    rc = sqlite3_open("agenda.db", &db);

    erroBancoDeDados(rc, db);

    criaTabelas(rc, db, stmt);

    while(1)
    {
        op = menu();

        switch (op)
        {
            case 1 :
                listarContatos(db);
            break;

            case 2 :
                inserirContato(db);
            break;

            case 3 :
                //removerContato();
            break;

            case 4 :
                //editarContato();
            break;

            case 5 :
                limparAgenda(rc, db, stmt);
            break;

            case 6 :
                exit(0);
            break;
        }
    }

    sqlite3_close(db);

}
