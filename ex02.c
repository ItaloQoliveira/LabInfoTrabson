#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct{
    int dia;
    int mes;
    int ano;
}data; 
typedef struct{
    char rua[50];
    char numero[50];
    char bairro[50];
    char cep[50];
    char cidade[50];
    char estado[50];
    int codestado; 
}infoendereco;
typedef struct{
    char nome[50];
    char pnome[50];
    char mail[50];
    data aniversario;
    infoendereco endereco;
    char telefone[50];
    char obs[50];
}agenda;
agenda agendinha [100];
agenda limpadora;
agenda auxiliar;
int contador=0;
void cadastro();
void limpabuffer(void);
void menubuscas();
void buscapnome();
void Buscapmes();
void buscaptel();
void listanome();
void menulistagem();
void listagem1();
void listagem2();
void listagem3();
void excluir();
int main(){
    int op;
    printf("Aperte 1 para cadastros-2 para funções de busca-3 para funções de listagem e 4 para deletar alguém da agenda ");
    scanf("%d",&op);
    switch (op){
    case 1:
        cadastro();
        break;
    case 2:
        menubuscas();
        break;
    case 3:
        menulistagem();
        break;
    case 4:
        excluir();
        break;
    default:
        main();
        break;
    }
}
void cadastro(){
    char nomep[50];
    int j,i,arroba=0,estado;
     do{ //cadastrar o nome
       printf("Informe seu nome:");
       j=0;
        scanf("\n%[^\n]s",&nomep);
       for(i=0;i<(strlen(nomep));i++){
         if((isalpha(nomep[i])==0) && ((nomep[i])!=32)){
                j=1;
            }
       }
   }while(j==1);
    for(i=0;i<strlen(nomep);i++){
       nomep[i]=toupper(nomep[i]);
    }
    strcpy(agendinha[contador].nome,nomep);

    do{
        j=0;
        printf("Insira o email\n");
        scanf("\n%[^\n]s",&nomep);
        for(i=0;nomep[i]!='@';i++){
            arroba=i;
        }
        if(arroba<strlen(nomep)){ //se possui um @
            if(arroba<=2){ //Se possui mais de 2 digitos antes do @
                if((nomep[strlen(nomep-1)]=='m') &&(nomep[strlen(nomep)-2]=='o')  &&(nomep[strlen(nomep)-3]=='c')){

                }else{
                    j=1;
                }
            } 
            
        }else{
            j=1;
        }
   } while (j==1);
    strcpy(agendinha[contador].mail,nomep);
    printf("Insira a rua\n");    
    scanf("\n%[^\n]s",&agendinha[contador].endereco.rua);
    printf("Insira o numero\n");
    scanf("\n%[^\n]s", &agendinha[contador].endereco.numero);
    printf("Insira o bairro\n");
    scanf("\n%[^\n]s",&agendinha[contador].endereco.bairro);
    do{
        j=0;
        printf("Insira o CEP, com o -\n");
        scanf("\n%[^\n]s",&nomep);
        if(nomep[5]=='-'){

        }else{
            j=1;
        }
         
    } while (j==1);
    strcpy(agendinha[contador].endereco.cep,nomep);
    printf("Insira a cidade\n");
    
    scanf("\n%[^\n]s", &agendinha[contador].endereco.cidade);
    do{
        j=0;
        printf("Insira o estado\n");
        scanf("\n%[^\n]s",&nomep);
        if(strcmp(nomep,"AC")==0){
            agendinha[contador].endereco.codestado=1;
        }else if(strcmp(nomep,"AL")==0){
            agendinha[contador].endereco.codestado=2;
        }else if(strcmp(nomep,"AP")==0){
            agendinha[contador].endereco.codestado=3;
        }else if(strcmp(nomep,"AM")==0){
            agendinha[contador].endereco.codestado=4;
        }else if(strcmp(nomep,"BA")==0){
            agendinha[contador].endereco.codestado=5;
        }else if(strcmp(nomep,"CE")==0){
            agendinha[contador].endereco.codestado=6;
        }else if(strcmp(nomep,"DF")==0){
            agendinha[contador].endereco.codestado=7;
        }else if(strcmp(nomep,"ES")==0){
            agendinha[contador].endereco.codestado=8;
        }else if(strcmp(nomep,"GO")==0){
            agendinha[contador].endereco.codestado=9;
        }else if(strcmp(nomep,"MA")==0){
            agendinha[contador].endereco.codestado=10;
        }else if(strcmp(nomep,"MT")==0){
            agendinha[contador].endereco.codestado=11;
        }else if(strcmp(nomep,"MS")==0){
            agendinha[contador].endereco.codestado=12;
        }else if(strcmp(nomep,"MG")==0){
            agendinha[contador].endereco.codestado=13;
        }else if(strcmp(nomep,"PA")==0){
            agendinha[contador].endereco.codestado=14;
        }else if(strcmp(nomep,"PB")==0){
            agendinha[contador].endereco.codestado=15;
        }else if(strcmp(nomep,"PR")==0){
            agendinha[contador].endereco.codestado=16;
        }else if(strcmp(nomep,"PE")==0){
            agendinha[contador].endereco.codestado=17;
        }else if(strcmp(nomep,"PI")==0){
            agendinha[contador].endereco.codestado=18;
        }else if(strcmp(nomep,"RJ")==0){
            agendinha[contador].endereco.codestado=19;
        }else if(strcmp(nomep,"RN")==0){
            agendinha[contador].endereco.codestado=20;
        }else if(strcmp(nomep,"RS")==0){
            agendinha[contador].endereco.codestado=21;
        }else if(strcmp(nomep,"RO")==0){
            agendinha[contador].endereco.codestado=22;
        }else if(strcmp(nomep,"RR")==0){
            agendinha[contador].endereco.codestado=23;
        }else if(strcmp(nomep,"SC")==0){
            agendinha[contador].endereco.codestado=24;
        }else if(strcmp(nomep,"SP")==0){
            agendinha[contador].endereco.codestado=25;
        }else if(strcmp(nomep,"SE")==0){
            agendinha[contador].endereco.codestado=26;
        }else if(strcmp(nomep,"TO")==0){
            agendinha[contador].endereco.codestado=27;
        }else{
            j=1;
        }
        
    } while (j==1);
    char num[50],ddd[50];
    int l;
    do{
        j=0;
        printf("Insira número do telefone, formato(XX)XXXXX-XXXX\n");
        scanf("\n%[^\n]s",&num);
        if((num[0]=='(') && (num[0]==')') && (num[9]=='-')){
        
        }else{
            j==1;
        }
       
    } while (j==1);
    strcpy(agendinha[contador].telefone,num);
    do{
        j=0;
        printf("Insira o dia do aniversário\n");
        scanf("%d",&i);
        if(i>30 || i<1){
            j=1;
        }
    } while (j==1);
    agendinha[contador].aniversario.dia=i;
    do{
        j=0;
        printf("Insira o mes do aniversário\n");
        scanf("%d",&i);
        if(i>12 || i<1){
            j=1;
        }
    } while (j==1);
    agendinha[contador].aniversario.mes=i;
    do{
        j=0;
        printf("Insira o ano do aniversário\n");
        scanf("%d",&i);
        if(i<1900){
            j=1;
        }
    } while (j==1);
    agendinha[contador].aniversario.ano=i;
    printf("Observação\n");
    scanf("\n%[^\n]s",&agendinha[contador].obs);
    printf("CADASTRO EFETUADO\n");
    contador++;
    main();
}

