#include "matriz.h"


int Esparsa(int *Matriz,int M,int N,float percentagem){

    float cont=0;
    float per=0.0;
    

        for (int i = 0; i < M*N; i++)
        {
            if(*Matriz == 0){
               cont++;
               
           }
        *Matriz++;
        }
        
           
    per=(cont/(M*N))*100;

    if (per > percentagem)
    {
        return 1;
    }else
        return 0;
    
}