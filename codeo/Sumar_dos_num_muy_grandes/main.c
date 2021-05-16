#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *input;
  int len1, len2, i, j, *num1, *num2, carry = 0, maxLen, minLen, *maxLenNum, *minLenNum;

  input = (char *)malloc(10002); // 2 bytes extra para '\n' y '\0'

  // NUMERO 1
  fgets(input, 10002, stdin);
  len1 = strlen(input) - 1;
  input[len1] = '\0'; // replace '\n'
  num1 = (int *)malloc(sizeof(int) * len1);
  for (i = 0; i < len1; i++)
  {
    num1[i] = input[i] - '0';
  }

  // NUMERO 2
  fgets(input, 10002, stdin);
  len2 = strlen(input) - 1;
  input[len2] = '\0'; // replace '\n'
  num2 = (int *)malloc(sizeof(int) * len2);
  for (i = 0; i < len2; i++)
  {
    num2[i] = input[i] - '0';
  }

  if (len1 == len2 || len1 > len2)
  {
    maxLen = len1;
    maxLenNum = num1;
    minLen = len2;
    minLenNum = num2;
  }
  else
  {
    maxLen = len2;
    maxLenNum = num2;
    minLen = len1;
    minLenNum = num1;
  }

  // if (len1 == 1)
  // {
  //   printf("%d\n", num1[0] + k);
  //   free(num1);
  //   free(input);
  //   return 0;
  // }

  // Hacemos la suma
  maxLenNum[maxLen - 1] += minLenNum[minLen - 1];

  if (maxLenNum[maxLen - 1] > 9)
  {
    carry = 1;
    maxLenNum[maxLen - 1] -= 10;
  }

  // printf("maxLen = %d, minLen = %d\n", maxLen, minLen);

  for (i = 0; i <= maxLen - 2; i++)
  {
    j = i + 2;
    maxLenNum[maxLen - j] += carry;
    // printf("j=%d\n", j);
    if (j <= minLen)
    {
      // printf("maxNum = %d, minNum = %d\n", maxLenNum[maxLen - j], minLenNum[minLen - j]);
      maxLenNum[maxLen - j] += minLenNum[minLen - j];
    }

    if (maxLenNum[maxLen - j] > 9)
    {
      carry = 1;
      maxLenNum[maxLen - j] -= 10;
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

  for (i = 0; i < maxLen; i++)
  {
    printf("%d", maxLenNum[i]);
  }

  printf("\n");

  free(num1);
  free(num2);
  free(input);
  return 0;
}