void menubuscas(){
    int op;
    printf("1Para buscar pelo primeiro nome\n2 para buscar pelo mês de aniversário\n3 para buscar por número de telefone\n 4 listar o nome de todos os cadastrados.");
    scanf("%d",&op);
    switch (op){
    case 1:
       buscapnome();
        break;
    case 2:
        Buscapmes();
        break;
    case 3:
        buscaptel();
        break;

    case 4:
        listanome();
        break;    
    default:
        printf("Opção inválida\n");
        menubuscas();
        break;
    }
}
void buscapnome(){
    int i,j;
    char querochorar[50];
    for(i=0;i<=contador;i++){
        for(j=0;agendinha[i].nome[j]!=' ';j++){
            agendinha[i].pnome[j]=agendinha[i].nome[j];
        }
    }
    printf("Qual nome buscar?\n");
    scanf("\n%[^\n]s",&querochorar);
    for(i=0;i<=contador;i++){
        if(strcmp(agendinha[i].pnome,querochorar)==0){
            printf("Nome:%s\nEmail:%s\nAniversário:%d/%d/%d\n",agendinha[i].nome,agendinha[i].mail,agendinha[i].aniversario.dia,agendinha[i].aniversario.mes,agendinha[i].aniversario.ano);
            printf("Rua:%s\nNumero:%s\nBairro:%s\nCep:%s\nCidade:%s\nEstado:%s\n",agendinha[i].endereco.rua,agendinha[i].endereco.numero,agendinha[i].endereco.bairro,agendinha[i].endereco.cep,agendinha[i].endereco.cidade,agendinha[i].endereco.estado);
            printf("Telefone:%s\n OBS:%s",agendinha[i].telefone,agendinha[i].obs);
        }
    }
    main();
}
void Buscapmes(){
    int i,j;
    char sadboy2001[50];
    printf("Qual mês buscar?\n");
    scanf("\n%[^\n]s",&sadboy2001);
    for(i=0;i<=contador;i++){
        if(agendinha[i].aniversario.mes==sadboy2001){
            printf("Nome:%s\nEmail:%s\nAniversário:%d/%d/%d\n",agendinha[i].nome,agendinha[i].mail,agendinha[i].aniversario.dia,agendinha[i].aniversario.mes,agendinha[i].aniversario.ano);
            printf("Rua:%s\nNumero:%s\nBairro:%s\nCep:%s\nCidade:%s\nEstado:%s\n",agendinha[i].endereco.rua,agendinha[i].endereco.numero,agendinha[i].endereco.bairro,agendinha[i].endereco.cep,agendinha[i].endereco.cidade,agendinha[i].endereco.estado);
            printf("Telefone:%s\n OBS:%s",agendinha[i].telefone,agendinha[i].obs);
  
        }
    }
    main();
}

