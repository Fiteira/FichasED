#include <stdio.h>
#include <stdlib.h>

int LerInteiro(char *txt)
{
    printf("%s", txt);
    int x;
    scanf("%d", &x);
    return x;
}

float lerFloat(char *txt)
{
    printf("%s", txt);
    float x;
    scanf("%f", &x);
    return x;
}

void lerString(char *txt, char *res)
{
    printf("%s", txt);
    fflush(stdin);
    gets(res);
}

int aleatorio(int min,int max){

    return min+rand()%(max-min + 1);

}