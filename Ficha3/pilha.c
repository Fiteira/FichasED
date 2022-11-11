#ifndef PILHA_C_INCLUDED
#define PILHA_C_INCLUDED
#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

PILHA *criarPilha()
{
    PILHA *P=(PILHA *)malloc(sizeof(PILHA));

    P->inicio=NULL;
    P->nEl=0;

    return P;
}
void PUSH(PILHA *P,CONTENTOR *X)
{
    NO *nozito =(NO *)malloc(sizeof(NO));
    nozito->info=X;
    nozito->prox=P->inicio;
    P->inicio=nozito;
    P->nEl++;
}

void POP(PILHA *P)
{
    if(!P)return;
    if(!P->inicio)return;

    CONTENTOR *aux=P->inicio->info;
    NO *no_aux=P->inicio->prox;
    free(P->inicio->info);
    P->inicio=no_aux;
    P->nEl--;
}

CONTENTOR *TOPO(PILHA *P)
{
    if(!P) return NULL;
    if(!P->inicio) return NULL;
    return P->inicio->info;
}

void mostrarPilha(PILHA *P)
{
    if(!P)return;
    NO *ajuda=P->inicio;
    while(ajuda)
    {

        mostrarContentor(ajuda->info);
        printf("\n-----------\n");
        ajuda=ajuda->prox;
    }
}

CONTENTOR *fundo(PILHA *P)
{
    if(!P || !P->inicio) return NULL;

    NO *Q=P->inicio;
    while(Q->prox !=NULL)
    {
        Q=Q->prox;

    }
    return Q->info;
}

void destruirPilha(PILHA *P)
{

    if(!P)return;
    NO *anterior;
    NO *percorre=P->inicio;

    while(percorre)
    {
            anterior=percorre;
            percorre=percorre->prox;
            free(anterior->info);
            free(anterior);
    }
    P->inicio=NULL;
    P->nEl=0;
}

int getTamanho(PILHA *P)
{
    if(!P)return -1;
    return P->nEl;
}

CONTENTOR *pertence_Rec(PILHA *p,char *txt)
{
    if(!p) return;

    return  pertence_Rec_NOS(p->inicio,txt);
}

CONTENTOR *pertence_Rec_NOS(NO *p,char *txt)
{
    if(!p)return NULL;

    if(stricmp(p->info->referencia,txt)==0)
        return p->info;

    return pertence_Rec_NOS(p->prox,txt);
}



#endif // PILHA_C_INCLUDED
