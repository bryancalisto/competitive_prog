#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r)
{
  int i, j, k, l_len, r_len;
  int *l_tmp;
  int *r_tmp;

  l_len = m - l + 1;
  r_len = r - m;
  l_tmp = (int *)malloc(sizeof(int) * l_len);
  r_tmp = (int *)malloc(sizeof(int) * r_len);

  for (i = 0; i < l_len; i++)
  {
    l_tmp[i] = arr[l + i];
  }

  for (i = 0; i < r_len; i++)
  {
    r_tmp[i] = arr[m + i + 1];
  }

  // Ordenamos en si a los subarreglos que se hayan formado
  i = 0;
  j = 0;
  k = l;

  while (i < l_len && j < r_len)
  {
    if (l_tmp[i] <= r_tmp[j])
    {
      arr[k] = l_tmp[i];
      i++;
    }
    else
    {
      arr[k] = r_tmp[j];
      j++;
    }
    k++;
  }

  // Copiamos al arr completo los elementos restantes de ambas mitades
  while (i < l_len)
  {
    arr[k] = l_tmp[i];
    i++;
    k++;
  }

  while (j < r_len)
  {
    arr[k] = r_tmp[j];
    j++;
    k++;
  }

  free(l_tmp);
  free(r_tmp);
}

void mergeSort(int *arr, int l, int r)
{
  if (l < r)
  {
    // Obtenemos punto medio
    int m = l + (r - l) / 2;
    // Mandamos a ordernar las mitades recursivamente
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Hacemos merge de las mitades
    merge(arr, l, m, r);
  }
}

int main()
{
  int N, i, j, k;
  fscanf(stdin, " %d", &N);
  int *arr = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++)
  {
    int num;
    fscanf(stdin, " %d", &arr[i]);
  }

  // Ordenamos (Cualquiera que brinde O(n log n): Merge sort, quick sort, heap sort)
  mergeSort(arr, 0, N - 1);

  // Mostramos
  for (i = 0; i < N; i++)
  {
    printf("%d ", arr[i]);
  }

  free(arr);
}