#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "tipo_dados.h"

typedef struct elemento
{
    TIPO_DADO *Info;
    struct elemento *Prox;
    struct elemento *Ant;

}ELEMENTO,*ptELEMENTO;


typedef struct lista
{
    ELEMENTO *Inicio;
    int NEL;
}LISTA,*ptLISTA;

LISTA *criarLista();
ptELEMENTO criar_ELEMENTO();
void inserir_elemento_ordenado(ptLISTA L, ptELEMENTO ele_novo);
ptELEMENTO remover_elemento(ptLISTA L, ptELEMENTO ele_remover);

#endif // LISTA_H_INCLUDED
