#include "Lista.h"

// LISTA DUPLAMENTE ENCADEADA CIRCULAR


struct lista{
	TipoDados Item;
	struct lista* Ant;
	struct lista* Prox;
};

tLista* InitLista(void)
{
	return NULL;
}

tLista* CriaItem(char letra, int freq) // Recebe a letra e a frequência do item e já inicializa
{
	tLista* lista = (tLista*)malloc(sizeof(tLista));
	lista->Ant = NULL;
	lista->Prox = NULL;
	lista->Item.Letra = letra; // <-
	lista->Item.Freq = freq; // <-
}

tLista* InitItem(TipoDados item)
{
	tLista* lista = (tLista*)malloc(sizeof(tLista));
	lista->Ant = NULL;
	lista->Prox = NULL;
	lista->Item = item;
	return lista;
}

void InsereItem(tLista **lista, tLista *novoItem)
{
	tLista *andador = *lista;

	if(andador==NULL) //Caso lista vazia
	{
		// -> Lista de item único <-
		*lista=novoItem; //Novo item é o primeiro item
		novoItem->Ant = *lista; //Novo item é o anterior (lista circular)
		novoItem->Prox = *lista; //Novo item é o próximo (lista circular)
	}
	
	else
	{
		while(andador->Prox!=*lista)
			andador=andador->Prox; //Ir até o fim da lista
		andador->Prox = novoItem; //Adicionar ao fim da lista
		novoItem->Ant = andador; //Campo anterior do novo item é o antigo útlimo item
		(*lista)->Ant = novoItem; //Campo anterior do primeiro item da lista aponta para o último item (novo)
	}

	novoItem->Prox=*lista; //Último Item da Lista aponta para o primeiro

}

void freeLista(tLista *lista)
{
	tLista *aux, *prox;

	aux = lista; //Recebe primeira posição

	prox = aux->Prox;
	free(aux); //Libera primeira posição
	aux = prox;

	/* Libera até que o campo Prox da célula visitada seja igual ao endereço da primeira posição da lista
	 * (último elemento da lista aponta para o primeiro por ser uma lista circular) */
	while(aux!=lista)
	{
		prox = aux->Prox;
		free(aux);
		aux = prox;
	}
}

tLista *ListaProx(tLista *elemento)
{
	return elemento->Prox;
}

tLista *ListaAnt(tLista *elemento)
{
	return elemento->Ant;
}

char ListaLetra(tLista *elemento)
{
	return elemento->Item.Letra;
}

int ListaFreq(tLista *elemento)
{
	return elemento->Item.Freq;
}

void SetProx(tLista *elemento, tLista *prox)
{
	elemento->Prox = prox;
}

void SetAnt(tLista *elemento, tLista *ant)
{
	elemento->Ant = ant;
}

char DadoLetra(TipoDados elemento)
{
	return elemento.Letra;
}

int DadoFreq(TipoDados elemento)
{
	return elemento.Freq;
}
