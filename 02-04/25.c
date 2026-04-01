#include <stdio.h>
#include <stdlib.h>

int main() {
  int vetor[] = {77, 12, 89, 34, 56, 23, 90};
  int tamanho = 7;

  int busca;
  int posicao = -1;
  int comparacoes = 0;

  printf("digite o valor que deseja buscar: ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++) {
    comparacoes++;
    if (vetor[i] == busca) {
      posicao = i;
      break; // para o loop assim que encontra!!
    }
  }

  if (posicao != -1)
    printf("valor %d encontrado no indice %d\n", busca, posicao);
  else
    printf("valor %d nao encontrado.\n", busca);

  printf("comparacoes realizadas: %d\n", comparacoes);

  return 0;
}