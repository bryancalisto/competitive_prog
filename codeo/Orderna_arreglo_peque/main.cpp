#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, i, j, k;
  fscanf(stdin, " %d", &N);
  vector<int> arr;

  // Leemos input y de paso vamos ordenando
  int n;
  fscanf(stdin, " %d", &n);
  arr.push_back(n);

  for (i = 1; i < N; i++)
  {
    int num;
    fscanf(stdin, " %d", &num);

    arr.push_back(num);

    k = arr.size() - 2;
    while (k >= 0 && arr[k] > num)
    {
      arr[k + 1] = arr[k];
      k--;
    }

    arr[k + 1] = num;
  }

  // Mostramos resultado
  for (i = 0; i < N; i++)
  {
    printf("%d ", arr[i]);
  }
}