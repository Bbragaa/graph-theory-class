#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  long long comparacoes;
  long long movimentacoes;
  double tempo_ms;
} Resultado;

void preencher_decrescente(int v[], int n) {
  for (int i = 0; i < n; i++) {
    v[i] = n - i;
  }
}

void copiar_vetor(int destino[], const int origem[], int n) {
  memcpy(destino, origem, (size_t)n * sizeof(int));
}

Resultado bubble_sort(int v[], int n) {
  Resultado r;
  r.comparacoes = 0;
  r.movimentacoes = 0;
  r.tempo_ms = 0.0;

  clock_t inicio = clock();

  for (int i = 0; i < n - 1; i++) {
    int trocou = 0;

    for (int j = 0; j < n - 1 - i; j++) {
      r.comparacoes++;
      if (v[j] > v[j + 1]) {
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;

        r.movimentacoes++;
        trocou = 1;
      }
    }

    if (!trocou) {
      break;
    }
  }

  clock_t fim = clock();
  r.tempo_ms = (double)(fim - inicio) * 1000.0 / (double)CLOCKS_PER_SEC;

  return r;
}

Resultado selection_sort(int v[], int n) {
  Resultado r;
  r.comparacoes = 0;
  r.movimentacoes = 0;
  r.tempo_ms = 0.0;

  clock_t inicio = clock();

  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;

    for (int j = i + 1; j < n; j++) {
      r.comparacoes++;
      if (v[j] < v[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      int temp = v[i];
      v[i] = v[min_idx];
      v[min_idx] = temp;

      r.movimentacoes++;
    }
  }

  clock_t fim = clock();
  r.tempo_ms = (double)(fim - inicio) * 1000.0 / (double)CLOCKS_PER_SEC;

  return r;
}

void imprimir_linha(const char *alg, int n, Resultado r) {
  printf("%-14s | %-6d | %10.3f | %12lld | %14lld\n", alg, n, r.tempo_ms,
         r.comparacoes, r.movimentacoes);
}

int main(void) {
  int tamanhos[] = {100, 1000, 10000};
  int qtd = (int)(sizeof(tamanhos) / sizeof(tamanhos[0]));

  printf("algoritmo      | tamanho |  tempo (ms) |  comparacoes | "
         "movimentacoes\n");
  printf("---------------------------------------------------------------------"
         "--\n");

  for (int t = 0; t < qtd; t++) {
    int n = tamanhos[t];

    int *base = (int *)malloc((size_t)n * sizeof(int));
    int *vet = (int *)malloc((size_t)n * sizeof(int));

    if (!base || !vet) {
      printf("erro: memoria insuficiente\n");
      free(base);
      free(vet);
      return 1;
    }

    preencher_decrescente(base, n);

    copiar_vetor(vet, base, n);
    Resultado rb = bubble_sort(vet, n);
    imprimir_linha("bubble sort", n, rb);

    copiar_vetor(vet, base, n);
    Resultado rs = selection_sort(vet, n);
    imprimir_linha("selection sort", n, rs);

    free(base);
    free(vet);
  }

  return 0;
}
