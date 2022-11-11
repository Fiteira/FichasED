#include <stdio.h>
#include <stdlib.h>

#include "veiculo.h"
#include "fila.h"

int main()
{
    printf("Ficha4 - TP2 - 12-04-2022!\n");
    FILA *FESP = Criar_FILA();
    VEICULO *X = Criar_Ler_VEICULO();
    Add_FILA(FESP, X);
    X = Criar_Ler_VEICULO();
    Add_FILA(FESP, X);
    Mostrar_FILA(FESP);

    printf("----------------\n");
    VEICULO *K = Remover_FILA(FESP);
    if (K)
    {
        Mostrar_VEICULO(K);
        Destruir_VEICULO(K);
    }

    Gravar_Ficheiro_FILA(FESP, "FEspera.dat");
    Destruir_FILA(FESP);

    return 0;
}
