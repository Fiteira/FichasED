#include <stdio.h>
#include <stdlib.h>
#include "func.c"



int main(int argc, char const *argv[])
{
    
   

    EDados *Armazem;
    Armazem =CriarEDados("Leandro",0);


   
        int opcao=menu();
        
        do
    {
         opcao = menu();
         switch(opcao)
        {
            case 1: lerFicheiro(Armazem, "Utilizadores.dat");  
                break;
            case 2: ordenarDados(Armazem);  
                break;
            case 3: mostrarEDados(Armazem);  
                break;
            case 4: mostrarEDados(Armazem);  
                break;
            case 5: printf("Total joias: %.2f EUR", totalJoias(Armazem)); 
                break;
            case 6: //pesquisaCodigo(Armazem, lerString("Codigo",codigo));
                break;
            default:
            printf("\nOpcao invalida");
            break;
        }
    //system("cls");
    } while (opcao > 0);
    
    return 0;
}
