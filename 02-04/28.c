#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 7

int main() {
  int vetor[TAMANHO] = {11, 22, 33, 44, 55, 66, 77};
  int busca;
  int inicio = 0;
  int fim = TAMANHO - 1;
  int meio;
  int comparacoes = 0;
  int passo = 1;

  printf("vetor: ");
  for (int i = 0; i < TAMANHO; i++)
    printf("%d ", vetor[i]);
  printf("\n\n");

  printf("digite o valor para buscar: ");
  scanf("%d", &busca);

  printf("\nbuscando %d...\n\n", busca);

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
    comparacoes++;

    printf("passo %d: inicio=%d meio=%d fim=%d\n", passo, vetor[inicio],
           vetor[meio], vetor[fim]);

    if (vetor[meio] == busca) {
      printf("valor encontrado no indice %d\n", meio);
      printf("total de comparacoes: %d\n", comparacoes);
      return 0;
    } else if (busca < vetor[meio]) {
      printf("  %d e menor que %d, busca continua na metade esquerda\n\n",
             busca, vetor[meio]);
      fim = meio - 1;
    } else {
      printf("  %d e maior que %d, busca continua na metade direita\n\n", busca,
             vetor[meio]);
      inicio = meio + 1;
    }

    passo++;
  }

  printf("busca encerrada: inicio (%d) ultrapassou fim (%d)\n", inicio, fim);
  printf("valor %d nao encontrado.\n", busca);
  printf("total de comparacoes: %d\n", comparacoes);

  return 0;
}