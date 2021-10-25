//https://codeo.app/problemas/0xcc-la-liebre-y-la-tortuga-en-un-arreglo-circular
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, t, l, res;

  cin >> n;
  cin >> t;
  cin >> l;

  res = t - l;

  if (res < 0)
  {
    res = n + res;
  }

  printf("%d", res);

  return 0;
}