#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define DEBUG 1

typedef struct Pessoa
{
    char nome[21]; /* a */
    int idade;     /* b */
    float peso;    /* c */
    float altura;  /* d */
} *ptPESSOA,PESSOA;

typedef struct No
{
    ptPESSOA inf;
    struct No *esq, *dir;
} *ptNO,NO;

typedef struct Arvore
{
    int nelementos;
    ptNO raiz;
} *ptARVORE;

/* 4 criar nova �rvore */
ptARVORE criar_arvore()
{
    ptARVORE A;
    A = (ptARVORE) malloc(sizeof(struct Arvore));
    A->raiz = NULL;
    A->nelementos = 0;
    return A;
}

/* 5 alocar e inicializar um novo n� */
ptNO criar_no()
{
    NO *N=(NO*)malloc(sizeof(NO));
    N->inf=(PESSOA*)malloc(sizeof(PESSOA));
    N->dir=NULL;
    N->esq=NULL;
    return N;
}

/* 6 registar dados de um novo n� */
void ler_no(ptNO N)
{
    ptPESSOA pes = (ptPESSOA) N->inf;  // pes aponta tb para a informa��o
    printf("Nome: ");
    fflush(stdin);
    if (!DEBUG)
    {
        gets(pes->nome);
        //scanf("%s", pes->nome);
        printf("Idade (anos): ");
        scanf("%d", &pes->idade);
        printf("Peso (quilos): ");
        scanf("%f", &pes->peso);
        printf("Altura (metros): ");
        scanf("%f", &pes->altura);
    }
    else
    {
        printf("Idade (anos): ");
        scanf("%d", &pes->idade);
        strcpy(pes->nome,"A_");
        pes->altura = 1 + pes->idade/100.0;
        pes->peso = 50 + pes->idade/10.0;
    }
}

/* 7 comparar 2 n�s (utilizando a idade) */
int comparar_nos(ptNO A, ptNO B)
{
    if (A->inf->idade < B->inf->idade)
        return -1;
    else if (A->inf->idade > B->inf->idade)
        return 1;
    else
        return 0;   // s�o iguais
}

/* 8 verificar se 2 n�s s�o iguais (utilizando a idade) */
int nos_iguais(ptNO A, ptNO B)
{
    return comparar_nos(A, B) == 0;
}

/* 9 inserir novo n� na �rvore (ordena��o pelo campo idade) */
//de outra forma
void insere(ptNO no_novo, ptNO raiz)
{

    if(comparar_nos(no_novo,raiz)<=0)//inserir a esquerda
    {
        if(!raiz->esq)
            raiz->esq=no_novo;
        else
            insere(no_novo,raiz->esq);
    }
    else  //inserir a direira
    {
        if(!raiz->dir)
            raiz->dir=no_novo;
        else
            insere(no_novo,raiz->dir);

    }

}

void inserir_no(ptNO no_novo, ptARVORE A)
{
    if(!A)return;
    if(!no_novo)return;
    if(A->raiz==NULL)//se a arvore esta vazia
    {
        A->raiz=no_novo;
    }
    else //se a arvore ja contem elementos
    {
        insere(no_novo,A->raiz);
    }

    A->nelementos++;

}

/* 10 verificar se um determinado n� pertence a uma dada �rvore (utilizando o campo idade) */
ptNO pesquisar_no(ptNO no_pesquisa, ptNO raiz)
{
    if(!raiz)return NULL;
    else if(nos_iguais(raiz,no_pesquisa))
        return raiz;
    else if(comparar_nos(no_pesquisa,raiz)<0)
        return pesquisar_no(no_pesquisa,raiz->esq);
    else
        return pesquisar_no(no_pesquisa,raiz->dir);
}

ptNO pesquisar(int idad, ptARVORE A)
{

    if(!A) return NULL ;
    ptNO no_pesq=criar_no();
    no_pesq->inf->idade=idad;
    return pesquisar_no(no_pesq,A->raiz);

}

/* 11 mostrar dados de um n� */
void mostrar_no(ptNO no_mostrar)
{
    int altura_no(ptNO);

    ptPESSOA pes = (ptPESSOA) no_mostrar->inf;
    if (!DEBUG)
    {
        printf("\nNome: %s", pes->nome);
        printf("\nIdade (anos): %d", pes->idade);
        printf("\nPeso (quilos): %.2f", pes->peso);
        printf("\nAltura (metros): %.2f", pes->altura);
    }
    else
    {
        printf(" ( %d )", pes->idade);
        printf("     nome:%s", pes->nome);
        printf("   %d anos", pes->idade);
        printf("   %.2f Kg ", pes->peso);
        printf("   %.2f metros", pes->altura);
        //printf("   n� de n�vel %d", altura_no(no_mostrar)-altura_arvore(A));
    }
}

