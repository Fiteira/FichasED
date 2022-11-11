#include <stdio.h>
#include "tipos_dados.c"


main(){
    int n=4;
    PESSOA *v;
    v=criarVetorPessoa(n);
    preencherVetorPessoa(v,n);
    escreverVetorPessoa(v,n);
    mostrarVetorPessoaIMC(v,n,23.0,24.0);
    mesComMaisNascimentos(v,n);
    printf("\nA media dos pesos dos anos 2000 ate 2003: %.2f", mediaIMCentreDoisAnos(v,n,2000,2003));
    destruirVetorPessoa(v);
}