#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int M;
  int nValores = 10001;

  std::cin >> N;
  vector<int> monedas(N);

  for (int i = 0; i < N; i++)
  {
    int mon;
    std::cin >> mon;
    monedas[i] = mon;
  }

  vector<vector<int>> tbl(nValores, vector<int>(N));
  std::cin >> M;
  int valor;

  for (int i = 0; i < N; i++)
  {
    tbl[0][i] = 1;
  }

  for (int i = 0; i < nValores; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (j > 0)
      {
        tbl[i][j] = tbl[i][j - 1];
      }

      int restante = i - monedas[j];

      if (restante >= 0)
      {
        tbl[i][j] = (tbl[i][j] + tbl[restante][j]) % 1000000007;
      }
    }
  }

  for (int i = 0; i < M; i++)
  {
    std::cin >> valor;
    std::cout << tbl[valor][N - 1] << std::endl;
  }

  return 0;
}