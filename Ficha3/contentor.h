#ifndef CONTENTOR_H_INCLUDED
#define CONTENTOR_H_INCLUDED

#define MAX_CONTEUDO 81
#define MAX_ORIGEM 31
#define MAX_DESTINO 16
#define MAX_CLIENTE 81
#define MAX_REFERENCIA 16

#include <time.h>

typedef struct
{
    int ano, mes, dia;
    int hora, min, seg;
}DATA;

typedef struct
{
    char conteudo[MAX_CONTEUDO];
    char origem[MAX_ORIGEM];
    char destino[MAX_DESTINO];
    char cliente[MAX_CLIENTE];
    DATA data_ent;
    float tonelagem;
    char referencia[MAX_REFERENCIA];

}CONTENTOR;

CONTENTOR *criarContentor(char *conteudo,char *cliente,char *origem,char *destino);
void mostrarContentor(CONTENTOR *x);


#endif // CONTENTOR_H_INCLUDED
