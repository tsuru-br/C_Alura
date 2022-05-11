#include <stdio.h>

#define NUMERO_DE_TENTATIVAS 5

int main(void)
{	
	float secretNumber = 26.0;
	int count = 1;	
	float chute = 0;
	int acertou = 0;
	float pontos = 1000;
	float pontos_perdidos = 0;

	printf("******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhação *\n");

	while(1) {
		printf("******************************************\n");
		printf("\tTentativa: %d", count);
		printf("\nQual o seu chute? ");
		scanf("%f", &chute);

		if(chute < 0)
		{
			printf("Você só pode chutar números positivos.\n");
			break; /* I could use "continue", but the break will be used as
		 		      an exit of the game*/
		}
		
		acertou = (chute == secretNumber);
		int maior = chute > secretNumber;

		if(acertou)
		{
			printf("******************************************\n");
			printf("Parabéns você acertou!\n");
			printf("Excelente partida, continue jogando!\n");
			printf("\nVenceu na %dº tentativa\n", count);		
			break;
		}
		else if(maior)
		{
			printf("Seu chute (%.0f) foi maior que o número secreto.\n", chute);
		}
		else
		{
			printf("Seu chute (%.0f) foi menor que o número secreto.\n", chute);
		}
		count++;

		if (count > 100)
		{
			printf("Você excedeu o limite de tentativas, tente outra vez");
			break;
		}


		if (chute > secretNumber) // Para que os pontos_perdidos não sejam negativos (secretNumber precisa ser menor)
		{
			pontos_perdidos = (chute - secretNumber) / (float)2;
		} 
		else // caso o chute seja menor do que o secretNumber (chutou baixo), então é invertido para não negativar
		{
			pontos_perdidos = (secretNumber - chute) / 2.0;
		}
		pontos = pontos - pontos_perdidos;	
	}
	printf("Fim de Jogo!\n");
	printf("\nTotal de Pontos: %.2f\n", pontos);

	return 0;
}