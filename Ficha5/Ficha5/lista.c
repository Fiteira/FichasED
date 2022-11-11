#include "lista.h"




LISTA *criarLista()
{
    LISTA *l=(LISTA*)malloc(sizeof(LISTA));
    l->Inicio=NULL;
    l->NEL=0;

}

ptELEMENTO criar_ELEMENTO()
{
    //printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    ptELEMENTO p=(ptELEMENTO)malloc(sizeof(ELEMENTO));
    p->Info=(ptTIPO_DADO)malloc(sizeof(TIPO_DADO));
    p->Prox=NULL;
    p->Ant=NULL;

    return p;
}

void inserir_elemento_ordenado(ptLISTA L, ptELEMENTO ele_novo)
{
    if (!L)return;

    ELEMENTO *novo=(ELEMENTO*)malloc(sizeof(ELEMENTO));
    novo->Prox=NULL;
    novo->Ant=NULL;
    novo->Info=ele_novo;

    if(!L->Inicio)
    {
        L->Inicio=ele_novo;
    }else
    {
        novo->Prox=L->Inicio;
        L->Inicio->Ant=novo;
        L->Inicio=novo->Info;
    }
    L->NEL++;
}

int elementos_iguais(ptELEMENTO a,ptELEMENTO b)
{
    return compararElementos(a,b);
}

int compararElementos(ptELEMENTO a,ptELEMENTO b)
{
   if(strcmp(a->Info->TEXTO,b->Info->TEXTO)==0)
   {
    return 1;
    }
    return 0;
}


ptELEMENTO remover_elemento(ptLISTA L, ptELEMENTO ele_remover)
{
    if(!L) return NULL;

    ELEMENTO *p=L->Inicio;
    int STOP=0;

    while(p && !STOP)
    {
        if(elementos_iguais(p->Info->TEXTO,ele_remover))
        {
            STOP=1;
        }
        else
        {
            p=p->Prox;
        }
    if(STOP)
    {
        if(!p->Ant)
        {
            p->Ant->Prox=p->Prox;
        }
        else if(!p->Prox)
        {
            p->Prox->Ant=p->Ant;
        }
        else
        {
            p->Ant->Prox=p->Prox;
            p->Prox->Ant=p->Ant;
        }
    }
    L->NEL--;
    return p;
    }
}

