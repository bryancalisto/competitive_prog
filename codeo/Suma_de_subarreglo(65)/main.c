#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N, c, i = 0, k, *arr;
  int p, q;
  long long res;

  fscanf(stdin, "%d", &N);

  arr = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++)
  {
    scanf(" %d", &arr[i]);
    if (i)
    {
      arr[i] += arr[i - 1]; // De una vez vamos sumando los elementos contiguos
    }
  }

  scanf(" %d", &c);

  //leer cada consulta, calcular su resultado e imprimirlo
  while (c--)
  {
    scanf(" %d %d", &p, &q);
    res = arr[q] - (p > 0 ? arr[p - 1] : 0);
    printf("%lld\n", res);
  }

  free(arr);
  return 0;
}