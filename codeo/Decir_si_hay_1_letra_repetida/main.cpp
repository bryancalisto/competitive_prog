#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define N_LETRAS 26

using namespace std;

int hashTable[N_LETRAS] = {0};
int _hash;

int main()
{
  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    _hash = (int)str[i] - 97;
    // cout << str[i] << " => " << _hash << endl;

    if (hashTable[_hash] > 0)
    {
      cout << "yes\n";
      return 0;
    }

    hashTable[_hash]++;
  }

  cout << "no\n";
  return 0;
}