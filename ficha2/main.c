#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#include "tipoDados.h"
#include "lista.h"

int main()
{
    printf("Ficha 2: Listas TP2!\n");
    LISTA *LP = criarLista("PT");
    ELEMENTO *EL=criarElemento();
    lerFicherio(LP, "dados.txt");
    addFim(LP,EL);
    remover_ultimo(LP);
    mostrarLista(LP);
    printf("\n\n\n---Lista inversa---\n");
    //mostrar_inversa_v2(LP);
    mostrar_inversa_v2(LP);
    printf("\n\n\n---Lista ordenada---\n");
    ordenar_lista_v1(LP);
    mostrarLista(LP);
    exportarFicherio(LP, "copia.txt");
    printf("\n \n[%d]",elementosRepetidosV2(LP));


    destruirLista(LP,1);

    return 0;
}
