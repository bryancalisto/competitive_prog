#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &);

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

vector<int> breakingRecords(vector<int> scores)
{
  vector<int> res = {0, 0};
  vector<int>::iterator it;
  int max_ = scores[0];
  int min_ = scores[0];

  for (it = ++scores.begin(); it != scores.end(); it++)
  {
    if (*it > max_)
    {
      max_ = *it;
      res[0]++;
    }

    if (*it < min_)
    {
      min_ = *it;
      res[1]++;
    }
  }

  return res;
}

int main()
{
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(n_temp);

  string scores_temp_temp;
  getline(cin, scores_temp_temp);

  vector<string> scores_temp = split(scores_temp_temp);

  vector<int> scores(n);

  for (int i = 0; i < n; i++)
  {
    int scores_item = stoi(scores_temp[i]);

    scores[i] = scores_item;
  }

  vector<int> result = breakingRecords(scores);

  for (size_t i = 0; i < result.size(); i++)
  {
    cout << result[i];

    if (i != result.size() - 1)
    {
      cout << " ";
    }
  }

  cout << "\n";

  return 0;
}

vector<string> split(const string &str)
{
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
