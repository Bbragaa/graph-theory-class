#include <stdio.h>
#include <stdlib.h>

int main() {
  int vetor[] = {5, 15, 25, 35, 45, 55};
  int tamanho = 6;

  int novo;
  int inicio = 0;
  int fim = tamanho - 1;
  int meio;

  printf("digite o valor a ser inserido: ");
  scanf("%d", &novo);

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;

    if (vetor[meio] == novo) {
      printf("valor ja existe no indice %d\n", meio);
      return 0;
    } else if (novo < vetor[meio])
      fim = meio - 1;
    else
      inicio = meio + 1;
  }

  // quando o loop termina, 'inicio' aponta para a posição correta de inserção
  
  printf("posicao correta para inserir %d: indice %d\n", novo, inicio);

  return 0;
}