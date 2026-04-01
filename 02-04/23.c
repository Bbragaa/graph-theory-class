#include <stdio.h>
#include <stdlib.h>

int main() {
  int produtos[] = {10, 25, 10, 30, 45, 25, 60, 10};
  int tamanho = 8;

  int busca;
  int posicoes[10];
  int total = 0;

  printf("digite o id do produto que deseja buscar: ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++) {
    if (produtos[i] == busca) {
      posicoes[total] = i;
      total++;
    }
  }

  if (total > 0) {
    printf("produto %d encontrado %d vez(es) nos indices: ", busca, total);
    for (int i = 0; i < total; i++)
      printf("%d ", posicoes[i]);
    printf("\n");
  } else {
    printf("produto nao encontrado.\n");
  }

  return 0;
}