/* 12a travessia inorder */
void mostrar_inorder_no(ptNO no_actual)
{
    if(no_actual)
    {
        mostrar_inorder_no(no_actual->esq);
        mostrar_no(no_actual);
        printf("\n");
        mostrar_inorder_no(no_actual->dir);
    }
}

void mostrar_inorder(ptARVORE A)
{
    if(!A)return;
    else if(!A->raiz)return;
    else
        mostrar_inorder_no(A->raiz);
}

/* 12b travessia preorder */
void mostrar_preorder_no (ptNO no_actual)
{

    if(no_actual)
    {
        mostrar_no(no_actual);
        printf("\n");
        mostrar_preorder_no(no_actual->esq);
        mostrar_preorder_no(no_actual->dir);
    }
}

void mostrar_preorder(ptARVORE A)
{
    if(!A)return;
    if(!A->raiz)return;
    else
        mostrar_preorder_no(A->raiz);
}

/* 12c travessia postorder */
void mostrar_postorder_no (ptNO no_actual)
{


    if(no_actual)
    {
        mostrar_postorder_no(no_actual->esq);
        mostrar_postorder_no(no_actual->dir);
        mostrar_no(no_actual);
        printf("\n");
    }

}

void mostrar_postorder(ptARVORE A)
{

    if(!A)return;
    if(!A->raiz)return;
    else
        mostrar_postorder_no(A->raiz);

}

/* 13 libertar o espa�o alocado para um dado n� e respectivas informa��es associadas */
void libertar_no(ptNO no_libertar)
{
    free(no_libertar->inf); // Destroi informacao
    free(no_libertar);      // Destroi o elemento
}

/* 14 remover um dado n� da �rvore (utilizando o campo idade como chave) */
ptNO removerNodoMax(ptNO *arvore)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);

    return NULL;
}

void removerNodo(ptNO *praiz) // re-arranja a �rvore
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);
    return NULL;
}



ptNO remover(ptNO no_remover, ptNO *praiz)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);

    return NULL;
}

/* 15 contar os n�s existentes numa dada �rvore */
int contar_no(ptNO no_actual)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);

    return 0 ;
}

int contar_nos(ptARVORE A)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);

    return 0;
}

/* 16 determinar o n�mero de pessoas com idade superior a uma dada idade m�nima */
int contar_no_sup_idade(ptNO no_actual, int idade_minima)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);

    return 0;
}

int contar_nos_sup_idade(ptARVORE A, int idade_minima)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);

    return 0;
}

int conta_folha(ptNO no_actual)
{
    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);
    return 0;
}

int contar_folhas(ptARVORE A)
{
    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);
    return 0;
}

/* 18 determinar a altura de uma dada a �rvore */
int altura_no(ptNO no_actual)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);
    return 0;
}

int altura_arvore(ptARVORE A)
{

    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);
    return 0;
}

/*  auxiliares    */
ptNO criar_preencher_no(char *nm, int ida, float pes, float alt )
{
    ptNO N = criar_no();
    if (N)
    {
        strcpy(N->inf->nome,nm);
        N->inf->idade = ida ;
        N->inf->peso =  pes ;
        N->inf->altura = alt ;
    }
    return N;
}

/* 14 remover um dado n� da �rvore (utilizando o campo idade como chave) */
// de outra forma (mas, apesar de remover bem, o ponteiro para o removido fica mal)
ptNO remove_max(ptNO tr, ptNO pos)
{

    ptNO ant;
    ant=pos;
    while(pos->dir)
    {
        ant=pos;
        pos=pos->dir;
    }
    if(tr->esq == pos)
    {
        tr->esq=pos->esq;
    }
    else
    {
        ant->dir=pos->esq;
    }
    ptPESSOA aux=tr->inf;
    tr->inf=pos->inf;
    pos->inf=aux;
    return pos;
}

ptNO remov(ptNO no_remover, ptNO ant, ptNO pos)
{

    if(!pos)
        return NULL;
    else if(nos_iguais(pos,no_remover))
    {
        if(!pos->dir)
        {
            if(ant->dir == pos)
                ant->dir=pos->esq;
            else
                ant->esq=pos->esq;
            return pos;
        }
        else if(!pos->esq)
        {
            if(ant->dir == pos)
                ant->dir=pos->dir;
            else
                ant->esq=pos->dir;
            return pos;
        }
        else
        {
            return remove_max(pos,pos->esq);
        }
    }
    else if(comparar_nos(pos,no_remover)>0)
        return remov(no_remover,pos,pos->esq);
    else
        return remov(no_remover,pos,pos->dir);
}

