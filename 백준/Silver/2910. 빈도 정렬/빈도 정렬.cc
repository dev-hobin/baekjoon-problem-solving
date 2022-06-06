#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, c;
vector<int> vec;
map<int, int> _map;
map<int, int> order;

bool custom_sort(int a, int b)
{
  int ac = _map[a];
  int bc = _map[b];
  if (ac > bc) return true;
  if (ac == bc) return order[a] < order[b];
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> c;
  for (int i = 0; i < n; i++)
  {
    int v;
    cin >> v;
    vec.push_back(v);
    _map[vec[i]]++;
    if (!order[vec[i]]) order[vec[i]] = i + 1;
  }

  sort(vec.begin(), vec.end(), custom_sort);

  for(int v : vec) cout << v << " ";

  return 0;
}