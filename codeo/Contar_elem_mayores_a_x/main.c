#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int n, c;
  int *resultados;
  int *consultas;
  char *arr;
  int *intArr;
  char *token;
  int tmp;
  int contador = 0;

  scanf("%d *[^\n]", &n);
  arr = (char *)malloc(5000); // 5000 is an almost aleatory number. In the worst case it should be (10^9).length * 2 (*2 to count spaces)
  intArr = (int *)malloc(sizeof(int) * n);
  fgets(arr, 5000, stdin);
  scanf("%d", &c);
  // printf("C: %d\n", c);
  consultas = (int *)malloc(sizeof(int) * c);
  resultados = (int *)malloc(sizeof(int) * c);

  for (int i = 0; i < c; i++)
  {
    scanf("%d", &consultas[i]);
  }

  token = strtok(arr, " ");

  // Armamos arreglo en base a input de usuario
  for (int i = 0; i < n; i++)
  {
    intArr[i] = atoi(token);
    token = strtok(NULL, " ");
  }

  // Ejecutamos cada consulta
  for (int i = 0; i < c; i++)
  {
    tmp = 0;

    for (int j = 0; j < n; j++)
    {
      // printf("intArr[%d]: %d , consultas[%d]: %d\n", j, intArr[j], i, consultas[i]);
      if (intArr[j] > consultas[i])
      {
        tmp++;
      }
    }

    resultados[i] = tmp;
  }

  for (int i = 0; i < c; i++)
  {
    printf("%d\n", resultados[i]);
  }

  free(arr);
  free(intArr);
  free(consultas);
  free(resultados);
  return 0;
}