#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipos_dados.h"
#include "uteis.c"

#define INSUCESSO 0
#define SUCESSO 1


EDados *criarEDados(char *autor,int n);
int lerFicheiro(EDados *ed,char *ficheiro);
void ordenarDados(EDados *v);
int gravarFicheiro(EDados *ed,char *ficheiro);
void mostrarEDados(EDados *ed);
USER *pesquisarUSER(EDados *ed,char *login);
void mostrarEDados(EDados *ed);
EDados *duplicarDados(EDados *orig);
EDados *criarEDados(char *autor,int n);
//void gerarUsersAleatorios(EDados *ed);
int menu();
void destruirEDados(EDados *ed);