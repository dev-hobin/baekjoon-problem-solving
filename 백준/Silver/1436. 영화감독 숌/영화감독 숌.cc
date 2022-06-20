#include <bits/stdc++.h>
using namespace std;

int n, i, cnt;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  
  int i = 1;
  while (i++)
  {
    if (to_string(i).find("666") != string::npos) cnt++;
    if (cnt == n)
    {
      cout << i;
      break;
    }
  }
  return 0;
}