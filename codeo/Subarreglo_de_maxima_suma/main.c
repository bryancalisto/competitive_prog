#include <stdio.h>

long long max(long long a, long long b)
{
  return a > b ? a : b;
}

int main()
{
  int N;
  long long sumaActual = 0, sumaMax = -1000000000, num;

  scanf("%d", &N);

  // Kadane
  for (int i = 0; i < N; i++)
  {
    scanf(" %lld", &num);
    sumaActual = max(num, sumaActual + num);

    if (sumaActual > sumaMax)
    {
      sumaMax = sumaActual;
    }
  }

  printf("%lld\n", sumaMax);
  return 0;
}