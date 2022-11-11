#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 21
typedef struct
{
    char NOME[MAX_NOME];
    //char *NOME;
    int IDADE;
    float PESO;
    float ALTURA;
}PESSOA;

PESSOA *Criar_Pessoa(char *_nome, int _idade, float _peso, float _altura);
void Mostrar_Pessoa(void *P);
void FDestruirPessoa(void *P);
void Gravar_Pessoa(void *P, FILE *F);
int FComparacao_NOME(void *P, void *valor);

#endif // PESSOA_H_INCLUDED
