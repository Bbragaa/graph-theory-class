#include <stdio.h>
#include <stdlib.h>

int main() {
  long long agenda[] = {11987654321, 11991234567, 11993456789, 11995678901,
                        11997890123};
  int tamanho = 5;
  long long busca;
  int ini = 0, fim = tamanho - 1, meio, pos = -1;

  printf("digite o numero de telefone: ");
  scanf("%lld", &busca);

  while (ini <= fim) {
    meio = (ini + fim) / 2;
    if (agenda[meio] == busca) {
      pos = meio;
      break;
    }
    if (agenda[meio] < busca)
      ini = meio + 1;
    else
      fim = meio - 1;
  }

  if (pos != -1)
    printf("numero encontrado na posicao %d.\n", pos);
  else
    printf("numero nao encontrado.\n");

  return 0;
}