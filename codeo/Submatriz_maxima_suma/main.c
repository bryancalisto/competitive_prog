#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Si se trabaja con C99, descomentar las siguientes 4 lineas
//#define INT_MIN -2147483648
// int max(a,b){
//   return a > b? a: b;
// }

// Para encontrar valor de la mayor suma de los subarrays de un array en O(n)
int kadane(int *arr, int len)
{
  int sumaMax = -INT_MIN;
  int sumaActual = 0;

  for (int i = 0; i < len; i++)
  {
    sumaActual = max(arr[i], arr[i] + sumaActual);
    if (sumaActual > sumaMax)
    {
      sumaMax = sumaActual;
    }
  }

  return sumaMax;
}

int main()
{
  int i, j, k, l, R, C, *matriz, sumaMax = INT_MIN, *tmp;

  // INPUT
  fscanf(stdin, "%d %d", &R, &C);
  matriz = (int *)malloc(sizeof(int) * R * C);

  for (i = 0; i < R; i++)
  {
    for (j = 0; j < C; j++)
    {
      fscanf(stdin, "%d", matriz + i * C + j);
    }
  }

  // ALGORITMO
  tmp = (int *)calloc(R * C, sizeof(int)); // matriz temporal

  for (i = 0; i < R; i++)
  {
    for (j = 0; j < C; j++)
    {
      if (j > 0)
      {
        *(tmp + i * C + j) = *(matriz + i * C + j) + *(tmp + i * C + j - 1);
      }
      else
      {
        *(tmp + i * C + j) = *(matriz + i * C + j);
      }
    }
  }

  int nums;
  for (i = 0; i < C; i++)
  {
    for (j = i; j < C; j++)
    {
      nums = 1;
      int *v = (int *)malloc(sizeof(int) * nums);
      for (k = 0; k < R; k++)
      {
        l = 0;
        if (i > 0)
        {
          l = *(tmp + k * C + j) - *(tmp + k * C + i - 1);
        }
        else
        {
          l = *(tmp + k * C + j);
        }

        v[nums - 1] = l;
        nums++;
        v = (int *)realloc(v, sizeof(int) * nums);
      }

      sumaMax = max(sumaMax, kadane(v, nums - 1));
      free(v);
    }
  }

  printf("%d\n", sumaMax);

  free(matriz);
  free(tmp);
  return 0;
}