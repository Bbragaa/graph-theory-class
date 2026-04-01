#include <stdio.h>
#include <stdlib.h>

int main() {
  long long cpfs[] = {11122233300, 22233344400, 33344455500, 44455566600,
                      55566677700};
  int tamanho = 5;
  long long busca;
  int ini = 0, fim = tamanho - 1, meio, etapas = 0;

  printf("digite o cpf (so numeros): ");
  scanf("%lld", &busca);

  while (ini <= fim) {
    etapas++;
    meio = (ini + fim) / 2;
    if (cpfs[meio] == busca) {
      printf("cpf encontrado na posicao %d. etapas da busca: %d\n", meio,
             etapas);
      return 0;
    }
    if (cpfs[meio] < busca)
      ini = meio + 1;
    else
      fim = meio - 1;
  }

  printf("cpf nao encontrado. etapas realizadas: %d\n", etapas);
  return 0;
}