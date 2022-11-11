#include <stdio.h>
#include <stdlib.h>

#include "contentor.h"
#include "pilha.h"
#include "uteis.h"

int main()
{
    printf("Porto Leixoes!\n");
    PILHA *P_Leixoes=criarPilha();
    mostrarPilha(P_Leixoes);

    char conteudo[MAX_CONTEUDO];
    char origem[MAX_ORIGEM];
    char destino[MAX_DESTINO];
    char cliente[MAX_CLIENTE];

    //mostrarContentor(fundo(P_Leixoes));
    CONTENTOR *X;

    for(int i=0;i<10;i++)
    {
    sprintf(conteudo,"XPTO%d",i);
    sprintf(cliente,"ZE%d",i);
    sprintf(origem,"X%d",i);
    sprintf(destino,"Y%d",i);
    X=criarContentor(conteudo,cliente,origem,destino);
    }

    PUSH(P_Leixoes,X);

    printf("Tamanho da Pilha= %d\n",getTamanho(P_Leixoes));

    mostrarContentor(X);

    CONTENTOR *C=pertence_Rec(X,"a");
    mostrarContentor(C);

    destruirPilha(P_Leixoes);
    return 0;
}
