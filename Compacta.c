#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"

long TamanhoArquivo(const char *Arq_in);
void LeArquivo(FILE* entrada, char* Vetor);

int main(int argc, char** argv)
{
	const char *Arq_in = "teste.txt";
	long tamanho = TamanhoArquivo(Arq_in);
	FILE* entrada;
	
	if(argc != 2)
	{
		printf("Arquivo de entrada não fornecido\n");
		return 0;
	}
	entrada = fopen(argv[1], "rt");
	if(entrada == NULL)
	{
		printf("Erro na abertura do arquivo\n");
		return 0;
	}
	int i=0;
	char Vetor[tamanho];
	printf("%ld\n", tamanho);
	LeArquivo(entrada, Vetor);

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

void LeArquivo(FILE* entrada, char* Vetor)
{
	while((fgets(Vetor, sizeof(Vetor), entrada)) != NULL)
		printf("%s", Vetor);
}	

void CriaLista(TipoDados *vetor, int tam, tLista **lista)
{
	int contador;

	for(contador=0;contador<tam;contador++)			
		InsereItem(lista,InitItem(vetor[contador]));
}
