#ifndef FUNC_BD_H_INCLUDED
#define FUNC_BD_H_INCLUDED

#include "interface.h"
#include <sqlite3.h> // Header do SQLite (encontrado no caminho: /usr/include)

#define CONTATOS "CREATE TABLE IF NOT EXISTS contatos \
        (\
        nome VARCHAR(200),\
        id_contato INTEGER\
        );"

#define TELEFONES "CREATE TABLE IF NOT EXISTS telefones \
        (\
        pk_tel INTEGER,\
        id_contato INTEGER,\
        numero_tel VARCHAR(20)\
        )\
        ;"

#define CELULARES "CREATE TABLE IF NOT EXISTS celulares \
        (\
        pk_cel INTEGER,\
        id_contato INTEGER,\
        numero_cel VARCHAR(20)\
        )\
        ;"

#define EMAILS "CREATE TABLE IF NOT EXISTS emails \
        (\
        pk_email INTEGER,\
        id_contato INTEGER,\
        email VARCHAR(20)\
        )\
        ;"

//Inserção teste
#define INSERCAO "INSERT INTO contatos"

//Global
char *errmsg; // ponteiro de string para algum erro

void erroBancoDeDados(int rc, sqlite3* db); //verifica se o banco de dados foi aberto corretamente.

void criaTabelas(int rc, sqlite3 *db, sqlite3_stmt *stmt); //insere as tabelas pré-definidas em constantes.

void listarContatos(sqlite3 *db);

void inserirContato(sqlite3 *db);

#endif // FUNC_BD_H_INCLUDED