ptNO remover_no(ptNO no_remover, ptARVORE A)
{

    ptNO no_removido;

    if(!A->raiz)
        no_removido=NULL;
    else if(nos_iguais(A->raiz,no_remover))
    {
        if(!A->raiz->dir)
        {
            no_removido=A->raiz;
            A->raiz=A->raiz->esq;
        }
        else if(!A->raiz->esq)
        {
            no_removido=A->raiz;
            A->raiz=A->raiz->dir;
        }
        else
        {
            no_removido=remove_max(A->raiz,A->raiz->esq);
        }
    }
    else if(comparar_nos(A->raiz,no_remover)>0)
    {
        no_removido=remov(no_remover,A->raiz,A->raiz->esq);
    }
    else
    {
        no_removido=remov(no_remover,A->raiz,A->raiz->dir);
    }

    return no_removido;
}

/*  travessia por n�vel */
void mostrar_nivel_no(ptNO no_actual)
{
    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);
}

void mostrar_nivel(ptARVORE A)
{
    printf("\n\n\n\tFuncao [%s] ainda nao implementada...\n\n",__FUNCTION__);
}


/*  'desenha' �rvore   */
// A fun��o auxiliar desenhaNo imprime o caracter c precedido
// de 3b espa�os e seguido de uma mudan�a de linha.
void desenhaNo(int c, int b)
{
    int i;
    for (i = 0; i < b; i++)
        printf("---");
    if (c)    // n�o � zero <=> NULL
        printf("%d<\n", c);
    else
        printf("#\n");
}
// A fun��o desenha faz um desenho esquerda-direita-raiz da �rvore x.
// O desenho ter� uma margem esquerda de 3b espa�os.
void desenha(ptNO x, int b)
{
    if (x == NULL)
    {
        desenhaNo(0, b);
        return;
    }
    desenha(x->dir, b+2);
    desenhaNo(x->inf->idade, b);
    desenha(x->esq, b+2);
}

/* 19 */
int menu_principal()
{
    int x;
    printf("\n\n\n# MENU PRINCIPAL ----------------------------------------------#");
    printf("\n|  (1)  Inserir um novo N� na �rvore                           |");
    printf("\n|  (2)  Pesquisar N�S da �rvore (por uma idade)                |");
    printf("\n|       Mostrar todos os N�S da �rvore usando a t�cnica:       |");
    printf("\n|       (3)  inorder                                           |");
    printf("\n|       (4)  preorder                                          |");
    printf("\n|       (5)  postorder                                         |");
    printf("\n|  (6)  Retirar um N� da �rvore (atrav�s da idade)             |");
    printf("\n|  (7)  Mostrar o n�mero total de N�S da �rvore                |");
    printf("\n|  (8)  Mostrar o n�mero de N�S na �rvore com uma idade m�nima |");
    printf("\n|  (9)  Mostrar o n�mero de N�S folha da �rvore                |");
    printf("\n|  (10) Mostrar a altura da �rvore                             |");
    printf("\n|  (11) Retirar um N� (de outra forma, para comparar)          |");
    printf("\n|       (12)  travessia por n�vel                              |");
    printf("\n|  (13) 'desenha' �rvore                                       |");
    printf("\n|  (15) Informa��es da �rvore                                  |");
    printf("\n|  ----------------------------------------------------------- |");
    printf("\n|  (0) SAIR                                                    |");
    printf("\n#--------------------------------------------------------------#\n");
    fflush(stdin);
    do
    {
        printf("\n  Qual a sua opcao ? ");
        fflush(stdin);
        scanf("%d",&x);
    }
    while (x < 0 || x > 15 );
    return x;
}

