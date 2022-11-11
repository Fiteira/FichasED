#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "tipoDados.h"


typedef struct elemento
{
  PALAVRA *Info;
  struct elemento *Prox;

}ELEMENTO,NO, *ptELEMENTO;

typedef struct lista
{
    char Lingua[3];
    ELEMENTO *Inicio;
    int NEL;
}LISTA,*ptLISTA;

LISTA *criarLista(char *lingua);
ELEMENTO *criarElemento();
void lerElemento(ELEMENTO *x);
void addInicio(LISTA *l,NO *x);
void addFim(LISTA *l,NO *x);
void addOrd(LISTA *l,NO *x);
void mostrarLista(LISTA *l);
void mostrarContrarioLista(LISTA *l);
PALAVRA *pesquisarPalavra(LISTA *l);
int lerFicherio(LISTA *l,char *ficherio);
int exportarFicherio(LISTA *l,char *ficherio);
int removerPalavra(LISTA *l,char *txt);
int repetidos(LISTA *l);
ELEMENTO *pertence_Rec_NOS(NO *p,char *txt);
ELEMENTO *pertence_Rec(LISTA *l,char *txt);
int elementosRepetidosV2(LISTA *l);
void libertarElemento(ptELEMENTO p);
void mostrar_inversa_v1(LISTA *l);
void mostrar_inversa_v2(ptLISTA l);
void ordenar_lista_v1(ptLISTA l);
void destruirLista(LISTA *l,int tipo);


#endif // LISTA_H_INCLUDED
