#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Dado{
	char Letra;
	int Freq;
} TipoDados;
typedef struct lista tLista;

tLista* InitLista(void);

tLista* CriaItem(char letra, int freq);

tLista* InitItem(TipoDados item);

void InsereItem(tLista **lista, tLista *novoItem);

void CopiaLista(char *vetor);

void freeLista(tLista *lista);

tLista *ListaProx(tLista *elemento);

void freeLista(tLista *lista);

tLista *ListaProx(tLista *elemento);

tLista *ListaAnt(tLista *elemento);

char ListaLetra(tLista *elemento);

char DadoLetra(TipoDados elemento);

int ListaFreq(tLista *elemento);

int DadoFreq(TipoDados elemento);

void SetProx(tLista *elemento, tLista *prox);

void SetAnt(tLista *elemento, tLista *ant);
