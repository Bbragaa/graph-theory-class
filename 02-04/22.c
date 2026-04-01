#include <stdio.h>
#include <stdlib.h>

int main() {
  int transacoes[] = {1001, 1020, 1055, 1100, 1200, 1300, 1500};
  int tamanho = 7;

  int busca;
  int inicio = 0;
  int fim = tamanho - 1;
  int meio;
  int posicao = -1;
  int iteracao = 1;

  printf("digite o codigo da transacao: ");
  scanf("%d", &busca);

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;

    printf("iteracao %d: inicio=%d meio=%d fim=%d\n", iteracao,
           transacoes[inicio], transacoes[meio], transacoes[fim]);

    if (transacoes[meio] == busca) {
      posicao = meio;
      break;
    } else if (busca < transacoes[meio]) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }

    iteracao++;
  }

  if (posicao != -1)
    printf("codigo %d encontrado na posicao %d\n", busca, posicao);
  else
    printf("codigo %d nao encontrado.\n", busca);

  return 0;
}