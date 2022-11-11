#include <stdio.h>
#include <stdlib.h>
#include "tipos_dados.h"
#include "uteis.c"

PESSOA *criarVetorPessoa(int n){
    return (PESSOA*)malloc(n*sizeof(PESSOA));
}

void preencherVetorPessoa(PESSOA *v,int n){

    for (int i = 0; i < n; i++)
    {
        v[i].cc=aleatorio(1000,2000);
        v[i].altura=aleatorio(100,200)/100.0;
        v[i].peso=aleatorio(20,120);
        v[i].dtn.mes=aleatorio(0,11);
        v[i].dtn.ano=aleatorio(2000,2005);
        v[i].dtn.dia=aleatorio(1,31);
        sprintf (v[i].nome,"joao- %d",i);
    }
    
}

void escreverVetorPessoa(PESSOA *v,int n){

    for (int i = 0; i < n; i++)
    {
        printf("\n------------------");
        printf("\n cc: %d",v[i].cc);
        printf("\n altura: %0.2f",v[i].altura);
        printf("\n peso: %0.2f",v[i].peso);
        printf("\n\ndata de nascimento",v[i].altura);
        printf("\n  dia: %d",v[i].dtn.dia);
        printf("\n  mes: %d",v[i].dtn.mes);
        printf("\n  ano: %d",v[i].dtn.ano);  
    }    
}

int mostrarVetorPessoaIMC(PESSOA *v,int n,float inf,float sup){
    
    int num=0;
    for (int i = 0; i < n; i++)
    {
        float IMC=v[i].peso/(v[i].altura * v[i].altura);
            if ((IMC > inf)&&(IMC < sup))
            {
                printf("\nIMC- %0.2f",IMC);
                printf("\n CC- %d",v[i].cc);
                num++;
            }
    }
    return num;
}

int mesComMaisNascimentos(PESSOA *v,int n){

    int mes[12];
        for (int i = 0; i < 12; i++)
        {
            mes[i]=0;
        }

        for (int i = 0; i < n; i++)
        {
            int mespessoa=v[i].dtn.mes;
            mes[mespessoa]++;
        }
        
    int posMax=0;
        for (int i = 0; i < 12; i++)
        {
           if (mes[i]>mes[posMax])
           {
               posMax=i;
           }
        }
    return posMax;
}

float mediaIMCentreDoisAnos(PESSOA *v,int n,int anoMin,int anoMax){

    float media=0.0;
    int cont=0;
    for (int i = 0; i < n; i++)
    {
      if (v[i].dtn.ano >= anoMin && v[i].dtn.ano <= anoMax)
      {
          media+=v[i].peso;
          cont++;
      }
    }
      media=media/cont;
    return media;
}


int anoMaisNasc(PESSOA *v,int n,int *nNasc){

    int *ano,*nNasc;

    ano=(int*)malloc(n*sizeof(int));
    nNasc=(int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        
    }
    
}



void destruirVetorPessoa(PESSOA *v){

    if(v){
            free(v);
    }   

}