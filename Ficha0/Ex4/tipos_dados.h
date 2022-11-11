
typedef struct data{
    int dia,mes,ano;
}DATA;

typedef struct pessoa
{
    int cc;
    float altura ,peso;
    char genero;
    DATA dtn;
    char nome[50];
}PESSOA;

PESSOA *criarVetorPessoa(int n);
void preencherVetorPessoa(PESSOA *v,int n);
void escreverVetorPessoa(PESSOA *v,int n);
int mostrarVetorPessoaIMC(PESSOA *v,int n,float inf,float sup );
int mesComMaisNascimentos(PESSOA *v,int n);
float mediaIMCentreDoisAnos(PESSOA *v,int n,int anoMin,int anoMax);
void destruirVetorPessoa(PESSOA *v);