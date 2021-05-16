#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int N, *arr, res = -1, i = 0, j = 0, sumIzq = 0, sumDer = 0, puntoDeCorte;

  fscanf(stdin, "%d", &N);
  arr = (int *)malloc(sizeof(int) * N);

  while (j < N && fscanf(stdin, "%d", arr + j++) == 1)
    ;

  for (i = 0; i < N; i++)
  {
    sumDer += arr[i];
  }

  for (i = 0; i < N; i++)
  {
    sumDer -= arr[i];
    sumIzq += arr[i];

    // printf("sumDer = %d - %d = %d\n", sumDer, arr[i], sumDer - arr[i]);
    // printf("sumIzq = %d sumDer = %d\n", sumIzq, sumDer);
    if (sumDer < 0 && sumIzq > 0)
    {
      res = i + 1;
      break;
    }
  }

  if (res != -1)
  {
    printf("%d\n", res);
  }
  else
  {
    printf("Impossible\n");
  }

  free(arr);
  return 0;
}