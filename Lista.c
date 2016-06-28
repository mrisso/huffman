#define NAO_USADO												0
#define USADO													1

#include "Lista.h"

// LISTA DUPLAMENTE ENCADEADA


struct lista{
	TipoDados Item;
	struct lista* Ant;
	struct lista* Prox;
	int flag; //Indica se o nó da lista já foi utilizado
};

void CriaLista(TipoDados *vetor, int tam, tLista **lista)
{
	int i;
	TipoDados aux;
	for(i=0; i<tam; i++)
	{		
		aux = vetor[i];
		printf("%c - %d\n", aux.Letra, aux.Freq);
		InsereItem(lista, InitItem(aux));
	}
}

TipoDados* ArmazenaLetras(char* String, long tamanho)
{
	TipoDados* Vetor = (TipoDados*)malloc(256*sizeof(TipoDados)); // Vetor com o tamanho da AscII
	int i, j, k=0;
	int freq=0;
	for(i=0; i<255; i++)
	{
		for(j=0; j<(tamanho); j++)
		{
			if(String[j] == i)
				freq++;
		}
		
		if(freq != 0)
		{
			Vetor[k].Letra = i;
			Vetor[k].Freq = freq;
			k++;
		}
		else
		{
			Vetor[k].Letra = '\0';
			Vetor[k].Freq = 0;	
		}
		
		freq = 0;
	}
	return Vetor;
}

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
	return lista;
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
		*lista = novoItem; //Novo item é o primeiro item
	}
	
	else
	{
		while(andador->Prox != NULL)
			andador = andador->Prox; //Ir até o fim da lista
		
		andador->Prox = novoItem; //Adicionar ao fim da lista
		novoItem->Ant = andador; //Campo anterior do novo item é o antigo útlimo item
	}

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

int compara (const void *v1, const void *v2)
{
	int d1, d2;

	d1 = ((const TipoDados *) v1)->Freq;
	d2 = ((const TipoDados *) v2)->Freq;
	
	return d1 - d2;
}

tLista *operaLista(tLista *lista, int tam)
{
	tLista *andador = lista;

	if(andador == NULL)
		return NULL;

	

}

void ordenaVetor(TipoDados *vetor, int tam)
{
	qsort(vetor,tam,sizeof(TipoDados),compara);
}
