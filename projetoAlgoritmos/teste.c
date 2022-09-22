#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char nome[30];
    int id;
    float saldo;
}cliente;

cliente cadastro(cliente conta);
float deposito(cliente conta);

int main() 
{
    cliente conta[10];
    int temp, j, i = 0, loop = 1;
    char op;

    srand(time(NULL));

    while(loop)
    {
    printf("Bem-vindo!\n\n[1] Cadastrar\n[2] Depositar\n[3] Sacar\n[4] Sair");
    op = getchar();
    fflush(stdin);

    switch (op)
    {
    case '1':
        system("cls");
        conta[i] = cadastro(conta[i]);
        i++;
        break;
    
    case '2':
        system("cls");
        printf("Informe o numero de sua conta corrente: ");
        scanf("%i", temp);
        conta[0].saldo = deposito(conta[0]);
        break;
    
    case '3':
        printf("Erro");
        break;

    case '4':
        loop = 0;
        break;

    default:
        system("cls");
        printf("Opcao invalida!");
        system("pause");
        break;
    }
    fflush(stdin);
    system("cls");
    }

    system("cls");
    printf("Sucesso! %s\n%i\n%f", conta[0].nome, conta[0].id, conta[0].saldo);

    return 0;
}

cliente cadastro(cliente conta)
{
    printf("Informe o seu nome completo: ");
    fgets(conta.nome, 30, stdin);
    conta.id = (rand() % 8999)+1000;
    conta.saldo = 0;
    system("cls");
    printf("Informacoes de Usuario\n- Nome: %s- Numero da conta: %i\n- Saldo: %f\n", conta.nome, conta.id, conta.saldo);
    system("pause");
    return conta;
}

float deposito(cliente conta)
{
    printf("Insira o valor a ser depositado: ");
    scanf("%f", conta.saldo);

    return conta.saldo;
}