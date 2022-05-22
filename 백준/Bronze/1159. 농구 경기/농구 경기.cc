#include <iostream>

using namespace std;

int n;
string s;
int a[30];
bool can;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    int ind = (int)s[0] - 97;
    a[ind] += 1;
  }
  for (int i = 0; i < 30; i++)
  {
    if (a[i] >= 5)
    {
      can = true;
      cout << (char)(i+97);
    }
  }
  if (!can) cout << "PREDAJA";
  return 0;
}