void buscaptel(){
    int i,j;
    char num;
    printf("Qual telefone buscar?(xx)xxxxx-xxxx");
    scanf("\n%[^\n]s",&num);
    for(i=0;i<=contador;i++){
        if(strcmp(agendinha[i].telefone,num)==0){
            printf("Nome:%s\nEmail:%s\nAniversário:%d/%d/%d\n",agendinha[i].nome,agendinha[i].mail,agendinha[i].aniversario.dia,agendinha[i].aniversario.mes,agendinha[i].aniversario.ano);
            printf("Rua:%s\nNumero:%s\nBairro:%s\nCep:%s\nCidade:%s\nEstado:%s\n",agendinha[i].endereco.rua,agendinha[i].endereco.numero,agendinha[i].endereco.bairro,agendinha[i].endereco.cep,agendinha[i].endereco.cidade,agendinha[i].endereco.estado);
            printf("Telefone:%s\n OBS:%s",agendinha[i].telefone,agendinha[i].obs);

        }
    }
    main();    
}
void listanome(){
    int i,j;
    for(i=0;i<=contador;i++){
        for(j=i;j<=contador;j++){
            if(strcmp(agendinha[i].nome,agendinha[j].nome)>0){
                auxiliar=agendinha[i];
                agendinha[i]=agendinha[j];
                agendinha[j]=auxiliar;
            }
        }

    }
    for(i=0;i<=contador;i++){
        printf("%s\n",agendinha[i].nome);
    }
    main();
}
void menulistagem(){
    int op;
    printf("Opções de listagem\n1_e-mail,telefone,nome(ordem alfabetica)\n2_e-mail,telefone,nome(região)\n3-Tudo(ordem alfabetica)\n");
    scanf("%d",&op);
    switch (op){
    case 1:
        listagem1();
        break;
    case 2:
       listagem2();
        break;
    case 3:
        listagem3();
        break; 
    default:
        printf("Op invalida\n");
        main();
        break;
    }
}

void listagem1(){
    int i,j;
     for(i=0;i<=contador;i++){
        for(j=i;j<=contador;j++){
            if(strcmp(agendinha[i].nome,agendinha[j].nome)>0){
                auxiliar=agendinha[i];
                agendinha[i]=agendinha[j];
                agendinha[j]=auxiliar;
            }
        }

    }
    for(i=0;i<=contador;i++){
        printf("E-mail:%s\nNome:%s\nTelefone:%s",agendinha[i].mail,agendinha[1].nome,agendinha[i].telefone);
    }
    main();
}
void listagem2(){
    int i,j;
    for(j=1;j<28;j++){
        for(i=0;i<=contador;i++){
            if(agendinha[i].endereco.codestado==j){
                printf("E-mail:%s\nNome:%s\nTelefone:%s",agendinha[i].mail,agendinha[1].nome,agendinha[i].telefone);

            }
        }
    }
    main();
}

void listagem3(){
    int i,j;
    for(i=0;i<=contador;i++){
        for(j=i;j<=contador;j++){
            if(strcmp(agendinha[i].nome,agendinha[j].nome)>0){
                auxiliar=agendinha[i];
                agendinha[i]=agendinha[j];
                agendinha[j]=auxiliar;
            }
        }

    }
    for(i=0;i<=contador;i++){
        printf("Nome:%s\nEmail:%s\nAniversário:%d/%d/%d\n",agendinha[i].nome,agendinha[i].mail,agendinha[i].aniversario.dia,agendinha[i].aniversario.mes,agendinha[i].aniversario.ano);
        printf("Rua:%s\nNumero:%s\nBairro:%s\nCep:%s\nCidade:%s\nEstado:%s\n",agendinha[i].endereco.rua,agendinha[i].endereco.numero,agendinha[i].endereco.bairro,agendinha[i].endereco.cep,agendinha[i].endereco.cidade,agendinha[i].endereco.estado);
        printf("Telefone:%s\n OBS:%s",agendinha[i].telefone,agendinha[i].obs);
  

    }
    main();
}
void excluir(){
    int i,j;
    char exnamorada[50];
    printf("Nome escolhido para sumir:");
    scanf("\n%[^\n]s",&exnamorada);
    for(i=0;i<=100;i++){
        if(strcmp(exnamorada,agendinha[i].nome)){
            agendinha[i]=limpadora;
            for(j=1;j<100;j++){
                agendinha[j]=agendinha[j+1];
            }
        }
    }   
    contador--; 
    main();
}
