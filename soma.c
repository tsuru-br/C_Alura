#include <stdio.h>

int main() 
{
  int soma = 0;
  for(int i = 1; i <= 100; i++) 
  {
    soma = soma + i;
	printf("%d\n",soma);
  }
  printf("A soma eh %d\n", soma);
}