#include "func.h"

EDados *criarEDados(char *autor,int n){

    EDados *ed=(EDados *)malloc(sizeof(EDados));
    strcpy(ed ->Autor,autor);   
    ed->dados= NULL;
    ed->NEL=n;
        if(ed->NEL > 0){
            ed->dados=(USER* )malloc(ed->NEL * sizeof(USER));
        }
}


void mostrarUser(USER *ut){

    printf("USER:\n");
    printf("\tNOME: %s\n", ut->nome);
    printf("\tUTILIZADOR: %s\n", ut->utilizador);
    printf("\tPASSWORD: %s\n", ut->password);
    printf("\tJOIA: %0.2f\n", ut->joia);
    printf("\tDATA REGISTO: %d/%d/%d \n", ut->data_registo.dia,ut->data_registo.mes,ut->data_registo.ano);
    printf("\tEMAIL: %s\n", ut->email);
    printf("\tPAGINA WEB PESSOAL: %s\n", ut->pagina_web_pessoal);
    printf("\tTELEFONE: %d\n", ut->telemovel);
    printf("\tNUMERO DE ACESSOS: %d\n", ut->numero_acessos);
    printf("\tDATA REGISTO: %d/%d/%d \n", ut->data_ultimo_acesso.dia,ut->data_ultimo_acesso.mes,ut->data_ultimo_acesso.ano);

}

void mostrarEDados(EDados *ed){

    if(!ed)   
    return;
    
    printf("AUTOR: [%s]",ed->Autor);
    printf("NEL: [%d]",ed->NEL);
    
    for (int i = 0; i < ed->NEL; i++)
    {
        mostrarUser(&(ed->dados[i]));
    }
    
}

void mostrarEDadosOrdenados(EDados *ed){

    if(!ed)   
    return;
    

    printf("AUTOR: [%s]",ed->Autor);
    printf("NEL: [%d]",ed->NEL);
    
    for (int i = 0; i < ed->NEL; i++)
    {
        MostrarUser(&(ed->dados[i]));
    }
    
}


int lerFicheiro(EDados *ed,char *ficheiro){

  if(!ed) return INSUCESSO;   

    FILE *f=fopen(ficheiro,"rb");
    if (!f) return INSUCESSO;

    ed->NEL = ftell(f)/sizeof(USER); //calcular quantos utilizadores tem no ficheiro binario

    ed->dados=(USER*)malloc(ed->NEL*sizeof(USER));
    fseek(f,0,SEEK_SET);//moving pointer to start
    fread(ed->dados,sizeof(USER),ed->NEL,f);
    
    fclose(f);

    return SUCESSO;
}


int gravarFicheiro(EDados *ed,char *ficheiro){

    if(!ed) return INSUCESSO;   

    FILE *f=fopen(ficheiro,"wb");
    if (!f) return INSUCESSO;

    fwrite(&(ed->NEL),sizeof(int),1,f);
    fwrite(ed->dados,sizeof(USER),ed->NEL,f);
    
    fclose(f);

    return SUCESSO;
}

USER *pesquisarUSER(EDados *ed,char *login);


void ordenarDados(EDados *v){
    if(!v)  return;

    if(!v->dados)  return;

    for (int i = 0; i < v->NEL; i++)
    {
        for (int j = 0; j < (v->NEL-1-i); j++)
        {
            if (v->dados[i].numero_acessos > v->dados[i+1].numero_acessos)
            {
                USER aux=v->dados[i];
                v->dados[i]=v->dados[i+1];
                v->dados[i+1]=aux;
            }
        }
    }   
}

EDados *duplicarDados(EDados *orig){
    
    EDados *novo;
    novo=CriarEDados("Leandro",0);
    novo->dados=(USER*)malloc(orig->NEL*sizeof(USER));
    novo->NEL=orig->NEL;

    for (int i = 0; i < novo->NEL; i++)
    {
        novo->dados[i]=orig->dados[i];
    }
}

int contarPessoasAcessosAno(EDados *v,int ano){

    if(!v)  return;

    if(!v->dados) return;

    int cont=0;

        for (int i = 0; i < v->NEL; i++)
        {
            if(v->dados->data_ultimo_acesso.ano == ano){
                cont++;
            }
        }
    
    return cont;
}


int pesquisarCod(EDados *v,char *cod){

    if(!v)  return;

    if(!v->dados) return;

    int i;
        for (i = 0; i < v->NEL; i++)
        {
            if(stricmp((v->dados[i].utilizador),cod) == 0){ //stricmp serve para igonar maiculas
                
                printf("\n--------------");
                printf("Dados do utilizador %s\n",cod);
                MostrarUser(&(v->dados[i]));

            }
        }
    return i;
}

int pesquisarNome(EDados *v,char *nome){

    if(!v)  return;

    if(!v->dados) return;

    int i;
        for (i = 0; i < v->NEL; i++)
        {
            if(strcmp((v->dados[i].nome),nome) == 0){
                
                printf("\n--------------");
                printf("Dados do utilizador %s\n",nome);
                MostrarUser(&(v->dados[i]));

            }
        }
    return i;
}

float totalJoias(EDados *v){

    
    if(!v)  return;

    if(!v->dados) return;

    float total = 0;

        for (int i = 0; i < v->NEL; i++){

            v->dados[i].joia +=total;
        }

    return total;
}


int menu(){
 
    int opcao = 0;

    printf("\n # --------------------------------------#");
    printf("\n | (1) Ler Ficheiro");
    printf("\n | (2) Ordenar por numero utilizadores");
    printf("\n | (3) Listar Utilizadores");
    printf("\n | (4) Listar Utilizadores Ordenados");
    printf("\n | (5) Valor total joias");
    printf("\n | (6)Pesquisar utilizador por codigo"); // terminar
    printf("\n # --------------------------------------#");
    printf("\n | (0) Sair");
    printf("\n # --------------------------------------#");
    do
    {
    
    opcao = lerInteiro("\nQual opcao?");
    
    } while (opcao < 0 && opcao > 6);

    return opcao;
}


void destruirEDados(EDados *ed)
{
    if (!ed) return;
    if (ed->dados) free(ed->dados);
    free(ed);
}