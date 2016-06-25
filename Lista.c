#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// LISTA DUPLAMENTE ENCADEADA CIRCULAR

typedef struct {
	char Letra;
	int Freq;
}TipoDados;

typedef struct lista{
	TipoDados Item;
	struct lista* Ant;
	struct lista* Prox;
}tLista;

tLista* CriaLista()
{
	tLista* lista = (tLista*)malloc(sizeof(tLista));
	lista->Ant = NULL;
	lista->Prox = NULL;
	lista->Item.Letra = 0;
	lista->Item.Freq = 0;
}
