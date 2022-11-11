#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipoMusica.h"


void musicasDownload(MUSICA *lista, int n, int numD){

    for (int i = 0; i < n; i++)
    {
        if(lista[i].nDownloads > numD){
           
            printf("\n ------------------");
            printf("\n%s",lista[i].nome);
            printf("\n%s",lista[i].interprete);
            printf("\n%d",lista[i].ano);
            printf("\n%d",lista[i].simple);
            printf("\n%d",lista[i].nDownloads);       
        }
    }    
}

int numMusicasCantor(MUSICA *p,int n,char *cantor){

    int nMusicas=0;
    for (int i = 0; i < n; i++)
    {
        if(strcmp(p[i].interprete,cantor)==0){
            nMusicas++;
        }
    }
    return nMusicas;
} 

void gravarFicheiroBin(MUSICA *p,int n){


    
}


main(){
    int n;
    printf("Quantas musicas sao?");
    scanf("%d",&n);

    MUSICA *musicas=(MUSICA*)malloc(n*sizeof(MUSICA));
}
