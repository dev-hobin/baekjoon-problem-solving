#include <iostream>

using namespace std;
int n;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n)
  {
    int res = 1;
    long long el = 1;
    while (true)
    {
      if (el % n == 0)
      {
        cout << res << "\n";
        break;
      }
      else
      {
        el = el * 10 + 1;
        el %= n;
        res++;
      }
    }
  }
  return 0;
}