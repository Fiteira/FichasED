
#include "Pessoa.h"

PESSOA *Criar_Pessoa(char *_nome, int _idade, float _peso, float _altura)
{
    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    strcpy(P->NOME, _nome);
    P->IDADE = _idade;
    P->PESO = _peso;
    P->ALTURA = _altura;
    return P;
}
void Mostrar_Pessoa(void *P)
{
    if (!P) return;
    PESSOA *X = (PESSOA *)P;
    printf("-----PESSOA-----\n");
    printf("\t NOME: [%s]\n", X->NOME);
    printf("\t IDADE: [%d]\n", X->IDADE);
    printf("\t PESO: [%f]\n", X->PESO);
    printf("\t ALTURA: [%f]\n", X->ALTURA);
}
void FDestruirPessoa(void *P)
{
    PESSOA *X = (PESSOA *)P;
    free(X);
}
void Gravar_Pessoa(void *P, FILE *F)
{
    PESSOA *X = (PESSOA *)P;

    //fwrite(X->NOME, sizeof(char), MAX_NOME, F);
    int TAM = strlen(X->NOME) + 1;
    fwrite(&TAM, sizeof(int), 1, F);
    fwrite(X->NOME, sizeof(char), TAM, F);

    fwrite(&(X->IDADE), sizeof(int), 1, F);
    fwrite(&(X->PESO), sizeof(int), 1, F);
    fwrite(&(X->ALTURA), sizeof(int), 1, F);
}
int FComparacao_NOME(void *P, void *valor)
{
    PESSOA *X = (PESSOA *)P;
    char *nome = (char *)valor;
    if (stricmp(X->NOME, nome) == 0)
        return 1;
    return 0;
}
