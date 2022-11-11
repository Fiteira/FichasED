#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"

typedef struct no_fila
{
    VEICULO *Info;
    struct no_fila *Prox;
}NOF;

typedef struct
{
    NOF *Inicio;
    int NEL;
}FILA;

FILA *Criar_FILA();
void Destruir_FILA(FILA *F);
void Add_FILA(FILA *F, VEICULO *X);
VEICULO *Remover_FILA(FILA *F);
void Mostrar_FILA(FILA *F);
int Get_Espera(FILA *F);
void Gravar_Ficheiro_FILA(FILA *F, char *nome_ficheiro);

#endif // FILA_H_INCLUDED
