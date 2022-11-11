
#include "Hashing.h"


// Autor: Eu
Hashing *Criar_Hashing()
{
    Hashing *H = (Hashing *)malloc(sizeof(Hashing));
    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        H->Dados[i] = (GRUPO *)malloc(sizeof(GRUPO));
        H->Dados[i]->FAIXA = i;
        H->Dados[i]->LP = Criar_Lista_Generica();
    }
    return H;
}
void Destruir_Hashing(Hashing *H)
{
    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        Destruir_LG(H->Dados[i]->LP, FDestruirPessoa);
        free(H->Dados[i]);
    }
    free(H);
}
int Funcao_Hashing(PESSOA *P)
{
    return (int) P->IDADE / 10;
}

int Funcao_Hashing_Nome(PESSOA *P)
{
    if(!P) return 0;

    char inicial = P->NOME[0];
    inicial = tolower(inicial);

    // recorrendo a tabela ASCII

    int pos = inicial - 'a';

    if(pos < 0 || pos > 25) return 0;
    return pos;
}
int Add_Hashing(Hashing *H, PESSOA *P)
{
    if (!H) return -2;
    if (!P) return -1;
    int Pos = Funcao_Hashing_Nome(P);
    if ((Pos < 0) || (Pos > 25)) return 0;
    Add_LG(H->Dados[Pos]->LP, P);
    return 1;
}
void Mostrar_Hashing(Hashing *H)
{
    printf("-------[%s]------\n", __FUNCTION__);
    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        printf("FAIXA: %c\n", H->Dados[i]->FAIXA + 'A');
        Mostrar_LG(H->Dados[i]->LP, Mostrar_Pessoa);
    }
}
PESSOA *Pesquisar_Pessoa_NOME(Hashing *H, char *nome)
{
    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        PESSOA *P = (PESSOA *)Pesquisar_LG(H->Dados[i]->LP, FComparacao_NOME, nome);
        if (P != NULL)
            return P;
    }
    return NULL;
}
int Gravar_Ficheiro_Binario(Hashing *H, char *fich)
{
    FILE *F = fopen(fich,  "wb");
    int VAR = MAX_ENTRADAS;
    fwrite(&VAR, sizeof(int), 1, F);

    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        Gravar_LG(H->Dados[i]->LP, Gravar_Pessoa, F);
    }

    fclose(F);
    return 0;
}

int Lerr_Ficheiro_Binario(Hashing *H, char *fich)
{
    return 0;
}

int remover_elemento_hashing(Hashing * H, PESSOA * P)
{
    if(!H) return 0;
    if(!P) return 0;

    int POS = Funcao_Hashing(P);
    if(validar_posicao_hashing(POS))
    {
        RemoverElementoLG(H->Dados[POS]->LP, P, FDestruirPessoa, FComparacao_NOME);
    }

}

int validar_posicao_hashing(int pos)
{
    return ((pos < 0) || (pos > 9)) ? 0 :  1;
}
