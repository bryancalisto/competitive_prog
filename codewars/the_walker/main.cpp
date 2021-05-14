// https://www.codewars.com/kata/5b40b666dfb4291ad9000049/train/cpp
#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846

using namespace std;

std::vector<int> solve(int a, int b, int c, int alpha, int beta, int gamma)
{
  double aa = alpha * M_PI / 180;
  double bb = beta * M_PI / 180;
  double gg = gamma * M_PI / 180;
  double x = 0;
  double y = 0;
  double r = 0;
  int d;
  int m;
  int s;
  double tOC = 0;
  int tmp;

  x += a * cos(aa);
  y += a * sin(aa);

  y += b * cos(bb);
  x -= b * sin(bb);

  x -= c * cos(gg);
  y -= c * sin(gg);

  r = sqrt(x * x + y * y);
  tOC = acos(x / r) * 180 / M_PI;
  tmp = tOC;
  m = (tOC - tmp) * 60;
  s = ((tOC - tmp) * 60 - m) * 60;

  vector<int> res = {(int)round(r), tmp, m, s};
  return res;
}

std::string intarray2string(std::vector<int> arr)
{
  std::string str;
  for (int n : arr)
    str += std::to_string(n) + ", ";
  return str.substr(0, str.length() - 2);
}

int main()
{
  int a, b, c, alpha, beta, gamma;
  scanf(" %d, %d, %d, %d, %d, %d", &a, &b, &c, &alpha, &beta, &gamma);
  // printf("%d, %d, %d, %d, %d, %d\n", a, b, c, alpha, beta, gamma);
  vector<int> res = solve(a, b, c, alpha, beta, gamma);
  cout << intarray2string(res) << endl;
}
