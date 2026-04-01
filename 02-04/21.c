#include <stdio.h>
#include <stdlib.h>

int main() {
  int historico[] = {321, 105, 876, 432, 210, 654, 999, 111};
  int tamanho = 8;

  int busca;
  int posicao = -1;
  int comparacoes = 0;

  printf("digite o id da pagina que deseja buscar: ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++) {
    comparacoes++;
    if (historico[i] == busca) {
      posicao = i;
      break;
    }
  }

  if (posicao != -1) {
    printf("pagina %d encontrada na posicao %d (indice %d)\n", busca,
           posicao + 1, posicao);
  } else {
    printf("pagina %d nao encontrada no historico.\n", busca);
  }

  printf("comparacoes realizadas: %d\n", comparacoes);

  return 0;
}