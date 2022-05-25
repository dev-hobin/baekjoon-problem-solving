#include <iostream>
#include <string>

using namespace std;

int n;
string s;
string res;

int table[65][65];

string zip(int yi, int xi, int n)
{
  if (n == 1)
  {
    if (table[yi][xi] == 0) return "0";
    else return "1";
  }
    
  int sum = 0;
  for (int i = yi; i < yi + n; i++)
  {
    for (int j = xi; j < xi + n; j++) sum += table[i][j];
  }
  if (sum == n*n) return "1";
  if (sum == 0) return "0";

  string ret = "";
  int half = n/2;
  ret += zip(yi, xi, half);
  ret += zip(yi, xi + half, half);
  ret += zip(yi + half, xi, half);
  ret += zip(yi + half, xi + half, half);

  return "(" + ret + ")";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < n; j++) table[i][j] = s[j] - '0';
  }

  cout << zip(0, 0, n);

  return 0;
}