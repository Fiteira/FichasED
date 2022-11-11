

typedef struct
{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct
{
    char nome[50];
    char utilizador[20];
    char password[20];
    float joia; //caucao
    DATA data_registo;
    char email[30];
    char pagina_web_pessoal[50];
    int telemovel;
    int numero_acessos;
    DATA data_ultimo_acesso;
}USER;

typedef struct 
{
    char Autor[50];
    USER *dados;
    int NEL;

}EDados;



