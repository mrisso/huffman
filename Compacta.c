#define DEBUG				0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Lista.h"

long TamanhoArquivo(const char *Arq_in);
void LeArquivo(FILE* entrada, char* Vetor, long tamanho);
void ordenaVetor(TipoDados *vetor, int tam);

int main(int argc, char** argv)
{
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
	const char *Arq_in = argv[1];
	long tamanho = TamanhoArquivo(Arq_in);
	
	printf("%ld\n", tamanho);
	int i=0;
	char Vetor[tamanho];
	int tam=0;
	TipoDados* Dados = NULL;
	tLista* Lista = NULL;

	LeArquivo(entrada, Vetor, tamanho);

	Dados = ArmazenaLetras(Vetor, tamanho);
	
	for(i=0; i<255; i++)
		if(Dados[i].Freq > 0)
			tam++; // tamanho do vetor Dados do tipo estrutura TipoDados;

	ordenaVetor(Dados,tam);

	printf("%s\n",Vetor);

	if(DEBUG)
		for(i=0;i<tam;i++)
			printf("%c %d\n",Dados[i].Letra,Dados[i].Freq);
	
	CriaLista(Dados, tam, &Lista); 
	
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

void LeArquivo(FILE* entrada, char* Vetor, long tamanho)
{
	fread(Vetor, sizeof(char), tamanho, entrada);
}

