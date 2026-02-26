/*
 * sorting_algorithms.c
 * Implementacao dos principais algoritmos de ordenacao em C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* -------------------------
   Funcoes auxiliares
   ------------------------- */

/* Imprime os elementos do array */
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n - 1)
      printf(", ");
  }
  printf("\n");
}

/* Copia src para dst */
void copyArray(int src[], int dst[], int n) {
  for (int i = 0; i < n; i++)
    dst[i] = src[i];
}

/* Troca dois inteiros */
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/* -------------------------
   Bubble Sort
   Complexidade: O(n^2)
   ------------------------- */
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int trocou = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        trocou = 1;
      }
    }
    /* Encerra cedo se nenhuma troca ocorreu */
    if (!trocou)
      break;
  }
}

/* -------------------------
   Selection Sort
   Complexidade: O(n^2)
   ------------------------- */
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIdx])
        minIdx = j;
    }
    if (minIdx != i)
      swap(&arr[i], &arr[minIdx]);
  }
}

/* -------------------------
   Insertion Sort
   Complexidade: O(n^2)
   ------------------------- */
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int chave = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > chave) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = chave;
  }
}

/* -------------------------
   Quick Sort
   Complexidade: O(n log n) medio, O(n^2) pior caso
   ------------------------- */

/* Particiona o array em torno do pivo */
int partition(int arr[], int low, int high) {
  int pivo = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivo) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

/* -------------------------
   Merge Sort
   Complexidade: O(n log n)
   ------------------------- */

/* Intercala duas metades ordenadas */
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];

  free(L);
  free(R);
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

/* -------------------------
   Funcao de teste e medicao
   ------------------------- */

/* Executa e cronometra um algoritmo de ordenacao */
void runAndMeasure(const char *nome, void (*sortFn)(int[], int), int original[],
                   int n, int useQuick, int useMerge) {
  int *arr = (int *)malloc(n * sizeof(int));
  copyArray(original, arr, n);

  printf("\n--- %s ---\n", nome);
  if (n <= 20) {
    printf("Antes : ");
    printArray(arr, n);
  }

  clock_t inicio = clock();

  if (useQuick)
    quickSort(arr, 0, n - 1);
  else if (useMerge)
    mergeSort(arr, 0, n - 1);
  else
    sortFn(arr, n);

  clock_t fim = clock();
  double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

  if (n <= 20) {
    printf("Depois: ");
    printArray(arr, n);
  }
  printf("Tempo : %.6f segundos\n", tempo);

  free(arr);
}

/* Gera arrays de teste */
void gerarAleatorio(int arr[], int n) {
  srand(42);
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 10000;
}

void gerarOrdenado(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = i;
}

void gerarInverso(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = n - i;
}

/* Executa todos os algoritmos para um dado array */
void executarTodos(int original[], int n, const char *descricao) {
  printf("\n========================================\n");
  printf("Conjunto: %s | Tamanho: %d\n", descricao, n);
  printf("========================================");

  runAndMeasure("Bubble Sort", bubbleSort, original, n, 0, 0);
  runAndMeasure("Selection Sort", selectionSort, original, n, 0, 0);
  runAndMeasure("Insertion Sort", insertionSort, original, n, 0, 0);
  runAndMeasure("Quick Sort", NULL, original, n, 1, 0);
  runAndMeasure("Merge Sort", NULL, original, n, 0, 1);
}

/* -------------------------
   Menu interativo
   ------------------------- */
void exibirMenu() {
  printf("\n======================================\n");
  printf("||     ALGORITMOS DE ORDENACAO         ||\n");
  printf("||=====================================||\n");
  printf("|| 1. Bubble Sort                      ||\n");
  printf("|| 2. Selection Sort                   ||\n");
  printf("|| 3. Insertion Sort                   ||\n");
  printf("|| 4. Quick Sort                       ||\n");
  printf("|| 5. Merge Sort                       ||\n");
  printf("|| 6. Comparar todos os algoritmos     ||\n");
  printf("|| 0. Sair                             ||\n");
  printf("||=====================================||\n");
  printf("Escolha: ");
}

void menuTamanho(int *n) {
  printf("\nTamanho do array:\n");
  printf("  1. Pequeno  (10 elementos)\n");
  printf("  2. Medio    (1.000 elementos)\n");
  printf("  3. Grande   (100.000 elementos)\n");
  printf("Escolha: ");
  int op;
  scanf("%d", &op);
  switch (op) {
  case 1:
    *n = 10;
    break;
  case 2:
    *n = 1000;
    break;
  case 3:
    *n = 100000;
    break;
  default:
    *n = 1000;
  }
}

void menuTipoArray(int arr[], int n) {
  printf("\nTipo do array:\n");
  printf("  1. Aleatorio\n");
  printf("  2. Ja ordenado\n");
  printf("  3. Ordem inversa\n");
  printf("Escolha: ");
  int op;
  scanf("%d", &op);
  switch (op) {
  case 1:
    gerarAleatorio(arr, n);
    break;
  case 2:
    gerarOrdenado(arr, n);
    break;
  case 3:
    gerarInverso(arr, n);
    break;
  default:
    gerarAleatorio(arr, n);
  }
}

/* -------------------------
   Main
   ------------------------- */
int main(void) {
  int opcao;

  do {
    exibirMenu();
    scanf("%d", &opcao);

    if (opcao == 0)
      break;

    if (opcao == 6) {
      /* Comparacao completa com multiplos tamanhos e tipos */
      int tamanhos[] = {100, 10000, 100000};
      for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];
        int *arr = (int *)malloc(n * sizeof(int));

        gerarAleatorio(arr, n);
        executarTodos(arr, n, "Aleatorio");

        gerarOrdenado(arr, n);
        executarTodos(arr, n, "Ja Ordenado");

        gerarInverso(arr, n);
        executarTodos(arr, n, "Ordem Inversa");

        free(arr);
      }
      continue;
    }

    int n;
    menuTamanho(&n);
    int *arr = (int *)malloc(n * sizeof(int));
    menuTipoArray(arr, n);

    int *copia = (int *)malloc(n * sizeof(int));
    copyArray(arr, copia, n);

    printf("\n");
    switch (opcao) {
    case 1:
      runAndMeasure("Bubble Sort", bubbleSort, copia, n, 0, 0);
      break;
    case 2:
      runAndMeasure("Selection Sort", selectionSort, copia, n, 0, 0);
      break;
    case 3:
      runAndMeasure("Insertion Sort", insertionSort, copia, n, 0, 0);
      break;
    case 4:
      runAndMeasure("Quick Sort", NULL, copia, n, 1, 0);
      break;
    case 5:
      runAndMeasure("Merge Sort", NULL, copia, n, 0, 1);
      break;
    }

    free(arr);
    free(copia);

  } while (opcao != 0);

  printf("\nEncerrando.\n");
  return 0;
}