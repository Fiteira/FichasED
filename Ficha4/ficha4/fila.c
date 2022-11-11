#include "fila.h"


FILA *Criar_FILA()
{
    FILA *F = (FILA *)malloc(sizeof(FILA));
    F->Inicio = NULL;
    F->NEL = 0;
    return F;
}
void Destruir_FILA(FILA *F)
{
    if (!F) return;
    NOF *P = F->Inicio;
    NOF *Aux = NULL;
    while (P)
    {
        Aux = P->Prox;
        free(P->Info);
        free(P);
        P = Aux;
    }
    free (F);
}
void Add_FILA(FILA *F, VEICULO *X)
{
    if (!F) return;
    NOF *Novo = (NOF *)malloc(sizeof(NOF));
    Novo->Info = X;
    Novo->Prox = NULL;
    if (!F->Inicio)
        F->Inicio = Novo;
    else
    {
        NOF *K = F->Inicio;
        while (K->Prox)
        {
            K = K->Prox;
        }
        K->Prox = Novo;
    }
    F->NEL++;
}
VEICULO *Remover_FILA(FILA *F)
{
    if (!F) return NULL;
    if (!F->Inicio) return NULL;
    VEICULO *Ptr_v = F->Inicio->Info;
    NOF *Aux = F->Inicio->Prox;
    free(F->Inicio);
    F->Inicio = Aux;
    F->NEL--;
    return Ptr_v;
}
void Mostrar_FILA(FILA *F)
{
    if (!F) return;
    NOF *P = F->Inicio;
    while (P)
    {
        Mostrar_VEICULO(P->Info);
        P = P->Prox;
    }
}
int Get_Espera(FILA *F)
{
    if (F == NULL) return -1;
    return F->NEL;
}
void Gravar_Ficheiro_FILA(FILA *F, char *nome_ficheiro)
{
    if(!F) return;
    if(!F->Inicio) return;
    int i=0;
    FILE *fic=fopen(nome_ficheiro,"wb");
    if(!fic)
    {
        printf("Impossivel abrir o ficheiro.\n")
    }
    else
    {
        NOF *pv=F->Inicio;
        while(pv)
        {
            i++;
            fwrite(pv->Info,sizeof(VEICULO),1,fic);
            pv=pv->seg;
        }
        fclose(fic);
    }
    printf("\n\n %d veiculo foram gravados no ficheiro.\n",i);
}

void le_veiculo_fich(FILA *F,char *nome_ficheiro)
{
    FILE *fic=fopen(nome_ficheiro,"rb");
    int i=0;
    if(!fic)
    {
        printf("Impossivel abrir o ficheiro.\n")
    }
    else
    {
     while(!feof(fic))
     {
      i++;
      VEICULO *V=(VEICULO*)malloc(sizeof(VEICULO));
      if(fread(V,sizeof(VEICULO),1,fic)>0)
      {

        Mostrar_VEICULO(V);

      }
     }
    }
}
