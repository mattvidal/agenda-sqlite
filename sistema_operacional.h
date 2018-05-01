#ifndef SISTEMA_OPERACIONAL_H_INCLUDED
#define SISTEMA_OPERACIONAL_H_INCLUDED

#if linux
#define limpabuffer() __fpurge(stdin)
#define limpatela() system("clear")
#define pausa() printf("Aperte qualquer tecla para retornar...");getchar()

#elif WIN32
#define limpabuffer() fflush(stdin)
#define limpatela() system("cls")
#define pausa() system("pause")
#endif

#endif // SISTEMA_OPERACIONAL_H_INCLUDED
