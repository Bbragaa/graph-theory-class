#include <stdio.h>
#include <stdlib.h>

// os códigos estão sem acentuação para não bugar o terminal
// eu uso c em alguns projetos mas acho que o mais "avançado" que eu usei foi o #define
int main() {
  int matriculas[] = {512, 102, 678, 205, 789, 317, 404};
  int busca;
  int tamanho = sizeof(matriculas) / sizeof(matriculas[0]);

  printf("qual matricula deseja buscar? ");
  scanf("%d", &busca);

  for (int i = 0; i < tamanho; i++) {
    if (matriculas[i] == busca) {
      printf("aluno encontrado na posicao %d\n", i + 1);
      return 0;
    }
  }

  printf("aluno nao encontrado.\n");

  return 0;
}