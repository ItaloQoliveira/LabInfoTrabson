
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct{
    int n_conta;
    char n_cliente [50];
    float saldo;
    float limite;
}conta;
typedef struct{
    int n_conta;
    char n_cliente [50];
    float saldo;
}contap;
conta cc[50];
conta auxcc[50];
contap cp[50];
contap auxcp[50];
int contadorc =1;
int contadorcc =0;
int contadorcp = 0;
int contadavez;
void acessarconta();
void acessarcontacc();
void menuacessocc();
void deletarcc();
void depositarcc();
void sacarcc();
void saldocc();
void acessarcontacp();
void menuinicial();
void criarconta();
void criarcontac();
void criarcontap();
void consulta();
void consultacc();
void consultacp();
void excluir();
void listanumeroc();
void listanomeal();
void sacar();
void depositar();

int main (){
    int evitadordelixo;
    for(evitadordelixo=0;evitadordelixo<50;evitadordelixo++){
        cc[evitadordelixo].n_conta=0;
        cp[evitadordelixo].n_conta=0;
    }
    menuinicial();
    return 0;
}

void menuinicial(){
    int op;
    printf("Para acessar sua conta digite 1\nPara criar uma conta digite 2\nPara consulta de contas digite 3.\n");
    scanf("%d",&op);
    switch (op){
    case 1:
       acessarconta(); 
        break;
    case 2:
        criarconta();
        break;
    case 3:
        consulta();
        break;
    default:
        printf("Opção invalida\n");
        menuinicial();
        break;
    }
}
void acessarconta(){
    int op;
    printf("Para acessar conta corrente digite 1\nPara acessar conta poupança digite 2\n");
    scanf("%d",&op);
    switch (op){
    case 1:
        acessarcontacc();
        break;
    case 2:
        acessarcontacp();
        break;
    default:
        menuincial();
        break;
    }
}
void acessarcontacc(){
    char nump[10];
    int i,j,f=0,num=0;
    do{
        j=0;
        printf("Insira o número da sua conta:");
        scanf("\n%[^\n]s",&nump);
        for(i=0;i<strlen(nump);i++){
            if(isdigit(nump[i])==0){
                j=1;
            }
        }
        if (j==0){
            num= atoi(nump);
           for(i=0;i<50;i++){
               if((num==cc[i].n_conta) && (num!=0)){
                   f=1;
                   contadavez=i;
               }
           } 
        
        }
        if(f==0){
            printf("Conta nao existe.\n");
            j=1;

        }

    }while(j==1);
    menuacessocc();
}
void menuacessocc(){
    int op;
    printf("Para depositar digite 1\nPara sacar digite 2\nPara visualizar seu saldo digite 3\nPara retornar ao menu inicial digite 4\nPara deletar a conta atual digite 9\n");
    scanf("%d",&op);
    switch (op){
    case 1:
       depositarcc();
        break;
    case 2:
        sacarcc();
        break;
    case 3:
        saldocc();
        break;
    case 4:
        menuinicial();
        break;
    case 9:
        deletarcc();
    default:
        printf("Opção invalida");
        menuacessocc();
        break;
    }
}
void deletarcc(){
    char op;
    printf("Deseja realmente deletar essa conta? s/n");
    scanf(" %c",&op);
    switch (op)
    {
    case 's':
        cc[contadavez].n_conta=0;
        contadorcc-=1;
        menuinicial();
        break;
    
    default:
        menuacessocc();
        break;
    }

}
void depositarcc(){
    float quantidade;
    printf("Quantidade:");
    scanf("%f",&quantidade);
    cc[contadavez].saldo+=quantidade;
    printf("Deposito de %.2f feito\nNovo saldo é de %.2f\n",quantidade,cc[contadavez].saldo);
    menuacessocc();
}
void sacarcc(){
    float quantidade;
    int z,f,op;
    do{
        z=0;
        printf("Quantidade:");
        scanf("%f",&quantidade);
        if ((cc[contadavez].saldo-quantidade<0) && (cc[contadavez].saldo-quantidade>=-500) ) {
            printf("Aviso, conta no cheque especial\n");
        }
        if(cc[contadavez].saldo-quantidade<-500){
            printf("Limite de saldo insuficiente, insira 1 para mudar o valor ou 2 para voltar ao menu da conta");
            scanf("%d",&op);
            switch (op){
            case 1:
                sacarcc();
                break;
            case 2:
                menuacessocc();
                break;
            default:
                menuacessocc();
                break;
            }
                        
        }
    } while(z==1);
    cc[contadavez].saldo-=quantidade;
    printf("Saque de %f efetuado.\n Novo saldo de:%.2f\n",quantidade,cc[contadavez].saldo);
    menuacessocc();
}
void saldocc(){
    int op;
    printf("Saldo da conta;%.2f\n Insira 1 para voltar ao menu de acesso a conta e 2 para voltar ao menu principal.",cc[contadavez].saldo);
    scanf("%d",&op);
    switch (op){
    case 1:
        menuacessocc();
        break;
    case 2:
        menuinicial();
        break;
    default:
        saldocc();
        break;
    }
}
void acessarcontacp(){
        char nump[10];
    int i,j,f=0,num=0;
    do{
        j=0;
        printf("Insira o número da sua conta:");
        scanf("\n%[^\n]s",&nump);
        for(i=0;i<strlen(nump);i++){
            if(isdigit(nump[i])==0){
                j=1;
            }
        }
        if (j==0){
            num= atoi(nump);
           for(i=0;i<50;i++){
               if((num==cp[i].n_conta) && (num!=0)){
                   f=1;
                   contadavez=i;
               }
           } 
        
        }
        if(f==0){
            printf("Conta nao existe.\n");
            j=1;

        }

    }while(j==1);
    menuacessocp();
}
void menuacessocp(){
    int op;
    printf("Para depositar digite 1\nPara sacar digite 2\nPara visualizar seu saldo digite 3\nPara retornar ao menu inicial digite 4\nPara deletar a conta atual digite 9\n");
    scanf("%d",&op);
    switch (op){
    case 1:
       depositarcp();
        break;
    case 2:
        sacarcp();
        break;
    case 3:
        saldocp();
        break;
    case 4:
        menuinicial();
        break;
    case 9:
        deletarcp();
    default:
        printf("Opção invalida");
        menuacessocp();
        break;
    }
}
void depositarcp(){
    float quantidade;
    printf("Quantidade:");
    scanf("%f",&quantidade);
    cp[contadavez].saldo+=quantidade;
    printf("Deposito de %.2f feito\nNovo saldo é de %.2f\n",quantidade,cp[contadavez].saldo);
    menuacessocp();
}
void sacarcp(){
    float quantidade;
    int z,f,op;
    do{
        z=0;
        printf("Quantidade:");
        scanf("%f",&quantidade);
        if(cp[contadavez].saldo-quantidade<-0){
            printf("Limite de saldo insuficiente, insira 1 para mudar o valor ou 2 para voltar ao menu da conta");
            scanf("%d",&op);
            switch (op){
            case 1:
                sacarcp();
                break;
            case 2:
                menuacessocp();
                break;
            default:
                menuacessocp();
                break;
            }
                        
        }
    } while(z==1);
    cp[contadavez].saldo-=quantidade;
    printf("Saque de %f efetuado.\n Novo saldo de:%.2f\n",quantidade,cp[contadavez].saldo);
    menuacessocp();
}

