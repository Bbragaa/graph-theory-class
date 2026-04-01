#include <stdio.h>
#include <stdlib.h>

int main() {
  int leituras[] = {45, 12, 78, 33, 90, 21, 56, 67};
  int tamanho = 8;
  int busca, verificacoes = 0;

  printf("leitura para verificar: ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++) {
    verificacoes++;
    if (leituras[i] == busca) {
      printf("leitura %d encontrada\n", busca);
      break;
    }
  }

  printf("total de verificacoes: %d\n", verificacoes);

  return 0;
}