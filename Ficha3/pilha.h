#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "contentor.h"

typedef struct no
{
    CONTENTOR *info;
    struct no *prox;

}NO;

typedef struct
{
    NO *inicio;
    int nEl;

}PILHA;

PILHA *criarPilha();
void PUSH(PILHA *P,CONTENTOR *X);
void POP(PILHA *P);
CONTENTOR *TOPO(PILHA *P);
void mostrarPilha(PILHA *P);
void destruirPilha(PILHA *P);
int getTamanho(PILHA *P);
CONTENTOR *findContentor(PILHA *P,char *referencia);
CONTENTOR *fundo(PILHA *P);
CONTENTOR *pertence_Rec(PILHA *p,char *txt);
CONTENTOR *pertence_Rec_NOS(NO *p,char *txt);
#endif // PILHA_H_INCLUDED
