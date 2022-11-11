#include <stdio.h>
#include "matriz.c"




main(){

    int Matriz[4][3]={{1,0,3},{4,5,0},{0,8,9},{0,11,12}};

    printf("%d",Esparsa(Matriz,4,3,1.0));
    
}