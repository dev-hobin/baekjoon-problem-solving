#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
string arr[100001];
map<string, int> name_to_index;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> n >> m;

  string v;
  for (int i = 1; i <= n; i++) {
    cin >> v;
    arr[i] = v;
    name_to_index[v] = i;
  }

  string s;
  for (int i = 1; i <= m; i++)
  {
    cin >> s;
    if ((int)s[0] >= 65) cout << name_to_index[s] << "\n";
    else cout << arr[stoi(s)] << "\n";
  }
  return 0;
}