/* 20 */
int main()
{
    ptARVORE arv = criar_arvore();
    ptNO no_novo, no_remover, no_removido, no_pesquisar, no_pesquisado ;
    int op,idad;
    setlocale(LC_ALL,"");   /* para usar caracteres acentuados   */

    if (DEBUG)
    {
        no_novo = criar_preencher_no("A_30", 30, 30.5, 1.30);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_20", 20, 20.5, 1.20);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_50", 50, 50.5, 1.50);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_60", 60, 60.5, 1.60);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_55", 55, 55.5, 1.55);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_40", 40, 40.5, 1.40);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_26", 26, 26.5, 1.26);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_10", 10, 10.5, 1.10);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_29", 29, 29.5, 1.29);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_27", 27, 27.5, 1.27);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_28", 28, 28.5, 1.28);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_22", 22, 22.5, 1.22);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_25", 25, 25.5, 1.25);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_21", 21, 21.5, 1.21);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_23", 23, 23.5, 1.23);
        inserir_no(no_novo, arv);
        no_novo = criar_preencher_no("A_24", 24, 24.5, 1.24);
        inserir_no(no_novo, arv);
    }

    do
    {
        op = menu_principal();
        switch(op)   //_________________________________________________________________________________
        {
        case 1:   // inserir n�
            no_novo = criar_no();
            ler_no(no_novo);
            inserir_no(no_novo, arv);
            break; //___________________________________________________________________________________
        case 2:   // pesquisar (por idade)
            if (arv->nelementos==0)
                printf("\nNao existem nos na arvore!\n");
            else
            {
                printf("Idade da pessoa:");
                scanf("%d", &idad);
                no_pesquisado = pesquisar(idad, arv);
                if (no_pesquisado)
                {
                    printf("\n Foi encontrado um no com a idade pretendida!\n");
                    mostrar_no(no_pesquisado);
                }
                else
                    printf("\nNao foi encontrado nenhum NO com essa idade!\n");
            }
            break; //___________________________________________________________________________________
        case 3:   //  travessia inorder
            if (arv->nelementos==0)
                printf("\nNao existem nos na arvore!");
            else
                mostrar_inorder(arv);
            break; //___________________________________________________________________________________
        case 4:   //  travessia preorder
            if (arv->nelementos==0)
                printf("\nNao existem nos na arvore!");
            else
                mostrar_preorder(arv);
            break; //___________________________________________________________________________________
        case 5:   //  travessia postorder
            if (arv->nelementos==0)
                printf("\nNao existem nos na arvore!");
            else
                mostrar_postorder(arv);
            break; //___________________________________________________________________________________
        case 6:   //  eliminar n�
            printf("\nRemover No da arvore...");
            if (arv->nelementos==0)
                printf("\nNao existem nos na arvore!");
            else
            {
                no_remover = criar_no();
                printf("Idade da pessoa:");
                scanf("%d", &((ptPESSOA)no_remover->inf)->idade);
                no_removido = remover_no(no_remover, arv);
                if (no_removido)
                {
                    printf("\n Foi removido um no!\n");
                    mostrar_no(no_removido);
                    libertar_no(no_removido);
                    arv->nelementos--;
                }
                else
                    printf("\nNao foi encontrado nenhum no com essa idade!\n");
            }
            break; //___________________________________________________________________________________
        case 7:
            //printf("\nNumero total de nos:%d", arv->nelementos);
            printf("\nNumero total de nos:%d ", contar_nos(arv));
            printf("(arv->nelementos = %d)\n", arv->nelementos);
            break; //___________________________________________________________________________________
        case 8:
        {
            int idade_minima;
            printf("\nIdade minima:");
            scanf("%d", &idade_minima);
            printf("\nNumero total de nos com idade superior a ");
            printf("%d: %d\n", idade_minima, contar_nos_sup_idade(arv, idade_minima));
        }
        break; //___________________________________________________________________________________
        case 9:
            printf("\nN�mero total de n�s folha: %d\n", contar_folhas(arv));
            break; //___________________________________________________________________________________
        case 10:
            printf("\nAltura da arvore:%d\n", altura_arvore(arv));
            break; //___________________________________________________________________________________
        case 11:
            printf("\nRemover No da arvore (de outra forma)...");
            if (arv->nelementos==0)
                printf("\nNao existem nos na arvore!");
            else
            {
                no_remover = criar_no();
                printf("Idade da pessoa:");
                scanf("%d", &((ptPESSOA)no_remover->inf)->idade);
                no_remover = remover_no(no_remover, arv);
                if (no_remover)
                {
                    printf("\n Foi removido um no!\n");
                    mostrar_no(no_remover);
                    libertar_no(no_remover);
                    arv->nelementos--; // diminui numero de elementos
                }
                else
                    printf("\nNao foi encontrado nenhum no com essa idade!\n");
            }
            break; //___________________________________________________________________________________
        case 12:   //  travessia por n�vel
            printf("Travessia por n�vel   \n");
            if (arv->nelementos==0)
                printf("\nNao existem nos na arvore!");
            else
                mostrar_nivel(arv);
            break; //___________________________________________________________________________________
        case 13:   //  travessia por n�vel
            if (!arv)  printf("\n�rvore n�o definida...");
            else if (!arv->raiz) printf("\n�rvore vazia...");
            else
                desenha(arv->raiz,1);
            break; //___________________________________________________________________________________
        case 15:   //  v�rias informa��es
            if (!arv)  printf("\n�rvore n�o definida...");
            else if (!arv->raiz) printf("\n�rvore vazia...");
            else
            {
                printf("\n A �rvore com %d n�s, dos quais %d s�o folhas, e altura %d.",arv->nelementos, contar_folhas(arv), altura_arvore(arv));
            }
            break; //___________________________________________________________________________________
        }  // END switch
        //system("pause");
    }
    while ( op != 0 );
    return 0;
}
