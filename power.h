
/* Mathoian Santos https://github.com/mathoian
 programa: Controle de funcionario
 Assunto:" programa
 Linguagem: C
 SO utilizado: arch linux x64
 versão do compilador: --

 */

#include "stdio.h"
#include "stdlib.h"
//#include <unistd.h>
#include "string.h"

#define VETOR 2 //vetor de funcionarios \0/ \o/ numero de registros
#define TNOME 30 //tam do nome



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
int matricula,mtcl2;
int opcao; //var opcao  do menu()
char sn = 's';  // variavel de decisao de add outro funcionario =]
int contFunc = 0;
int i= 0;
int j = 0;
//======================================== DEFINIÇÃO DE ESTRUTURAS
typedef struct { //data nascimento
int dia;
int mes;
int ano;
} DataNascc;

typedef struct {
int matricula;
char nome [TNOME];
DataNascc dataNasc; // ver struct data de nascimento
float salario;
}Funcionario;



Funcionario funcionario[VETOR];
//DataNascc dataNasc;
void menu();


void erro(){
printf("\nERRO\n");
}
// decisao de retornar ao menu
void returnMenu(){

  setbuf(stdin, NULL); // limpando buffer problematico

  printf("\n\nDeseja retornar ao Menu [s/n] ?  ");
  scanf("%c",&sn);
  if ((sn == 's') || (sn == 'N')) { // retornar ao menu()

  menu();

  }else{
  printf("Feche a tela");
  exit(0);
  }
}

int limpaVetor(){
  char null[]="null";
  for (size_t l = 0; l < VETOR; l++) {
  strcpy(funcionario[l].nome,null);
    funcionario[l].matricula = 0;
    funcionario[l].dataNasc.dia = 0;
    funcionario[l].dataNasc.mes = 0;
    funcionario[l].dataNasc.ano = 0;
    funcionario[l].salario = 0;
return 0;
  }
}
void limpaTela(){ // func limpa tela e limpa o buffer numa unica tacada
   printf("\e[H\e[2J"); // funcao limpar tela
   setbuf(stdin, NULL); // limpando buffer problematico
}


void funcionarioInput(){
  limpaTela();

     while(((sn == 's')||(sn == 'S')) && (contFunc < VETOR)){


          printf("* OPÇÃO INSERIR FUNCIONARIO *\n\n");

          printf("Informe a matricula do funcionario: ");
          scanf("%i",&mtcl2);
          setbuf(stdin, NULL); // limpando buffer problematico

          for (size_t u = 0; u < VETOR; u++) {
             int qtd =0;
            if(mtcl2 == funcionario[u].matricula){
              qtd++;

            }
            if(qtd == 0){
                setbuf(stdin, NULL); // limpando buffer problematico
                funcionario[j].matricula = mtcl2;
                printf("Informe o nome do funcionario ");
                fgets (funcionario[j].nome, 50, stdin);
                printf("Informe o [dia] do nascimento: ");
                scanf("%i",&funcionario[j].dataNasc.dia);
                printf("Informe o [mes] do nascimento: ");
                scanf("%i",&funcionario[j].dataNasc.mes);
                printf("Informe o [ano] do nascimento: ");
                scanf("%i",&funcionario[j].dataNasc.ano);
                printf("Informe o salario do funcionario: ");
                scanf(" %f",&funcionario[j].salario);
                contFunc++;
                j++;
                returnMenu();
            }
            if (qtd >0) {
                printf("\nUsuario ja existe");
            }

            }
          }




          limpaTela();
           menu();
     }

  //


