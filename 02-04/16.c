#include <stdio.h>
#include <stdlib.h>

int main() {
  int votos[] = {3, 1, 4, 2, 5, 3, 2, 1, 4};
  int tamanho = 9;
  int candidato, contagem = 0;

  printf("consultar votos do candidato (1-5): ");
  scanf("%d", &candidato);

  for (int i = 0; i < tamanho; i++) {
    if (votos[i] == candidato)
      contagem++;
  }

  printf("o candidato %d recebeu %d voto(s).\n", candidato, contagem);
  return 0;
}