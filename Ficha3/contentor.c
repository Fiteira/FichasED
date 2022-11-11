#include "contentor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



CONTENTOR *criarContentor(char *conteudo,char *cliente,char *origem,char *destino)
{
    CONTENTOR *x=(CONTENTOR *)malloc(sizeof(CONTENTOR));

  /*printf("\nConteudo: ");
    fflush(stdin);
    gets(x->conteudo);

    printf("\nCliente: ");
    fflush(stdin);
    gets(x->cliente);

    printf("\nOrigem: ");
    fflush(stdin);
    gets(x->origem);

    printf("\nDestino: ");
    fflush(stdin);
    gets(x->destino);

    printf("\nTonelagem: ");
    scanf("%f",&x->tonelagem);*/

    time_t t=time(NULL);
    struct tm *tempo= localtime(&t);
    x->data_ent.ano=tempo->tm_year + 1900;
    x->data_ent.mes=tempo->tm_mon + 1;
    x->data_ent.dia=tempo->tm_mday;
    x->data_ent.hora=tempo->tm_hour;
    x->data_ent.min=tempo->tm_min;
    x->data_ent.seg=tempo->tm_sec;

    sprintf(x->referencia,"[PT]:%d",aleatorio(0,100));

    strcpy(x->cliente,cliente);
    strcpy(x->conteudo,conteudo);
    strcpy(x->destino,destino);
    strcpy(x->origem,origem);
    x->tonelagem=aleatorio(100,300);

    printf("------------------");
    return x;
}



void mostrarContentor(CONTENTOR *x)
{
    if(!x)return;
    printf("Contentor----\n");
    printf("\tConteudo: [%s]\n",x->conteudo);
    printf("\tOrigem: [%s]\n",x->origem);
    printf("\tDestino: [%s]\n",x->destino);
    printf("\tCliente: [%s]\n",x->cliente);
    printf("\tData de entrega: %d-%d-%d  %d:%d:%d\n",x->data_ent.dia,x->data_ent.mes,x->data_ent.ano,x->data_ent.hora,x->data_ent.min,x->data_ent.seg);
    printf("\tTonelagem: [%0.2f]\n",x->tonelagem);
    printf("\tReferencia: [%s]\n",x->referencia);
}

