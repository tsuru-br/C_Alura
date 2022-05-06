#include <stdio.h>

#define NUMERO_DE_TENTATIVAS 5

int main(void)
{	
	int secretNumber = 26;
	int count = 1;	
	int chute = 0;
	int acertou = 0;
	int pontos = 1000;

	printf("******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhação *\n");

	while(1) {
		printf("******************************************\n");
		printf("\tTentativa: %d", count);
		printf("\nQual o seu chute? ");
		scanf("%d", &chute);

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
			printf("Seu chute (%d) foi maior que o número secreto.\n", chute);
		}
		else
		{
			printf("Seu chute (%d) foi menor que o número secreto.\n", chute);
		}
		count++;

		if (count > 100)
		{
			printf("Você excedeu o limite de tentativas, tente outra vez");
			break;
		}

		int pontos_perdidos = (chute - secretNumber) / 2; // teria que modular para ser só positivo
		pontos = pontos - pontos_perdidos;	
	}
	printf("Fim de Jogo!\n");
	printf("\nTotal de Pontos: %d\n", pontos);

	return 0;
}