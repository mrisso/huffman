int* CodificacaoWaveletHaar(int* Vetor, int n)
{
	int* VetorP = NULL;
	int i;
	int tamanho = n;
	
	VetorP = (int*)malloc(n*sizeof(int)); // vetor auxiliar.
	
	for(i=0, i<n; i++)
			VetorP[i] = 0;
	
	while(tamanho > 1)
	{
		tamanho = tamanho/2;
		for(i=0, i<tamanho; i++)
		{
			VetorP[i] = (Vetor[2*i] + Vetor[2*i+1]) / 2; // Calculo das Medias.
			VetorP[i+tamanho] = Vetor[2*i] - VetorP[i]; // Calculo das diferenças.
		}
		//Atribui as medias e diferenças do vetor auxiliar para o vetor de origem.
		for(i=0; i<(tamanho*2); i++)
			Vetor[i] = VetorP[i];
	}
	return Vetor;
}