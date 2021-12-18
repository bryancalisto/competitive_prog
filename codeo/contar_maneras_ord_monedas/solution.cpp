#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  vector<int> monedas;
  int M;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int mon;
    cin >> mon;
    monedas.push_back(mon);
  }

  vector<int> tbl = vector<int>(10000);
  cin >> M;
  while (M > 0)
  {
    int cantidad;
    cin >> cantidad;
    tbl[0] = 1;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < tbl.size(); j++)
      {
        if (monedas[i] <= j)
        {
          tbl[j] += tbl[j - monedas[i]];
        }
      }
    }

    cout << tbl[cantidad] << endl;
    M--;
  }

  return 0;
}