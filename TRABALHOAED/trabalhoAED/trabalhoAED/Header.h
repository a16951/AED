/*
Carlos Baixo 16949
Jo�o Silva 16951
compara��o do tempo de execu��o de opera��es de procura e de
ordena��o implementadas sobre listas ligadas e tabela de hash
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct nodo {
	int numero;
	struct nodo* seguinte;
} nodo;

#define MAX 10000
#define MAXLISTA 10000
nodo *tabela[MAX];
nodo *apLista = NULL;


void inicializaTabela();
int hash(int chave);
void preencheTabela();
void procura(int numProcuras);
nodo *criaLista();
void procuraLista(nodo *apLista, int numProcuras);
