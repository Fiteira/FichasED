#ifndef TIPO_DADOS_H_INCLUDED
#define TIPO_DADOS_H_INCLUDED


#define MAX_TIPO_DADO 50

typedef struct
{
    char TEXTO[MAX_TIPO_DADO];

}TIPO_DADO,*ptTIPO_DADO;



TIPO_DADO *criarPalavra(char *txt);


#endif // TIPO_DADOS_H_INCLUDED
