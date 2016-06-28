#include "Arvore.h"
#include "Lista.h"
// ARVORE BINARIA GENÉRICA
// O CODIGO NÃO UTILIZA O TAD LISTA AINDA, AO INSERIR MODIFICAR ATRIBUIÇÕES!!!!

struct Arv{ 
	char letra;
	int freq;
	struct Arv* pai;
	struct Arv* dir;
	struct Arv* esq;
};
/*
struct tabela{
	char Letra;
	int Freq;
	int QtdBit; // Quantidade de bits, que é representado pela quantidade de nós que percorreu até chegar a folha;
	char* CodeBit; // Codigo Binario. Atribuido a letra pesquisada, são atribuidos zeros e um's de acordo com o "caminhar" na arvore.
	//(Esquerda - 1 ; Direita - 0)
};
*/
tArvore* CriaArvoreVazia(void)
{
	return NULL;
}

tArvore* CriaArvore(tLista **lista, tArvore* dir, tArvore* esq)
{
	tArvore* arvore = (tArvore*)malloc(sizeof(tArvore));
	arvore->letra = lista->Letra;
	arvore->freq = lista->Freq;
	arvore->pai = NULL;
	arvore->esq = esq;
	arvore->dir = dir;
	
	return arvore;

tArvore* MontaArvore(tArvore* Arvore, tLista** Lista, int tam)
{
	tArvore* NovoNo;
		
	while(ListaProx(Lista) != NULL)
	{
		if(Lista->flag != 1 && ListaProx(Lista->flag) != 1)
		{
			//Cria o nó pai com NULL e atualiza valor dos filhos para os nós da Arvore
			NovoNo = CriaArvore(Lista, CriaArvoreVazia(), CriaArvoreVazia());
			NovoNo = CriaArvore(Lista->Prox, CriaArvoreVazia(), CriaArvoreVazia());
		}
		Arvore->pai = Lista->Freq;
		operaLista(Lista, tam);
		tam--;
		
		
		//Muda as referencias do nó filhos
		Lista = ListaProx(Lista->Item);
		SetProx(ListaAnt(Lista->Item), NULL);//Lista->Ant->Prox = NULL;
		SetAnt(Lista->Item, NULL);//Lista->Ant = NULL;
		
		//Insere nó Pai a lista
		/*if(ListaProx(Arvore->Item) != NULL)
		{
			SetProx(ListaAnt(Arvore->Item),NovoNo);//Arvore->Ant->Prox = NULL;
			SetProx(NovoNo,ListaProx(Arvore->Item));//= ListaProx(Arvore->Item);
			SetProx(Arvore->Item,NULL);
			
		}*/
	}
	
	return NovoNo;
}

tTabela* TabelaCodificada(tArvore *Arvore, tTabela *Tabela, char* Code, int QtdBit)
{
	int i=0;
	if(Arvore->esq!= NULL) // Segue pela esquerda da arvore;
	{
		Code[QtdBit] = '1'; // Atribui o bit 1;
		QtdBit++; // Atribui a quantidade de bits;
		//Faz a recursão da função com a referencia do no da esquerda;
		Tabela = TabelaCodificada(Arvore->esq, Tabela, Code, QtdBit); //Recursão para continuar explorando os filhos da Arvore;
		QtdBit--;
	}
	if(Arvore->dir!= NULL) // Segue pela direita da arvore;
	{
		Code[QtdBit] = '0'; // Atribui o bit 0;
		QtdBit++; // Atribui a quantidade de bits;
		//Faz a recursão da função com a referencia do no da esquerda;
		Tabela = TabelaCodificada(Arvore->dir, Tabela, Code, QtdBit); //Recursão para continuar explorando os filhos da Arvore;
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
	unsigned char buffer = 0;
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
