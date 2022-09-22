#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

void adicionar(int i);
void editar();
void remover();
void visualizar();

char controle[12] = "          \0\n";
char produto[9][12];
int id[9];
int quant[9];
int add[9];

int main()
{
	int op;
	int menu = 1;
	int j;

	char sair;

	for(j=0;j<10;j++)
	{
		strcpy(produto[j], controle);
		id[j] = j+1;
		add[j] = 0;
	}

	while(menu)
	{
		system("cls");
		printf("Selecione uma opcao para continuar:\n\n1-Adicionar\t2-Editar\n3-Remover\t4-Visualizar\n5-Sair\n\n");
  	scanf(" %d", &op);

  	switch(op)
		{
  		case 1:
  			for(j=0;j<10;j++)
  			{
  				if(add[j]==0)
  				{
					add[j] = j+1;
					adicionar(add[j]);
  				break;
  				}
				}
  			
  			break;

			case 2:
				editar();
				break;

			case 3:
				remover();
				break;

			case 4:
				system("cls");
				visualizar();
				printf("\n\nPressione qualquer tecla para continuar.");
				getch();
				break;

			case 5:
				system("cls");
				printf("Tem certeza que deseja sair? Digite 'S' para confirmar ou 'N' para cancelar.");
				scanf(" %c", &sair);

				if(toupper(sair)=='S')
					return 0;

				else if(toupper(sair)=='N');

				else
				{
					system("cls");
					printf("AVISO!\n\nErro. Opcao invalida, pressione qualquer tecla para retornar.\n\n");
					getch();
				}
				break;

			default:
				system("cls");
				printf("AVISO!\n\nErro. Opcao invalida, pressione qualquer tecla para retornar.\n\n");
				getch();
		}
	}
}

void adicionar(int i)
{
	i--;
	if(i>10)
	{
		system("cls");
		printf("AVISO!\nEstoque cheio (10/10).\nPressione qualquer tecla para retornar");
		getch();
	}
	else
	{
			system("cls");
			printf("Digite o nome do produto(maximo de 10 caracteres): ");
    	fflush (stdin);
			fgets(produto[i], 11, stdin);
			produto[i][10] = '\n';
			produto[i][11] = '\0';
			fflush (stdin);
    	printf("Digite a quantidade do produto: ");
    	scanf(" %i", &quant[i]);
		  fflush (stdin);
  }
}

void editar()
{
	int tempId;
	system("cls");
	visualizar();
	printf("\n\nDigite o id do produto que deseja editar: ");
	scanf(" %d", &tempId);
	tempId--;
	system("cls");
	printf("Voce selecionou: %s\n\nDigite a nova quantidade do produto: ", produto[tempId]);
	scanf(" %d", &quant[tempId]);
}

void remover()
{
	int tempId;
	char tempOp;
	
	while(tempOp)
	{
	system("cls");
	visualizar();
	printf("\n\nDigite o id do produto que deseja remover: ");
	scanf(" %d", &tempId);
	tempId--;
	printf("Voce selecionou: %s\n\nDeseja continuar? 'S' para continuar e 'N' para cancelar.\n\n", produto[tempId]);
	scanf(" %c", &tempOp);
	if(toupper(tempOp)=='S')
	{
		strcpy(produto[tempId], controle);
		add[tempId] = 0;
 		tempOp = 0;
	}
	else if(toupper(tempOp)=='N')
	break;
	else
	{
		system("cls");
				printf("AVISO!\n\nErro. Opcao invalida, pressione qualquer tecla para retornar.\n\n");
				getch();
	}
	}
}

void visualizar()
{
  int i;
  printf("|  ID |  Quant.\t  |  Nome\n|-----|-----------|-------------\n");
  for(i=0;i<10;i++)
  {
		if(strcmp(produto[i], controle))
		printf("|  %i  |\t%i\t  |  %s", id[i], quant[i], produto[i]);
	}
	printf("|-----|-----------|-------------");
}
