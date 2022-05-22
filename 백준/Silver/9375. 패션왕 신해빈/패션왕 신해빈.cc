#include <iostream>
#include <map>
#include <string>

using namespace std;

int t, n;
string name, kinds;
map<string, int> _map;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> n;
    for (int j = 0; j < n; j++)
    {
      cin >> name >> kinds;
      _map[kinds]++;
    }
    
    int res = 1;
    for(auto it : _map) res *= 1 + it.second;
    res -= 1;
    cout << res << "\n";
    _map.clear();
  }
  return 0;
}