#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


int main()
{
    LISTA *LP = criarLista();
    ELEMENTO *EL=criar_ELEMENTO();
    EL->Info=criarPalavra("TESTE");
    inserir_elemento_ordenado(LP,EL);


    return 0;
}
