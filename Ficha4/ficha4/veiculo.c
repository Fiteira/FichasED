#include "veiculo.h"

VEICULO *Criar_Ler_VEICULO()
{
    VEICULO *V = (VEICULO *)malloc(sizeof(VEICULO));
    printf("MARCA ? ");
    scanf("%s", V->MARCA);
    //........

    return V;
}
void Mostrar_VEICULO(VEICULO *V)
{
    printf("MARCA: [%s]\n", V->MARCA);
        //........
}

void Destruir_VEICULO(VEICULO *V)
{
    free(V);
}

int tempo_lavagem(time_t inicio,time_t fim)
{
    return (int) difftime(inicio,fim);
}

VEICULO *remover_viatura(FILA *F)
{
    if(!F)return NULL;
    if(!F->Inicio) return NULL;

    NOF *aux=F->Inicio;
    aux->Info->Tempo_de_espera=tempo_lavagem(aux->Info->Tempo_de_saida,aux->Info->Tempo_de_entrada);
    VEICULO *V=aux->Info;
    FILA->Inicio=FILA->Inicio->Prox;
    free(aux);

    FILA->NEL--;
    return V;
}


