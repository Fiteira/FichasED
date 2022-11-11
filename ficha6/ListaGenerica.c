
#include "ListaGenerica.h"

Lista_Generica *Criar_Lista_Generica()
{
    Lista_Generica *L = (Lista_Generica *)malloc(sizeof(Lista_Generica));
    L->Inicio = NULL;
    L->NEL = 0;
    return L;
}
void Add_LG(Lista_Generica *L, void *X)
{
    if (!L) return;
    NOG *Aux = (NOG *)malloc(sizeof(NOG));
    Aux->Info = X;
    Aux->Prox = L->Inicio;
    L->Inicio = Aux;
    L->NEL++;
}
void Add_Ordenado_LG(Lista_Generica *L, void *X, int (*func_comparar)(void*, void*))
{
    if(!L || !X) return;



}
void Destruir_LG(Lista_Generica *L, void (*fdestruir)(void *))
{
    if (!L) return;
    NOG *P = L->Inicio;
    NOG *Aux = NULL;
    while (P)
    {
        Aux = P->Prox;
        fdestruir (P->Info);
        free (P);
        P = Aux;
    }
    free(L);
}

void Mostrar_LG(Lista_Generica *L, void (*f)(void *))
{
    if (!L) return;
    NOG *P = L->Inicio;
    while (P)
    {
        f(P->Info);
        P = P->Prox;
    }
}
void Gravar_LG(Lista_Generica *L, void (*f)(void *, FILE *), FILE *F)
{
    if (!L) return;
    NOG *P = L->Inicio;
    while (P)
    {
        f(P->Info, F);
        P = P->Prox;
    }
}

void * Pesquisar_LG(Lista_Generica *L, int (*fcomp)(void *, void *), void *valor)
{
    if (!L) return NULL;
    NOG *P = L->Inicio;
    while (P)
    {
        if (fcomp(P->Info, valor) == 1)
            return P->Info;
        P = P->Prox;
    }
    return NULL;
}

void RemoverElementoLG(Lista_Generica *L, void * ele_remover, void (*func_remover) (void*), int (*func_comparar) (void*, void*))
{
    if( !L || !ele_remover || !L->Inicio) return;

    int STOP = 0;

    NOG * P = L->Inicio;
    NOG * anterior = NULL;

    // Procura o elemento até acabar a lista
    while(P && !STOP)
    {
        if(func_comparar(P->Info, ele_remover))
        {
            STOP = 1;
        }
        else
        {
            anterior = P;
            P = P->Prox;
        }
    }

    // caso encontre o elemento
    if(STOP)
    {
        // CASO SEJA  O PRIMEIRO
        if(func_comparar(P, L->Inicio))
        {
            RemoverPrimeiroLG(L, func_remover);
        }
        // CASO SEJA O ULTIMO
        else if(!P->Prox)
        {
            RemoverUltimoLG(L, func_remover);
        }
        // CASO ESTEJA NO MEIO
        else
        {
            anterior->Prox = P->Prox;
            func_remover(P->Info);
            free(P);
        }
        L->NEL--;
    }
    else
    {

    }

}

void RemoverPrimeiroLG(Lista_Generica *L, void (*func_remover) (void*))
{
    if (!L) return;
    if(!L->Inicio) return;
    NOG *primeiro = L->Inicio;
    if(!primeiro->Prox)
    {
        func_remover(primeiro->Info);
        free(primeiro);
        L->Inicio = NULL;
    }
    else
    {
        L->Inicio = primeiro->Prox;
        func_remover(primeiro->Info);
        free(primeiro);
    }
    L->NEL--;
}
// TODO: ARRUMAR ESSA FUNÇÃO
/** \brief
 *
 * \param L ListaGenerica*
 * \param (*func_remover void
 * \return void
 *
 */
void RemoverUltimoLG(Lista_Generica *L, void (*func_remover) (void*))
{
    if (!L) return;
    if(!L->Inicio) return;

    NOG *P = L->Inicio;
    NOG * proximo = NULL;

    // Caso não seja o unico elemento da lista
    if(P->Prox)
    {
        proximo = P->Prox;
        // vai até o fim da lista
        while(proximo->Prox)
        {
            P = proximo;
            proximo = proximo->Prox;
        }
        P->Prox = NULL;

        // TODO: AJUSTAR
        // ATENÇÃO: ERRO AQUI!!!!!
        // func_remover(proximo->Info);
        free(proximo);
    }
    else
    {
        // caso seja o unico elemento da lista
        func_remover(P->Info);
        free(P);
        L->Inicio = NULL;
    }

    L->NEL--;
}
