#include "tipo_dados.h"

TIPO_DADO *criarPalavra(char *txt)
{

    TIPO_DADO *p=(TIPO_DADO *)malloc(sizeof(TIPO_DADO));
    strcpy(p->TEXTO,txt);
    return p;
}

void mostrarPalavra(TIPO_DADO *string)
{
    if(!string)  return;

    printf("\n[%s]", string->TEXTO);

}
