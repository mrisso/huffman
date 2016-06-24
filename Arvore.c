#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ARVORE BINARIA GENÉRICA
// O CODIGO NÃO UTILIZA O TAD LISTA AINDA, AO INSERIR MODIFICAR ATRIBUIÇÕES!!!!

typedef struct Arv tArvore;

struct Arv{ 
	char Letra; //Letra e Freq serão inicializados no TAD Lista. Juntamente com Prox e Ant;
	int Freq; // A arvore terá um tipo lista que conterá esses espaços de memoria; 
	struct Arv* dir;
	struct Arv* esq;
};

typedef struct tabela tTabela;

struct tabela{
	char Letra;
	int Freq;
	int QtdBit; // Quantidade de bits, que é representado pela quantidade de nós que percorreu até chegar a folha;
	char* CodeBit; // Codigo Binario. Atribuido a letra pesquisada, são atribuidos zeros e um's de acordo com o "caminhar" na arvore.
	//(Esquerda - 1 ; Direita - 0)
};

tArvore* CriaArvoreVazia(void)
{
	return NULL;
}
tArvore* CriaArvore(tArvore* dir, tArvore* esq, char c, int f)
{
	tArvore* a = (tArvore*)malloc(sizeof(tArvore));
	a->Letra = c;
	a->Freq = f;
	a->esq = esq;
	a->dir = dir;
	
	return a;
}
int PreencheVetor(FILE* Arquivo, int* Vetor) // O vetor tem que ser alocado de acordo com o tamanho do arquivo;
{
	int i=0; // Indice;
	char Letra; // Espaço para a atribuição de uma letra do arquivo;
	
	while(fscanf(Arquivo, "%c", &Letra) != EOF)
	{
		Vetor[i] = Letra;
		i++;
	}
	
	rewind(Arquivo);
	return Vetor;
}
/* Cria Lista com todos os simbolos do arquivo de entrada  */
tArvore* ListaSimbolos (FILE* Arquivo)
{
	tArvore* Arvore = NULL;
	tArvore* Aux;
	char Letra;
	
	//Cria uma estrutura caso não tenha elementos na lista;
	while(fscanf(Arquivo, "%c", &Letra) != EOF)
	{
		if(Arvore == NULL)
			Arvore = CriaArvore(CriaArvoreVazia(), CriaArvoreVazia(), Letra, 1);
			Arvore->Ant = NULL; // Adicionar pelo TAD lista
			Arvore->Prox = NULL; // Adicionar pelo TAD lista
		else
		{
			Aux = Arvore;
			
			while(Aux->Letra != Letra && Aux->Prox != NULL)
				Aux = Aux->Prox;
			//Insere um elemento na lista caso nao tenha o elemento.
			if(Aux->Letra != Letra)
			{
				Aux->Prox = CriaArvore(CriaArvoreVazia(), CriaArvoreVazia(), Letra, 1);
				Aux->Prox->Ant = Aux;
				Aux = Aux->Prox; // Adicionar pelo TAD lista
				Aux->Prox = NULL; // Adicionar pelo TAD lista
			}
			else
				Aux->Freq++; // Incrementa a Frequencia do elemento caso ele já foi inserido.
		}
		Qtd_Itens++; // Tentar contar a quantidade de itens na lista Arvore...(Para uso do qSort em OrdenaArvore)
	}
	rewind(Arquivo);
	return Arvore;
}
/* Funções de Comparação/QSort */
int compara(const void* v1, const void* v2)
{
	int freq1, freq2;
	freq1 = ((tArvore*)v1)->Freq;
	freq2 = ((tArvore*)v2)->Freq;
	return (freq1 - freq2);
}
void OrdenaArvore(tArvore* Arvore)
{
	qsort (Arvore, n, sizeof(tArvore), compara); // 'n' é o numero de elementos da lista Arvore! 
	// Criar uma função para contar o numero de elementos da lista Arvore!!
	// Lembre-se que a lista Arvore tem dois itens com informações, ou seja, cada par de itens conta como um elemento;
}

