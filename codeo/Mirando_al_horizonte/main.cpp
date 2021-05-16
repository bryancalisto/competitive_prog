#include <bits/stdc++.h>

using namespace std;

int main()
{
  int c, n, i, j, *alturas, num;

  scanf(" %d", &c);

  for (i = 0; i < c; i++)
  {
    // INPUT
    scanf("%d", &n);
    alturas = (int *)malloc(sizeof(int) * n);
    vector<int> res(n);
    stack<int> pila;

    for (j = 0; j < n; j++)
    {
      scanf(" %d", &alturas[j]);
    }

    printf("Case #%d: ", i + 1);

    // ALGORITMO
    for (j = n - 1; j >= 0; j--)
    {
      pila.push(alturas[j]);

      while (pila.size() && alturas[j] >= pila.top())
      {
        pila.pop();
      }

      // El ultimo edificio nunca tiene quien le estorbe
      if (!pila.size())
      {
        res[j] = -1;
      }
      // No es el ultimo edificio asi que quien le estorba es el edificio mas alto mas cercano
      else
      {
        res[j] = pila.top();
      }

      pila.push(alturas[j]);
    }

    // Resultado
    for (j = 0; j < n; j++)
    {
      printf("%d ", res[j]);
    }

    printf("\n");
    free(alturas);
  }

  return 0;
}