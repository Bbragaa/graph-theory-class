#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8 // isso é uma variável global

  //  busca binaria iterativa - usa loop while
  //  vantagem: usa menos memoria (O(1))
  //  desvantagem: codigo um pouco mais longo 
int buscaIterativa(int vetor[], int tamanho, int busca) {
  int inicio = 0;
  int fim = tamanho - 1;
  int meio;

  while (inicio <= fim) {
    meio = (inicio + fim) / 2;

    if (vetor[meio] == busca)
      return meio;
    else if (busca < vetor[meio])
      fim = meio - 1;
    else
      inicio = meio + 1;
  }

  return -1;
}

  //  busca binaria recursiva - chama a si mesma
  //  vantagem: codigo mais curto e direto
  //  desvantagem: usa mais memoria (O(log n)) por causa das chamadas na pilha 
int buscaRecursiva(int vetor[], int inicio, int fim, int busca) {
  if (inicio > fim)
    return -1;

  int meio = (inicio + fim) / 2;

  if (vetor[meio] == busca)
    return meio;
  else if (busca < vetor[meio])
    return buscaRecursiva(vetor, inicio, meio - 1, busca);
  else
    return buscaRecursiva(vetor, meio + 1, fim, busca);
}

int main() {
  int vetor[TAMANHO] = {2, 4, 6, 8, 10, 12, 14, 16};
  int busca, posicao;

  printf("vetor: ");
  for (int i = 0; i < TAMANHO; i++)
    printf("%d ", vetor[i]);
  printf("\n\n");

  printf("digite o valor para buscar: ");
  scanf("%d", &busca);

  posicao = buscaIterativa(vetor, TAMANHO, busca);
  printf("\nbusca iterativa: ");
  if (posicao != -1)
    printf("valor %d encontrado no indice %d\n", busca, posicao);
  else
    printf("valor %d nao encontrado\n", busca);

  posicao = buscaRecursiva(vetor, 0, TAMANHO - 1, busca);
  printf("\nbusca recursiva: ");
  if (posicao != -1)
    printf("valor %d encontrado no indice %d\n", busca, posicao);
  else
    printf("valor %d nao encontrado\n", busca);

  printf("\ncomparacao:\n");
  printf("legibilidade:\n");
  printf("  iterativa: fluxo claro com loop, facil de entender\n");
  printf("  recursiva: codigo mais curto, mas precisa entender recursao\n");
  printf("uso de memoria:\n");
  printf("  iterativa: O(1) - usa apenas variaveis locais\n");
  printf("  recursiva: O(log n) - cada chamada ocupa espaco na pilha\n");
  printf("  para 8 elementos: recursiva usa ate 4 niveis de chamada\n");

  return 0;
}