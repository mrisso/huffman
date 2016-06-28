#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Dado{
	char Letra;
	int Freq;
} TipoDados;
typedef struct lista tLista;

void CriaLista(TipoDados *vetor, int tam, tLista **lista);

TipoDados* ArmazenaLetras(char* String, long tamanho);

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

int compara (const void *v1, const void *v2);

tLista *merge(tLista *m1, tLista *m2);

void listaToVetor(tLista *lista, TipoDados *vetor, int tam);

void vetorToLista(tLista **lista, TipoDados *vetor, int tam);

void operaLista(tLista **lista, int tam);

void ordenaVetor(TipoDados *vetor, int tam);
