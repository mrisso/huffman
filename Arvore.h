#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Arv tArvore;

typedef struct tabela tTabela;

tArvore* CriaArvoreVazia(void);

tArvore* CriaArvore(tArvore* dir, tArvore* esq, tLista *Item);

int* PreencheVetor(FILE* Arquivo, int* Vetor);

int compara(const void* v1, const void* v2);

void OrdenaArvore(tArvore* Arvore);

tArvore* MontaArvore(tArvore* Arvore);

tTabela* TabelaCodificada(tArvore *Arvore, tTabela *Tabela, char* Code, int QtdBit);

void Codificacao(FILE* Arquivo, FILE* Saida, tTabela* Tabela, int Quantidade);