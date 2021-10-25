#include <stdio.h>

int main()
{
  unsigned long long MAX_UINT = 18446744073709551615;
  unsigned long long num1;
  unsigned long long num2;

  scanf("%llu", &num1);
  scanf("%llu", &num2);

  if (num1 <= MAX_UINT - num2)
  {
    printf("Safe");
  }
  else
  {
    printf("Overflow");
  }

  return 0;
}