typedef struct uc
{
    char nomeUC[20];
    float nota;
}UC;


typedef struct aluno
{
    int n_mecanografico;
    char nome[20];
    UC uc[5];
}ALUNO;



ALUNO *alocarAlunos(int n);
void ListAluno(ALUNO *v,int n);
void calcularMedia(ALUNO *v,int n);
float numeroMedioUC(ALUNO *v,int n,int lim);
void listaNotas(ALUNO *v,int n,int val,char *nomeFich);
void escreverAluno(ALUNO *v,int n);