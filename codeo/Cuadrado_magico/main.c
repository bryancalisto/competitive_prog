#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, N, *arr, col, fila, diag1, diag2, prev = 0;

  fscanf(stdin, "%d", &N);
  arr = (int *)malloc(sizeof(int) * N * N);

  for (i = 0; i < N; i++)
  {
    j = 0;
    while (j < N && fscanf(stdin, "%d", arr + i * N + j++) == 1)
      ;
  }

  // Sumas de columnas y filas
  for (i = 0; i < N; i++)
  {
    col = 0;
    fila = 0;
    diag1 = 0;
    diag2 = 0;

    for (j = 0; j < N; j++)
    {
      col += *(arr + j * N + i);
      fila += *(arr + i * N + j);
      diag1 += *(arr + j * N + j);
      diag2 += *(arr + j * N + N - 1 - j);
    }
    // printf("col = %d / fila = %d / diag1 = %d / diag2 = %d\n", col, fila, diag1, diag2);

    if (!(col == fila && fila == diag1 && diag1 == diag2) || (i != 0 && col != prev))
    {
      printf("No\n");
      free(arr);
      return 0;
    }
    else
    {
      prev = col; // Tomamos cualquiera
    }
  }

  printf("Yes\n");

  free(arr);
  return 0;
}