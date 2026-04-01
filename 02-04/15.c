#include <stdio.h>
#include <stdlib.h>

void selectionSort(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int menor = i;
    for (int j = i + 1; j < n; j++)
      if (v[j] < v[menor])
        menor = j;
    int temp = v[i];
    v[i] = v[menor];
    v[menor] = temp;
  }
}

int buscaBinaria(int v[], int n, int busca) {
  int ini = 0, fim = n - 1;
  while (ini <= fim) {
    int meio = (ini + fim) / 2;
    if (v[meio] == busca)
      return meio;
    if (v[meio] < busca)
      ini = meio + 1;
    else
      fim = meio - 1;
  }
  return -1;
}

int main() {
  int dados[] = {88, 23, 45, 12, 67, 34, 90, 10};
  int n = 8, busca;

  printf("dados antes da ordenacao: ");
  for (int i = 0; i < n; i++)
    printf("%d ", dados[i]);
  printf("\n");

  selectionSort(dados, n);

  printf("dados depois da ordenacao: ");
  for (int i = 0; i < n; i++)
    printf("%d ", dados[i]);
  printf("\n");

//    antes da ordenação, a busca custa o(n) pois precisa verificar um por um.
//    depois de ordenar, a busca binária custa o(log n), muito mais rápido.
//    a ordenação em si custa o(n²) com selection sort, então só vale a pena
//    se formos fazer muitas buscas no mesmo conjunto de dados.

  printf("qual valor deseja buscar? ");
  scanf("%d", &busca);

  int pos = buscaBinaria(dados, n, busca);

  if (pos != -1)
    printf("valor encontrado na posicao %d\n", pos);
  else
    printf("valor nao encontrado.\n");

  return 0;
}