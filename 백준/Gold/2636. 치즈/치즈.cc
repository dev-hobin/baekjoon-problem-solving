#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, prev_cnt, i;
int arr[101][101];
int visited[101][101];
vector<pair<int, int>> v;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y_idx, int x_idx)
{
  if (arr[y_idx][x_idx] == 1)
  {
    v.push_back({y_idx, x_idx});
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    int y = y_idx + dy[i];
    int x = x_idx + dx[i];

    if (y < 0 || y >= n || x < 0 || x >= m || visited[y][x]) continue;
    visited[y][x] = 1;
    dfs(y, x);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++) 
    {
      cin >> arr[i][j];
      if (arr[i][j] == 1) prev_cnt++;
    };
  }

  while (++i)
  {
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++) visited[i][j] = 0;
    }
    v.clear();

    dfs(0, 0);

    for (pair<int,int> pi : v) arr[pi.first][pi.second] = 0;
    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (arr[i][j] == 1) cnt++;
      }
    }

    prev_cnt = v.size() + cnt;
    if (cnt == 0) break;
  }

  cout << i << "\n";
  cout << prev_cnt;
  
  return 0;
}