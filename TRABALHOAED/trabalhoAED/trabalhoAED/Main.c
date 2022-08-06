/*
Carlos Baixo 16949
João Silva 16951
comparação do tempo de execução de operações de procura e de
ordenação implementadas sobre lista ordenada e tabela de hash
*/

#include "Header.h"

int main(int argc, char* argv[])
{

	nodo *aux;
	int i, chave=0, posicao;
	float iniciotempo, fimtempo, tempo1=0, tempo2=0, tempo3=0, tempo4=0;
	int opcao;
	int numProcuras;
	do {
		printf("[1] - Criar e procurar na Tabela Hash\n");
		printf("[2] - Criar e procurar na Lista Ordenada\n");
		printf("[3] - Comparacao\n");
		printf("[0] - Sair\n");


		scanf_s("%d", &opcao);
		
		if (opcao == 1) {
			printf("==========Criacao da tabela==========\n");
			//Inicializar a tabela
			inicializaTabela();
			iniciotempo = clock();

			//Preenche a tabela com 100.000 chaves e calcula o tempo
			preencheTabela();
			fimtempo = clock();
			tempo1 = (fimtempo - iniciotempo) / CLOCKS_PER_SEC;

			printf("\nCriacao da tabela (seg): %f \n", tempo1);
			printf("Numero de chaves: %d\n", MAX);
			
			

			//Efuetua as operações de procura na tabela e calcula o tempo
			printf("Numero de chaves que deseja procurar: ");
			scanf_s("%d", &numProcuras);
			iniciotempo = clock();
			procura(tabela, numProcuras);
			fimtempo = clock();
			tempo2 = (fimtempo - iniciotempo) / CLOCKS_PER_SEC;
			printf("\n\nOperacoes de procura na tabela de hash (seg): %f \n", tempo2);
			printf("Numero de chaves procuradas: %d", numProcuras);
			system("pause");
			system("cls");
		}
			if (opcao == 2) {
				//Preenche a lista ordenada com 10.000 chaves e calcula o tempo
				iniciotempo = clock();
				apLista = criaLista();
				fimtempo = clock();

				tempo3 = (fimtempo - iniciotempo) / CLOCKS_PER_SEC;
				printf("\nCriacao da lista (seg): %f", tempo3);
				printf("\nNumero de chaves: %d", MAXLISTA);

				//Efetua as operacoes de procura na lista e calcula o tempo
				printf("\nNumero de chaves que deseja procurar: ");
				scanf_s("%d", &numProcuras);

				iniciotempo = clock();
				procuraLista(apLista, numProcuras);
				fimtempo = clock();
				tempo4 = (fimtempo - iniciotempo) / CLOCKS_PER_SEC;
				printf("\nOperacoes de procura na lista ordenada (seg): %f", tempo4);
				system("pause");
				system("cls");
			}

			if (opcao == 3) {
				system("cls");
				printf("=========COMPARACAO========\n");
				printf("\t\tTabela Hash || Lista Ordenada\n");
				
				for (int i = 0; i < 3; i++) {
					printf("\t\t\t    ||\n");
					if (i == 1) {
						printf("CRIACAO(seg):\t  %f  ||\t %f\n", tempo1, tempo4);
						printf("\t\t\t    ||\n");
						printf("\t\t\t    ||\n");
						printf("PROCURA(seg):\t  %f  ||\t %f\n", tempo3, tempo4);
					}
				}
				printf("\n\n\n\n");
				printf("Comparando a criacao de listas ordenadas com tabelas de has ordenada, conseguimos verificar que a tabela de has e mais rapido que a lista.\n");
				printf("Comparando a procura de um numero na lista ordenada e na tabela de has, conseguimos verificar que a tabela de has e mais lenta que a lista.\n");
				printf("\n\n\n\n");
				printf("A lista ordenada demora mais tempo para ser criada pois: para colocar o no na segunda posição primeiro declaramos o no 4  (que está em um lugar qualquer da memória), agora fazemos com que o primeiro apontador deixe apontar para o no 2 e aponte para o novo no (o no 4), e agora fazemos com que o no 4 aponte para o nó 2.");
				system("pause");
				system("cls");
			}
		
	} while (opcao != 0);
		

		
		getchar();
		return 0;
}


//criar lista ordenada
nodo *criaLista()
{
	int i, chave, posicao;
	nodo *novo, *lista, *atual;
	lista = NULL;
	for (i = 1; i <= MAXLISTA; i++)
	{
		chave = (int)(((float)rand() / RAND_MAX) * 1000000);
		novo = (nodo*)malloc(sizeof(nodo));
		novo->numero = chave;

		if (lista == NULL || lista->numero >= chave)
		{
			novo->seguinte = lista;
			lista = novo;
		}
		else
		{
			atual = lista;
			while (atual->seguinte != NULL && atual->seguinte->numero < chave)
			{
				atual = atual->seguinte;
			}
			novo->seguinte = atual->seguinte;
			atual->seguinte = novo;
		}
	}
	return lista;
}



void inicializaTabela()
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		tabela[i] = NULL;
	}
}

void preencheTabela()
{
	int i, posicao, chave;
	nodo *aux;

	for (i = 1; i < MAX; i++)
	{
		chave = (int)(((float)rand() / RAND_MAX) * 1000000);
		posicao = hash(chave);

		aux = (nodo*)malloc(sizeof(nodo));
		aux->seguinte = tabela[posicao];
		aux->numero = chave;
		tabela[posicao] = aux;
		
	}
}


int hash(int chave)
{
	return chave % MAX;
}

void procura(int numProcuras)
{
	int i, posicao, chave;
	nodo *aux;

	for (i = 1; i <= numProcuras; i++)
	{
		chave = (int)(((float)rand() / RAND_MAX) * 1000000);
		posicao = hash(chave);

		aux = tabela[posicao];
		while ((aux != NULL) && (aux->numero != chave)) {
			aux = aux->seguinte;
		}
	}
}

void procuraLista(nodo *apLista, int numProcuras) {
	int i, chave;
	nodo *atual;

	for (i = 1; i <= numProcuras; i++)
	{
		chave = (int)(((float)rand() / RAND_MAX) * 1000000);
		atual = apLista;
		while (atual != NULL && atual->numero != chave)
		{
			atual = atual->seguinte;
		}
	}
}