#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *input;
  int len, i, *num, carry = 0, k;

  input = (char *)malloc(10002);
  fgets(input, 10002, stdin);
  fscanf(stdin, "%d", &k);
  // printf("K= %d\n", k);
  len = strlen(input) - 1;
  input[len] = '\0'; // replace '\n'
  num = (int *)malloc(sizeof(int) * len);

  for (i = 0; i < len; i++)
  {
    num[i] = input[i] - '0';
  }

  if (len == 1)
  {
    printf("%d\n", num[0] + k);
    free(num);
    free(input);
    return 0;
  }

  num[len - 1] += k;

  if (num[len - 1] > 9)
  {
    carry = 1;
    num[len - 1] -= 10;
  }

  for (i = len - 2; i >= 0; i--)
  {
    num[i] += carry;

    if (num[i] > 9)
    {
      carry = 1;
      num[i] = 0;
    }
    else
    {
      carry = 0;
    }
  }

  if (carry == 1)
  {
    printf("1");
  }

  for (i = 0; i < len; i++)
  {
    printf("%d", num[i]);
  }

  printf("\n");

  free(num);
  free(input);
  return 0;
}