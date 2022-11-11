#include "tipoDados.h"

PALAVRA *criarPalavra(char *txt)
{

    PALAVRA *p=(PALAVRA *)malloc(sizeof(PALAVRA));
    strcpy(p->TEXTO,txt);
    return p;
}

void mostrarPalavra(PALAVRA *Pla)
{
    if(!Pla)  return;

    printf("\n[%s]", Pla->TEXTO);

}
