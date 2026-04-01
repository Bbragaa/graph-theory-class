#include <stdio.h>
#include <stdlib.h>

int main() {
  int filmes[] = {501, 123, 876, 234, 654, 345, 999};
  int tamanho = 7;
  int busca, verificado = 0, i;

  printf("id do filme: ");
  scanf("%d", &busca);

  for (i = 0; i < tamanho; i++) {
    verificado++;
    if (filmes[i] == busca) {
      printf("filme encontrado na posicao %d.\n", i);
      return 0;
    }
  }

  printf("filme nao encontrado. elementos verificados: %d\n", verificado);
  return 0;
}