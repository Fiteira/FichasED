#include <stdio.h>
#include <stdlib.h> 
#include "tipos_dado.c"

main(){
    
    int nReg;
    printf("Quantos alunos: ");
    scanf("%d",&nReg);
    
    ALUNO *v;
    v=alocarAlunos(nReg);
    lerAluno(v,nReg);
    escreverAluno(v,nReg);
    calcularMedia(v,nReg);
    listaNotas(v,nReg,5,"listaNotas.txt");
}