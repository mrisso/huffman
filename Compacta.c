#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"

long TamanhoArquivo(const char *Arq_in);
char* LeArquivo(FILE* entrada, char* Vetor, long tamanho);
void CriaLista(TipoDados *vetor, int tam, tLista **lista);
TipoDados* ArmazenaLetras(char* String, long tamanho);

int main(int argc, char** argv)
{
	const char *Arq_in = "teste.txt";
	long tamanho = TamanhoArquivo(Arq_in);
	
	FILE* entrada;
	if(argc != 2){
		printf("Arquivo de entrada não fornecido\n");
		return 0;
	}
	entrada = fopen(argv[1], "rt");
	if(entrada == NULL){
		printf("Erro na abertura do arquivo\n");
		return 0;
	}

	int i=0;
	char Vetor[tamanho];
	char* string;
	TipoDados* Dados;
	printf("%ld\n", tamanho);
	string = LeArquivo(entrada, Vetor, tamanho);
//printf("%s\n", string);
	Dados = ArmazenaLetras(Vetor, tamanho);

	for(i=0; i<255; i++)
	{
		if(Dados[i].Letra != '\0' && Dados[i].Freq != 0)
			printf("%c - %d\n", Dados[i].Letra, Dados[i].Freq);
	}
	fclose(entrada);
	return 0;
}

long TamanhoArquivo(const char *Arq_in)
{
  long Tamanho;
  FILE *arquivo = fopen(Arq_in, "rb");
  fseek(arquivo, 0, SEEK_END);
  Tamanho = ftell(arquivo);
  fclose(arquivo);
  return Tamanho;
}

char* LeArquivo(FILE* entrada, char* Vetor, long tamanho)
{
	while(!feof(entrada))
		return fgets(Vetor, tamanho, entrada);
}

TipoDados* ArmazenaLetras(char* String, long tamanho)
{
	TipoDados* Vetor = (TipoDados*)malloc(256*sizeof(TipoDados)); // Vetor com o tamanho da AscII
	int i, j, k=0;
	int freq=0;
	for(i=0; i<255; i++)
	{
		for(j=0; j<(tamanho-1); j++)
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
void CriaLista(TipoDados *vetor, int tam, tLista **lista)
{
	int contador;

	for(contador=0;contador<tam;contador++)
	{		
		InsereItem(lista, InitItem(vetor[contador]) );
	}
}