void funcionarioRemove(){
  char null[] = "";

   limpaTela();

    int excluir,qtd = 0;
    printf("Informe o numero de matricula do funcionario  ");
    scanf("%i",&matricula);


    for (size_t l = 0; l < VETOR; l++){

    if (matricula == funcionario[l].matricula){

    strcpy(funcionario[l].nome,funcionario[l+1].nome);
    funcionario[l].matricula = funcionario[l+1].matricula;
    funcionario[l].dataNasc.dia = funcionario[l+1].dataNasc.dia;
    funcionario[l].dataNasc.mes = funcionario[l+1].dataNasc.mes;
    funcionario[l].dataNasc.ano = funcionario[l+1].dataNasc.ano;
    funcionario[l].salario = funcionario[l+1].salario;
    strcpy(funcionario[l+1].nome,null);
    funcionario[l+1].matricula = 0;
    funcionario[l+1].dataNasc.dia = 0;
    funcionario[l+1].dataNasc.mes = 0;
    funcionario[l+1].dataNasc.ano = 0;
    funcionario[l+1].salario = 0;
  }
  if (l == VETOR-1){
    strcpy(funcionario[l].nome,null);
    funcionario[VETOR-1].matricula = 0;
    funcionario[VETOR-1].dataNasc.dia = 0;
    funcionario[VETOR-1].dataNasc.mes = 0;
    funcionario[VETOR-1].dataNasc.ano = 0;
    funcionario[VETOR-1].salario = 0;
  printf("cadastro remivido 1 !");
}
  printf("cadastro remivido !");
  contFunc--;
  j--;
returnMenu();
}
}




int aumentoSal(){

  float aumento;

  scanf("informe  o percentual do aumento salarial");
  scanf("%f",&aumento);

  if (aumento > 0){
    for (size_t h = 0; h < VETOR; h++) {
      funcionario[h].salario += funcionario[h].salario *(aumento/100);
    }
  }else{
    printf("erro aumento salario[valor negativo]");
  }
menu();
}

//ordenaM
void ordenaNome(){
  int aux;
  float faux;
  char saux[TNOME];

  for (size_t l = 0; l < VETOR; l++){
    for (size_t m = 0; m < VETOR; m++){
        if (strcmp(funcionario[l].nome, funcionario[m].nome) < 0){

        strcpy(saux,funcionario[l].nome);
        strcpy(funcionario[l].nome,funcionario[m].nome);
        strcpy(funcionario[m].nome,saux);

        aux = funcionario[l].matricula;
        funcionario[l].matricula = funcionario[m].matricula;
        funcionario[m].matricula = aux;

        aux = funcionario[l].dataNasc.dia;
        funcionario[l].dataNasc.dia = funcionario[m].dataNasc.dia;
        funcionario[m].dataNasc.dia = aux;

        aux = funcionario[l].dataNasc.mes;
        funcionario[l].dataNasc.mes = funcionario[m].dataNasc.mes;
        funcionario[m].dataNasc.mes = aux;

        aux = funcionario[l].dataNasc.dia;
        funcionario[l].dataNasc.ano= funcionario[m].dataNasc.ano;
        funcionario[m].dataNasc.ano = aux;

        faux = funcionario[l].salario;
        funcionario[l].salario = funcionario[m].salario;
        funcionario[m].salario = aux;
      }
    }
  }
}



void ordenaM(){
  int aux;
  float faux;
  char saux[TNOME];

  for (size_t l = 0; l < VETOR; l++){
    for (size_t m = 0; m < VETOR; m++){
      if (funcionario[l].matricula < funcionario[m].matricula){

       strcpy(saux,funcionario[l].nome);
       strcpy(funcionario[l].nome,funcionario[m].nome);
       strcpy(funcionario[m].nome,saux);

       aux = funcionario[l].matricula;
       funcionario[l].matricula = funcionario[m].matricula;
       funcionario[m].matricula = aux;

       aux = funcionario[l].dataNasc.dia;
       funcionario[l].dataNasc.dia = funcionario[m].dataNasc.dia;
       funcionario[m].dataNasc.dia = aux;

       aux = funcionario[l].dataNasc.mes;
       funcionario[l].dataNasc.mes = funcionario[m].dataNasc.mes;
       funcionario[m].dataNasc.mes = aux;

       aux = funcionario[l].dataNasc.dia;
       funcionario[l].dataNasc.ano= funcionario[m].dataNasc.ano;
       funcionario[m].dataNasc.ano = aux;

       faux = funcionario[l].salario;
       funcionario[l].salario = funcionario[m].salario;
       funcionario[m].salario = aux;
      }

    }
  }
}

