#include <bits/stdc++.h>

using namespace std;

int main()
{
  string str;
  int maxDif, maxLen = 0, i = 0, j = 0;
  map<char, int> tabla;

  cin >> str;
  cin >> maxDif;

  while (i < str.length() && j < str.length())
  {
    tabla[str[j]]++;

    // Se supero el limite de caracteres permitido. Terminamos con esta substring y actualizamos nuestros numeros
    while (tabla.size() > maxDif)
    {
      tabla[str[i]]--;
      if (tabla[str[i]] == 0)
      {
        tabla.erase(str[i]);
      }
      i++;
    }
    maxLen = max(maxLen, j - i + 1); // +1 porque indexamos desde 0
    j++;
  }

  cout << maxLen << endl;
}
