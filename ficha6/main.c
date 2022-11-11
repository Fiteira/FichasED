#include <stdio.h>
#include <stdlib.h>

#include "Hashing.h"

int main()
{
    printf("Hello world!\n");
    Hashing *HAS = Criar_Hashing();

    for (int i = 0; i < 4; i++)
    {
        char NOME[30];
        sprintf(NOME, "foncalo_%d", i);
        PESSOA *P = Criar_Pessoa(NOME, aleatorio(10, 90), 56+i, 180);

        Add_Hashing(HAS, P);
    }

    Gravar_Ficheiro_Binario(HAS, "dados.dat");
    PESSOA *X = Pesquisar_Pessoa_NOME(HAS, "GoncALO_2");
    remover_elemento_hashing(HAS, X);
    Mostrar_Hashing(HAS);

    Destruir_Hashing(HAS);
    return 0;
}
