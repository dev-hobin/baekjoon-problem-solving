#include <iostream>
#include <algorithm>
using namespace std;
char a1[100], a2[100];
int res = 1;
int main()
{
  int i = -1;
  while (cin >> a1[++i]);
  copy(a1, a1+i, a2);
  reverse(a1, a1+i);
  for (int j = 0; j <= i; j++)
  {
    if (a1[j] != a2[j]) res = 0;
  }
  cout << res << "\n";
  return 0;
}

