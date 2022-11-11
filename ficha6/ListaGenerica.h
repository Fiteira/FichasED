#ifndef LISTAGENERICA_H_INCLUDED
#define LISTAGENERICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct no_generico
{
    void *Info;
    struct no_generico *Prox;
}NOG;
typedef struct
{
    NOG *Inicio;
    int NEL;
}Lista_Generica;

Lista_Generica *Criar_Lista_Generica();
void Add_LG(Lista_Generica *L, void *X);
void Add_Ordenado_LG(Lista_Generica *L, void *X, int (*func_comparar)(void*, void*));
void Destruir_LG(Lista_Generica *L, void (*fdestruir)(void *));

void RemoverElementoLG(Lista_Generica *L, void * ele_remover,
      void (*func_remover) (void*), int (*func_comparar) (void*, void*));

void Mostrar_LG(Lista_Generica *L, void (*f)(void *));
void Gravar_LG(Lista_Generica *L, void (*f)(void *, FILE *), FILE *F);

void *Pesquisar_LG(Lista_Generica *L, int (*fcomp)(void *, void *), void *valor);

void RemoverPrimeiroLG(Lista_Generica *L, void (*func_remover) (void*));
void RemoverUltimoLG(Lista_Generica *L, void (*func_remover) (void*));

#endif // LISTAGENERICA_H_INCLUDED