float calcIRPF(float salario){

  if((salario > 1.903,98) && (salario < 2.826,65)){
    salario -= (salario * 0.75)/100;
  }

  if((salario > 2.826,66) && (salario < 3.751,05)){
    salario -= (salario * 0.15)/100;
  }

  if((salario > 3.751,06) && (salario < 4.664,68)){
    salario -= (salario * 2.25)/100;
  }

  if(salario > 4.664,68){
    salario -= (salario * 2.75)/100;
  }
    return salario;
}

float calcINSS(float salario){

  if(salario < 1.659,38){
      salario -= (salario * 0.08)/100;
    }

  if((salario > 1.659,39) && (salario < 2.765,66)){
      salario -= (salario * 0.09)/100;
    }

  if((salario > 2.765,67) && (salario < 5.531,31)){
    salario -= (salario * 0.11)/100;
   }

    return salario;
}



int buscaFunc(int matricula){
  int ctd = 0; //contador

    printf("Busca do funcionario %i\n\n ",matricula);

  for (size_t h = 0; h < VETOR; h++) {

  if (matricula == funcionario[h].matricula){

      printf("Registro numero: [%i]\n",h+1);
      printf("\nNome do funcionario:  %s",funcionario[h].nome);
      printf("\nMatricula de numero:  %i",funcionario[h].matricula);
      printf("\nData de nascimento:  %i/%i/%i",funcionario[h].dataNasc.dia,funcionario[h].dataNasc.mes,funcionario[h].dataNasc.ano);
      printf("\nSalario em R$: %.6f",calcIRPF(calcINSS(funcionario[h].salario)));
      ctd++;
    }
  }

if (ctd == 0) printf("Matricula %i Nao encontrada!",matricula);
  return matricula;
}



void funcionarioPrint(){
    limpaTela();
 i= 0;
  // while(funcionario[i].nome != "null"){
for (size_t i = 0; i < VETOR; i++) {

      printf("\n----------------------------------------------------------------------\n");
      printf("Registro numero: [%i]",i+1);
      printf("\nNome do funcionario: %s",funcionario[i].nome);
      printf("\nMatricula de numero: %i",funcionario[i].matricula);
      printf("\nData de nascimento: %i/%i/%i",funcionario[i].dataNasc.dia,funcionario[i].dataNasc.mes,funcionario[i].dataNasc.ano);
      printf("\nSalario em R$: %.6f",calcIRPF(calcINSS(funcionario[i].salario)));
   }
 }

 //submenu da opcao de listar
void subMenu(){ //subMenu
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
         ordenaNome();
         menu();
         break;
         case 2:
         printf ("\n\nopcao [%i] \n",opcao);
         ordenaM();
         menu();
         break;
         case 0:
         limpaTela();
         menu();
         break;
    }

}


void menu(){
    limpaTela();


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
        //limpaTela();
         case 1:
            printf ("\n\nopcao: [%i] \n",opcao);
            funcionarioInput();
            break;
         case 2:
            funcionarioRemove();
            break;
         case 3:
            printf ("\n\nopcao: [%i] \n",opcao);
            printf("informe a matricula");
            scanf("%d",&matricula);

            buscaFunc(matricula);
            returnMenu();
            break;
         case 4:
            printf ("\n\nopcao: [%i] \n",opcao);
            aumentoSal();
            break;
         case 5:
            printf ("opcao %i",opcao);
            subMenu(); // case opcao 6 chama sub menu ordena por NOME ou MATRICULA
            returnMenu();
            break;
         case 6:
          //  printf(" ..:TODOS REGISTROS:..\n\n");
          //  printf ("\n\n[Oo_ps! Opcao invalida]\n");

            funcionarioPrint();
            returnMenu();
            //menu();
            break;
         default :
            printf ("\n\n[Oo_ps! Opcao invalida]\n");
            menu();

    }
 }
