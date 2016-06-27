#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Dado TipoDados;
typedef struct lista tLista;

tLista* InitLista(void);

tLista* CriaItem(char letra, int freq);

void InsereItem(tLista **lista, tLista *novoItem);

void CopiaLista(char *vetor);

void freeLista(tLista *lista);

tLista *ListaProx(tLista *elemento);

void freeLista(tLista *lista);

tLista *ListaProx(tLista *elemento);

tLista *ListaAnt(tLista *elemento);

char ListaLetra(tLista *elemento);

int ListaFreq(tLista *elemento);

void SetProx(tLista *elemento, tLista *prox);

void SetAnt(tLista *elemento, tLista *ant);
