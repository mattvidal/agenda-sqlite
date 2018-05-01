#include "interface.h"

void header ()
{
    printf("Agenda de contatos\n\n");

}
int menu()
{
    char op[1] = "Z";

    int val;

    header();

    printf("1- Listar contatos (em ordem alfabética).\n");
    printf("2- Inserir contato.\n");
    printf("3- Remover contato.\n");
    printf("4- Editar contato (inserir/remover telefone, inserir/remover email).\n");
    printf("5- Limpar toda a agenda.\n");
    printf("6- Sair.\n\n");

    printf("Escolha uma opção: \n");

    while(1)
    {
        scanf("%s", op);
        val = atoi(op);

        if(val != NULL)
        {
            break;
        }
    }

    return val;
}