tArvore* MontaArvore(tArvore* Arvore)
{
	tArvore* NovoNo;
	Arvore = OrdenaArvore(Arvore); // Ordena a Lista dos elementos;
	
	while(Arvore->Prox != NULL)
	{
		//Cria o nó pai com a soma das frequencias dos filhos;
		NovoNo = CriaArvore(Arvore->Prox, Arvore, '\0', (Arvore->Freq + Arvore->Prox->Freq));
		
		//Muda as referencias do nó filhos
		Arvore = Arvore->Prox;
		Arvore->Ant->Prox = NULL;
		Arvore->Ant = NULL;
		
		//Insere nó Pai a lista
		if(Arvore->Prox != NULL)
		{
			Arvore->Prox->Ant = NovoNo;
			NovoNo->Prox = Arvore->Prox;
			Arvore->Prox = NULL;
			
			//Ordena a lista dos elementos
			Arvore = OrdenaArvore(NovoNo);
		}
	}
	
	return NovoNo;
}

tTabela* TabelaCodificada(tArvore *Arvore, tTabela *Tabela, char* Code, int QtdBit)
{
	int i=0;
	if(Arvore->Esq != NULL) // Segue pela esquerda da arvore;
	{
		Code[QtdBit] = '1'; // Atribui o bit 1;
		QtdBit++; // Atribui a quantidade de bits;
		//Faz a recursão da função com a referencia do no da esquerda;
		Tabela = TabelaCodificada(Arvore->Esq, Tabela, Code, QtdBit); //Recursão para continuar explorando os filhos da Arvore;
		QtdBit--;
	}
	if(Arvore->Dir != NULL) // Segue pela direita da arvore;
	{
		Code[QtdBit] = '0'; // Atribui o bit 0;
		QtdBit++; // Atribui a quantidade de bits;
		//Faz a recursão da função com a referencia do no da esquerda;
		Tabela = TabelaCodificada(Arvore->Dir, Tabela, Code, QtdBit); //Recursão para continuar explorando os filhos da Arvore;
		QtdBit--;
	}
	if(Arvore->Letra != '\0') // Atribuições da lista para a Tabela.
	{
		// Atribui os dados a tabela de codificação;
		Tabela[i].Letra = Arvore->Letra; // Letra;
		Tabela[i].Freq = Arvore->Freq; // Frequencia;
		Tabela[i].QtdBit = QtdBit; // Quantidade de Bits(nós) percorridos;
		strcpy(Tabela[i].CodeBit, Code); // CodeBit do caminho percorrido.
		QtdBit = 0;
		i++; // indice da codificação;
	}
	
	return Tabela;
}
void Codificacao(FILE* Arquivo, FILE* Saida, tTabela* Tabela, int Quantidade)
{
	int i, j, limite = 0;
	unsigned char buffer = 0
	unsigned char Letra = 0;
	
	while(fscanf(Arquivo, "%c", &Letra) != EOF) // Verifica o final do arquivo;
	{
		for(i=0; i<Quantidade; i++)
		{
			if(Tabela[i].Letra == Letra)
			{
				for(j=0; j<(Tabela[i].QtdBit); j++) // Verifica o simbolo na tabela;
				{
					if(Tabela[i].CodeBit[j] == '\0') // Atribui o bit 0 no buffer;
						buffer = buffer << 1;
					else // Atribui o bit 1 no buffer;
					{
						buffer = buffer << 1;
						buffer++;
					}
					limite++;
					if(limite == 8) // escreve no arquivo quando o buffer esta no limite;
					{
						fwrite(&buffer, sizeof(char), 1, Saida);
						buffer = 0;
						limite = 0;
					}
				}
				break;
			}
		}
	}
	if(limite < 8 && limite != 0)
		fwrite(&buffer, sizeof(char), 1, Saida);
}