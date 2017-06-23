
/* Mathoian Santos https://github.com/mathoian
 programa: Controle de funcionario
 Assunto:" programa
 Linguagem: C
 SO utilizado: arch linux x64
 versão do compilador: --

 */



#include "stdio.h"
#include "stdlib.h"

#define VETOR 3 //vetor de funcionarios
#define TNOME 30 //tam do nome
#define TDNAS 50 // tamanho data de nascimento



//=========================== COR CONSOLE
#define RED   "[31m"
#define GRN   "[32m"
#define YEL   "[33m"
#define BLU   "[34m"
#define MAG   "[35m"
#define CYN   "[36m"
#define WHT   "[37m"
#define RESET "[0m"



//=================================== VARIAVEIS

int opcao; //var opcao  do menu()
char sn = 'n';  // variavel de decisao de add outro funcionario =]
int contFunc = -1;
int i = -1;
//======================================== DEFINIÇÃO DE ESTRUTURAS
typedef struct {
int matricula;
char nome [TNOME];
int dataNasc; // ver struct data de nascimento
float salario;
}Funcionario;

typedef struct { //data nascimento
int dia;
int mes;
int ano;
} DataNascc;

Funcionario funcionario[VETOR];
DataNascc dataNasc;
void menu();

void limpaTela(){ // func limpa tela e limpa o buffer numa unica tacada
  printf("\e[H\e[2J"); // funcao limpar tela
  setbuf(stdin, NULL); // limpando buffer problematico
}

void funcionarioInput(){
  limpaTela();
  do {
    i++;

      //for (int i = 0; i < VETOR; i++) { // pode ser feito sem o laco for() por estar numa funcao.


     printf("* OPÇÃO INSERIR FUNCIONARIO *\n\n");

     printf("Informe o nome do funcionario ");
     scanf(" %[^\n]s",&funcionario[i].nome);

     printf("Informe a matricula do funcionario: ");
     scanf("%i",&funcionario[i].matricula);

     printf("Informe o [dia] do nascimento: ");
     scanf("%i",&dataNasc.dia);
     printf("Informe o [mes] do nascimento: ");
     scanf("%i",&dataNasc.mes);
     printf("Informe o [ano] do nascimento: ");
     scanf("%i",&dataNasc.ano);

     printf("Informe o salario do funcionario: ");
     scanf(" %f",&funcionario[i].salario);


      //}
      // retirar comentario caso queira add e imprimir o funcionario add
      /* for (int i = 0; i < VETOR; i++) { // pode ser feito sem o laco for() por estar numa funcao.
          printf("Nome do funcionario: %s\n",funcionario[i].nome);
          printf("Matricula de numero: %i\n",funcionario[i].matricula);
          printf("Data de nascimento: %i/%i/%i\n",dataNasc.dia,dataNasc.mes,dataNasc.ano);
          printf("Salario em R$: %2.2f",funcionario[i].salario);
       }*/
       printf("\n\n\n\nDeseja inserir outro funcionario? [S/n]\n"); // default [S]
       scanf("%s",&sn);
       limpaTela();
       contFunc++;
    } while(((sn == 's')||(sn == 'S')) && (contFunc < VETOR));

    if(contFunc < VETOR){
      printf("\n\n@ Numero de funcionarios preenhidos @\n\n");
    }



    menu();
}
void funcionarioPrint(){
  printf("Total de registros: [%i]",VETOR);

   for (i = 0; i < VETOR; i++){

     printf("\n----------------------------------------------------------------------\n");
     printf("Registro numero: [%i]",i+1);
      printf("\nNome do funcionario: %s",funcionario[i].nome);
      printf("\nMatricula de numero: %i",funcionario[i].matricula);
      printf("\nData de nascimento: %i/%i/%i",dataNasc.dia,dataNasc.mes,dataNasc.ano);
      printf("\nSalario em R$: %2.2f",funcionario[i].salario);
   }
 }
void subMenu(){
      limpaTela();
     //**** SUB MENU
     printf("\n");
     printf( YEL "                              ## MENU ## \n" RESET);
     printf("\n");
     printf(GRN"                            ESCOLHA A OPÇAO\n" RESET);
     printf("\n");
     printf("                            1 - POR NOME \n");
     printf("                            2 - POR MATRICULA\n");
     printf("                            0 - RETORNAR AO MENU\n");

     printf ("\n");
     printf (GRN" DIGITE OPÇÃO: " RED);
     scanf("%d",&opcao);

     switch (opcao) {
         case 1:
         printf ("\n\nopcao [%i]",opcao);
         break;
         case 2:
         printf ("\n\nopcao [%i] \n",opcao);
         break;
         case 0:
         limpaTela();
         menu();
         break;
    }

     }

void menu(){


     //**** menu
     printf("\n");
     printf( RED"                              ## MENU ## \n" RESET );
     printf("\n");
     printf( WHT "                            ESCOLHA A OPÇAO\n" RESET );
     printf("\n");
     printf("                            1 - INSERIR FUNCIONARIO\n");
     printf("                            2 - REMOVER FUNCIONARIO\n");
     printf("                            3 - CONSULTAR FUNCIONARIO\n");
     printf("                            4 - PROCESSAR AUMENTO\n");
     printf("                            5 - ORDENAR FUNCIONARIO\n");
     printf("                            6 - IMPRIMIR TODOS REGISTROS\n");

     printf ("\n");
     printf ( WHT " DIGITE OPÇÃO: " RED);
     scanf("%d",&opcao);

    switch (opcao) {
      limpaTela();
         case 1:
         printf ("\n\nopcao: [%i] \n",opcao);
         funcionarioInput();
         break;
         case 2:
         printf ("\n\nopcao: [%i] \n",opcao);
         break;
         case 3:
         printf ("\n\nopcao: [%i] \n",opcao);
         break;
         case 4:
         printf ("\n\nopcao: [%i] \n",opcao);
         break;
         case 5:
         printf ("opcao %i",opcao);
         subMenu(); // case opcao 6 chama sub menu ordena por NOME ou MATRICULA
         break;
         case 6:
         printf(" ..:TODOS REGISTROS:..\n\n");
         funcionarioPrint();
         break;
         default :
         printf ("Valor invalido!\n");

     }
 }
