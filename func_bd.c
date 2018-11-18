#include "func_bd.h"

void controlaErros(sqlite3* db)
{
    fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
    return sqlite3_errcode(db);

}

void erroBancoDeDados(int rc, sqlite3* db)
{
    if(rc)
    {
        fprintf(stderr, "Não é possível abrir o banco de dados: %s\n", sqlite3_errmsg(db));
        exit(0);
    }

}

void criaTabelas(int rc, sqlite3 *db, sqlite3_stmt *stmt)
{
    int cont = 0;

    for(cont = 0; cont < 4; cont++)
    {
        switch (cont)
        {
            case 0 :
                sqlite3_prepare_v2(db, CONTATOS, -1, &stmt, NULL);
            break;

            case 1 :
                sqlite3_prepare_v2(db, TELEFONES, -1, &stmt, NULL);
            break;

            case 2 :
                sqlite3_prepare_v2(db, CELULARES, -1, &stmt, NULL);
            break;

            case 3 :
                sqlite3_prepare_v2(db, EMAILS, -1, &stmt, NULL);
            break;

        }

        rc = sqlite3_step(stmt);

        if (rc != SQLITE_DONE)
        {
            printf("Erro ao inserir dados: %s\n", sqlite3_errmsg(db));
        }

        sqlite3_finalize(stmt);
    }
}

int callback(void *arg, int argc, char **argv, char **colName) {                                /* 1 */

    int i;
    //char controle[1] = "0";

    for(i=0; i<argc; i++)
    {
        printf("%s = %s\t", colName[i], argv[i] ? : "NULL");
    }



    printf("\n");
    return 0;
}

void listarContatos(sqlite3 *db)
{
    limpatela();
    header();

    if (sqlite3_exec(db, "SELECT * FROM contatos ORDER BY nome;", callback, NULL, &errmsg) != SQLITE_OK)
    {
        controlaErros(db);
        sqlite3_free(errmsg);
    }

    /*if (sqlite3_exec(db, "SELECT count(id_contato) FROM contatos;", callback, NULL, &errmsg) != SQLITE_OK)
    {
        controlaErros(db);
        sqlite3_free(errmsg);
    }*/

    limpabuffer();
    pausa();
    limpatela();
}

void inserirContato(sqlite3 *db)
{
    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(db, "INSERT INTO contatos VALUES ('Tom', 10);", -1, &stmt, NULL);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        controlaErros(db);
    }
    sqlite3_finalize(stmt);

}
