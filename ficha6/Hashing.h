#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "ListaGenerica.h"
#include "Pessoa.h"
#include <ctype.h>

#define MAX_ENTRADAS 25
typedef struct
{
    int FAIXA;
    Lista_Generica *LP;
}GRUPO;

typedef struct
{
    GRUPO *Dados[MAX_ENTRADAS];
    //Lista_Generica *Dados[MAX_ENTRADAS];
}Hashing;

Hashing *Criar_Hashing();
void Destruir_Hashing(Hashing *H);
int Funcao_Hashing(PESSOA *P);
int Funcao_Hashing_Nome(PESSOA *P);
int Add_Hashing(Hashing *H, PESSOA *P);
void Mostrar_Hashing(Hashing *H);
PESSOA *Pesquisar_Pessoa_NOME(Hashing *H, char *nome);
int Gravar_Ficheiro_Binario(Hashing *H, char *fich);
int Lerr_Ficheiro_Binario(Hashing *H, char *fich);
int remover_elemento_hashing(Hashing * H, PESSOA * P);

void * pesquisar_pessoa_idade(Hashing * H, PESSOA *P);

int validar_posicao_hashing(int pos);
#endif // HASHING_H_INCLUDED
