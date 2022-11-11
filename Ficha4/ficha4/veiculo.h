#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRICULA 9
#define MAX_NOME      31
#define MAX_MARCA     16
#define MAX_COR       16

typedef struct
{
    char MATRICULA[MAX_MATRICULA];
    char PROPRIETARIO[MAX_NOME];
    char MARCA[MAX_MARCA];
    char COR[MAX_COR];
    time_t Tempo_de_entrada;
    time_t Tempo_de_saida;
    int Tempo_de_espera;
}VEICULO;

VEICULO *Criar_Ler_VEICULO();
void Mostrar_VEICULO(VEICULO *V);
void Destruir_VEICULO(VEICULO *V);


#endif // VEICULO_H_INCLUDED
