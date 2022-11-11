#ifndef TIPODADOS_H_INCLUDED
#define TIPODADOS_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_PALAVRA 50

typedef struct
{
    char TEXTO[MAX_PALAVRA];

}PALAVRA,*ptPALAVRA;

PALAVRA *criarPalavra(char *txt);
void mostrarPalavra(PALAVRA *Pla);

#endif // TIPODADOS_H_INCLUDED