void saldocp(){
    int op;
    printf("Saldo da conta;%.2f\n Insira 1 para voltar ao menu de acesso a conta e 2 para voltar ao menu principal.",cp[contadavez].saldo);
    scanf("%d",&op);
    switch (op){
    case 1:
        menuacessocp();
        break;
    case 2:
        menuinicial();
        break;
    default:
        saldocp();
        break;
    }
}

void deletarcp(){
    char op;
    printf("Deseja realmente deletar essa conta? s/n");
    scanf(" %c",&op);
    switch (op)
    {
    case 's':
        cp[contadavez].n_conta=0;
        contadorcp-=1;
        menuinicial();
        break;
    
    default:
        menuacessocc();
        break;
    }

}

void criarconta(){
    int op;
    printf("Para conta corrente digite 1\nPara conta poupança digite 2\n");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        criarcontac();
        break;
    case 2:
        criarcontap();
        break;
    default:
        printf("Opção invalida\n");
        break;
    }
}
void criarcontac(){
    char nomep[50];
    int  j,i;
    printf("Sua conta será a conta %04d\n",contadorc);
    cc[contadorcc].n_conta=contadorc;
   do{
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
    strcpy(cc[contadorcc].n_cliente,nomep);
    cc[contadorcc].saldo=0;
    cc[contadorcc].limite=-500;
    contadorc++;
    contadorcc++;
    printf("Cadastro concluido\n");
    menuinicial();
 }
void criarcontap(){
    char nomep[50];
    int  j,i;
    printf("Sua conta será a conta %04d\n",contadorc);
    cp[contadorcp].n_conta=contadorc;
   do{
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
    strcpy(cp[contadorcp].n_cliente,nomep);
    cp[contadorcp].saldo=0;
    contadorc++;
    contadorcp++;
    printf("Cadastro concluido\n");
    menuinicial();
}
void consulta(){
    int op;
    printf("1 Para consultar contas correntes\n 2 Para consultar contas poupança");
    scanf("%d",&op);
    switch(op){
        case 1:
        consultacc();
        case 2:
        consultacp();
        default:
        printf("Opção invalida\n");
        consulta();
    }
}
void consultacc(){
    int op,i,j;
    printf("1 Para consulta pelo nome\n 2 Para consulta pelo número da conta\n");
    scanf("%d",&op);
    if (op==1){
        for(i=0;i<50;i++){
            for(j=i;j<50;j++){
                if(strcmp(cc[i].n_cliente,cc[j].n_cliente)>0){
                    auxcc[1]=cc[i];
                    cc[i]=cc[j];
                    cc[j]=auxcc[1];
                }
            }
        } 
        for(i=0;i<50;i++){
            if(cc[i].n_conta!=0){
                printf("Nome do cliente: %s\nNumero da conta: %d\n",cc[i].n_cliente,cc[i].n_conta);
            }
        }
    }else{
        for(i=1;i<50;i++){
            for(j=0;j<50;j++){
                if(i==cc[j].n_conta){
                    printf("Nome do cliente: %s\nNumero da conta:%d ",cc[j].n_cliente,cc[j].n_conta);
                }
            }
        }
    }
    menuinicial();
}
void consultacp(){
    int op,i,j;
    printf("1 Para consulta pelo nome\n 2 Para consulta pelo número da conta\n");
    scanf("%d",&op);
    if (op==1){
        for(i=0;i<50;i++){
            for(j=i;j<50;j++){
                if(strcmp(cp[i].n_cliente,cp[j].n_cliente)>0){
                    auxcp[1]=cp[i];
                    cp[i]=cp[j];
                    cp[j]=auxcp[1];
                }
            }
        } 
        for(i=0;i<50;i++){
            if(cp[i].n_conta!=0){
                printf("Nome do cliente: %s\nNumero da conta: %d\n",cp[i].n_cliente,cp[i].n_conta);
            }
        }
    }else{
        for(i=1;i<50;i++){
            for(j=0;j<50;j++){
                if(i==cp[j].n_conta){
                    printf("Nome do cliente: %s\nNumero da conta:%d ",cp[j].n_cliente,cp[j].n_conta);
                }
            }
        }
    }
    menuincial();
}

