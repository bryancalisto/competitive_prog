//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &);

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
  vector<int> scores;
  vector<int> res;
  int i;

  ranked.erase(unique(ranked.begin(), ranked.end()), ranked.end());

  for (i = 0; i < player.size(); i++)
  {
    printf("%d\n", lower_bound(ranked.begin(), ranked.end(), player[i], greater<int>()) - ranked.begin() + 1);
  }

  return res;
}

int main()
{

  string ranked_count_temp;
  getline(cin, ranked_count_temp);

  int ranked_count = stoi(ranked_count_temp);

  string ranked_temp_temp;
  getline(cin, ranked_temp_temp);

  vector<string> ranked_temp = split(ranked_temp_temp);

  vector<int> ranked(ranked_count);

  for (int i = 0; i < ranked_count; i++)
  {
    int ranked_item = stoi(ranked_temp[i]);

    ranked[i] = ranked_item;
  }

  string player_count_temp;
  getline(cin, player_count_temp);

  int player_count = stoi(player_count_temp);

  string player_temp_temp;
  getline(cin, player_temp_temp);

  vector<string> player_temp = split(player_temp_temp);

  vector<int> player(player_count);

  for (int i = 0; i < player_count; i++)
  {
    int player_item = stoi(player_temp[i]);

    player[i] = player_item;
  }

  vector<int> result = climbingLeaderboard(ranked, player);

  for (size_t i = 0; i < result.size(); i++)
  {
    cout << result[i];

    if (i != result.size() - 1)
    {
      cout << "\n";
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