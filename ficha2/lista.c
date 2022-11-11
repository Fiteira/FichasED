#include "lista.h"

LISTA *criarLista(char *lingua)
{
    //printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    LISTA *l=(LISTA*)malloc(sizeof(LISTA));
    l->Inicio=NULL;
    l->NEL=0;

    if(strlen(lingua) == 2)
        strcpy(l->Lingua,lingua);
    else
        strcpy(l->Lingua,"??");

    return l;
}

ELEMENTO *criarElemento()
{
    //printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    ELEMENTO *p=(ELEMENTO*)malloc(sizeof(ELEMENTO)); //ou PtrNO p=(PtrNO)malloc(sizeof(ELEMENTO));
    p->Info=(p);
    p->Prox=NULL;

    return p;
}

void addInicio(LISTA *l,NO *x)
{
    //printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    if(!l)return;
    if(!x)return;

    x->Prox=l->Inicio;
    l->Inicio=x;
    l->NEL++;

}

void addFim(LISTA *l,NO *x)
{
    printf("[%s] Ainda nao implementada\n",__FUNCTION__);


}

void addOrd(LISTA *l,NO *x)
{
    printf("[%s] Ainda nao implementada\n",__FUNCTION__);
}

void mostrarLista(LISTA *l)
{
    //printf("[%s] Ainda nao implementada\n",__FUNCTION__);

    if(!l)return;

    printf("Lingua=[%s]\n",l->Lingua);
    printf("NEL= %d\n",l->NEL);
    NO *p=l->Inicio;

    while (p!=NULL)
    {
        mostrarPalavra(p->Info);
        p=p->Prox;
    }
}

void mostrarContrarioLista(LISTA *l)
{
    printf("[%s] Ainda nao implementada\n",__FUNCTION__);
}

PALAVRA *pesquisarPalavra(LISTA *l)
{
    printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    return NULL;
}


int lerFicherio(LISTA *l,char *ficherio)
{
    //printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    if(!l)return 0;
    if(!ficherio)return 0;

    FILE *f=fopen(ficherio,"r");
    if(!f)return 0;
    char BUFFER[MAX_PALAVRA];
    while (!feof(f))
    {
        fscanf(f,"%s",BUFFER);
        PALAVRA *pal=criarPalavra(BUFFER);
        ELEMENTO *x=criarElemento();
        x->Info=pal;
        addInicio(l,x);
    }


    fclose(f);
    return 1;

}

int exportarFicherio(LISTA *l,char *ficherio)
{
    //printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    if(!l)return 0;
    if(!ficherio)return 0;

    FILE *f=fopen(ficherio,"w");
    if(!f)return 0;

    ELEMENTO *p=l->Inicio;
    while (p)
    {
        fprintf(f,"%s\n",p->Info->TEXTO);
        p=p->Prox;
    }
    fclose(f);
    return 1;
}

int validarElemento(ELEMENTO *x)
{
    if(x->Info->TEXTO > 10){

        return 1;
    }
    return 0;
}

void lerElemento(ELEMENTO *x)
{
int elementoValido=validarElemento(&x->Info->TEXTO);
    do{
        printf("Qual a palavra?");
        scanf("%s",x->Info->TEXTO);
        if(!elementoValido)
        {
            printf("Apenas letras [a-z] ");
        }
        return 0;
    }while(!x);
        return 1;
}


int compararElementos(ptELEMENTO a,ptELEMENTO b)
{
   if(strcmp(a->Info->TEXTO,b->Info->TEXTO)==0){
    return 1;
   }
   return 0;
}

int elementos_iguais(ptELEMENTO a,ptELEMENTO b)
{
    return compararElementos(a,b);
}

/** 12 e introduza um elemento na lista, garantido a sua ordenação */
void inserir_elemento_ordenado(ptLISTA L, ptELEMENTO ele_novo)
{
    if (!L)return;
    int av=1;
    ptELEMENTO ant,act;
    if(L->Inicio==NULL){
        ele_novo->Prox=NULL;
        L->Inicio=ele_novo;
    }else{
    ant=act=L->Inicio;
        while(av)
            if(act==NULL)
                av=0;
            else if(compararElementos(act,ele_novo)>0)
                av=0;
            else{
                ant=act;
                act=act->Prox;
            }
        if(act==L->Inicio){
            ele_novo->Prox=L->Inicio;
            L->Inicio=ele_novo;
        }else{
            ant->Prox=ele_novo;
            ele_novo->Prox=act;
        }
    }
    L->NEL++;
}

/** 13 verificar se um determinado elemento pertence a uma lista (abordagem iterativa)*/
ELEMENTO *pesquisar_iterativo(LISTA *L, ELEMENTO *ele_pesquisa)
{
    if (!L) return NULL;
    if (!ele_pesquisa) return NULL;
    ELEMENTO *P = L->Inicio;
    while(P)
    {
        if (elementos_iguais(P, ele_pesquisa) == 1)
            return P;

        P = P->Prox;
    }
    return NULL;
}

/** 14 verificar se um determinado elemento pertence a lista (abordagem recursiva) */

ptELEMENTO pesquisar_recursivo(ptLISTA L, ptELEMENTO ele_pesquisa)
{



}

/** 14 Feita na aula TP2 29-03 */

ELEMENTO *pertence_Rec(LISTA *l,char *txt)   //PALAVRA *pertence_Rec(NO *p,char *txt)
{
    if(!l) return;

    return  pertence_Rec_NOS(l->Inicio,txt);
}

