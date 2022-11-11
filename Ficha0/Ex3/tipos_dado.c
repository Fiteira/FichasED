#include <string.h>
#include <stdlib.h>
#include "tipos_dado.h"
#include "uteis.c"


ALUNO *alocarAlunos(int n){
   return (ALUNO*)malloc(n * sizeof(ALUNO));
}

void lerAluno(ALUNO *v,int n){

    for (int i = 0; i < n; i++)
    {
        
       v[i].n_mecanografico=aleatorio(23000,24000);        //v[i].n_mecanografico=LerInteiro("\n Numero mecanografico: ");
       sprintf(v[i].nome,"abel %d",i);                    //LerString("\n Nome: ",v[i].nome);
            for (int j = 0; j < 5; j++)
            {
                sprintf(v[i].uc[j].nomeUC,"uc %d",j);     //LerString("\n Nome da UC:",v[i].uc[j].nomeUC);
                v[i].uc[j].nota=aleatorio(0,20)*1.0;     //v[i].uc[j].nota=LerInteiro("Nota: ");
            }   
    }
}

void escreverAluno(ALUNO *v,int n){
    
    for (int i = 0; i < n; i++)
    {
        printf("\n------------------");
        printf("\n n_mecanografico: %d",v[i].n_mecanografico);
        printf("\n nome: %s",v[i].nome);
        for (int j = 0; j < 5; j++)
        {
            printf("\n A %s : nota %.2f",v[i].uc[j].nomeUC,v[i].uc[j].nota);
        }
    } 
}

void calcularMedia(ALUNO *v,int n){
    float notas=0;
    float *media;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            notas+= v[i].uc[j].nota;
        }
        notas=(notas/5);
        media[i]=notas;
        notas=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("\n Media do aluno numero %d- %0.2f",v[i].n_mecanografico,media[i]);
    }
    
}

float numeroMedioUC(ALUNO *v,int n,int lim){
    int cont=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < 5; j++)
        {
            if(v[i].uc[j].nota < lim){
                cont++;
            }
        }
        
    }
    return (cont*1.0)/n;
}

void listaNotas(ALUNO *v,int n,int val,char *nomeFich){

    FILE *f=fopen(nomeFich,"w+");

    for (int i = 0; i < n; i++)
    {
        fprintf(f,"\n nome: %s",v[i].nome);
        for (int j = 0; j < 5; j++)
        {
            if (v[i].uc[j].nota >= val)
            {
                fprintf(f,"\n %s -> %0.2f",v[i].uc[j].nomeUC,v[i].uc[j].nota);
            }   
        }
        fprintf(f,"\n------------");
    }
    
    fclose(f);
}