#include <stdio.h>
#include <stdlib.h>

int main() {
  int pedidos[] = {903, 112, 457, 221, 678, 345, 789, 150};
  int tamanho = 8;
  int busca, comparacoes = 0, encontrado = -1;

  printf("digite o codigo do pedido: ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++) {
    comparacoes++;
    if (pedidos[i] == busca) {
      encontrado = i;
      break;
    }
  }

  if (encontrado != -1)
    printf("pedido encontrado na posicao %d. comparacoes: %d\n", encontrado,
           comparacoes);
  else
    printf("pedido nao encontrado. comparacoes feitas: %d\n", comparacoes);

  return 0;
}