ELEMENTO *pertence_Rec_NOS(NO *p,char *txt) //PALAVRA *pertence_Rec_NOS(NO *p,char *txt)
{
    if(!p)return NULL;

    if(stricmp(p->Info->TEXTO,txt)==0)
        return p; //return p->Info;

    return pertence_Rec_NOS(p->Prox,txt);

}

/** Ex.15 ver se tem repetidos */
int repetidos(LISTA *l)
{
        if(!l)return 0;
    NO *p=l->Inicio;
    NO *q;

    while(p)
    {
        q=p->Prox;
            while(q)
            {
                if(compararElementos(p,q)==1)
                    return 1;
                q=q->Prox;
            }
        p=p->Prox;
    }
    return 0;
}

/** Ex.15 extra todos_repetidos */

LISTA *todosRepetidos(LISTA *l)
{
    if(!l) return NULL;

    LISTA *listaRepetidos=criarLista("PT");
    NO *p=l->Inicio;
    NO *q;

     while(p)
    {
        q=p->Prox;
            while(q)
            {
                if(compararElementos(p,q)==1)
                {
                 addInicio(listaRepetidos,p->Info);
                // break; para nao ir o mesmo nome para a lista
                }
                q=q->Prox;
            }
        p=p->Prox;
    }
    return listaRepetidos;
}


/** Ex 15 mais eficiente -so funciona se a lista estiver ordenada*/

int elementosRepetidosV2(LISTA *l)
{
    if(!l) return 0;

    ELEMENTO *ref=l->Inicio;

    while(ref->Prox)
    {
        if(elementos_iguais(ref,ref->Prox))
            return 1;
        else
            ref=ref->Prox;
    }
    return 0;
}

int removerPalavra(LISTA *l,char *txt)
{
    printf("[%s] Ainda nao implementada\n",__FUNCTION__);
    return 0;
}


/** Ex 18 remova o primeiro elemento da lista */
 ptELEMENTO remover_primeiro(LISTA *l)
 {
    if(!l)return NULL;
    if(!l->Inicio) return NULL;

    ptELEMENTO prox=l->Inicio;
 }


/** Ex 19 remover o ultimo elemento da lista */
ptELEMENTO remover_ultimo(LISTA *l)
{
    if(!l) return NULL;

    ptELEMENTO ant=NULL;
    ptELEMENTO aux=NULL;
    ptELEMENTO p=l->Inicio;

    while(p->Prox){
        ant=p;
        p=p->Prox;
    }
    aux=p;

    if(ant)
    {
        ant->Prox=NULL;
    }else
    {
        l->Inicio=NULL;
    }
    l->NEL--;

    libertarElemento(aux);

    return p;
}


/** Ex17  remova um determinado elemento de uma lista  (acabar em casa) */

ptELEMENTO remover_elemento(LISTA *l, ptELEMENTO ele_remover)
{

    if(!l)  return NULL;

    int av=1;

    ptELEMENTO ret,ant,act;
        if(l->Inicio == NULL){
            ret=NULL;
        }else{
            ant=act=l->Inicio;
            while(av)
                if(act=NULL)
                    av=0;
                else if(elementos_iguais(act,ele_remover))
                    av=0;
                else{
                    ant=act;
                    act=act->Prox;
                }
              if(act!=NULL){
                ret=act;
                if(l->Inicio==act)
                    l->Inicio=act->Prox;
                else
                    ant->Prox=act->Prox;
                l->NEL--;
                }else
                ret=NULL;
        }
        return ret;
    }


void libertarElemento(ptELEMENTO p)
{
    free(p->Info);
    free(p);
}

/** Ex 22  lista pela ordem inversa (crie uma função recursiva) */
void mostrar_inversa_v1(ptLISTA l)
{
    if(!l) return;
    mostrar_ordenado_inversa(l->Inicio);
}

void mostrar_ordenado_inversa(ptELEMENTO p)
{
    if(!p)  return;

    mostrar_ordenado_inversa(p->Prox);
    mostrarPalavra(p->Info);
}


/**Ex 23 lista pela ordem inversa (não usando recursividade)*/

void mostrar_inversa_v2(ptLISTA l)
{
    if(!l) return;
    if(!l->Inicio) return;

    int i;
    ptELEMENTO *vect;
    vect=(ptELEMENTO *)malloc(l->NEL * sizeof(ptELEMENTO));

    ptELEMENTO p=l->Inicio;
    while(p)
    {
        *vect=p->Info;
        vect++;
        p=p->Prox;

    }
    for(i=0;i<l->NEL;i++)
    {
        mostrarPalavra(*(--vect));
    }
    free (vect);
}


/** Ex 24 que destrua (remova e liberte) todos os elementos de uma lista */

void destruirLista(LISTA *l,int tipo)
{
    if(!l)  return;
    NO *p = l->Inicio;
    NO *aux;
    while (p)
    {
        aux=p->Prox;
            if(tipo==1) //para destruir no a lista principal
                free(p->Info);
        free(p);
        p=aux;
    }
    free(l);
}


/** Ex 30 ordenar os elementos da lista */

void ordenar_lista_v1(ptLISTA l) //fast Bubbleshort
{
    ptELEMENTO p=NULL;
    ptPALAVRA aux;

    if(!l || l->Inicio == NULL)
        return;
    int troca=1;

    for(int i=1;i<l->NEL && troca;i++)
    {
        troca=0;
        p=l->Inicio;
        while(p->Prox != NULL)
        {
            if(compararElementos(p,p->Prox) < 0)
            {
                aux=p->Info;
                p->Info=p->Prox->Info;
                p->Prox->Info=aux;
                troca =1;
            }
            p=p->Prox;
        }
    }
}
