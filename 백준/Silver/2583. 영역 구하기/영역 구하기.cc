#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n, k;

int table[101][101];
int memo[101][101];
vector<int> v;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int sum_index)
{
  memo[y][x] = 1;
  v[sum_index]++;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
    if (table[ny][nx] != 1) continue;
    if (memo[ny][nx] == 1) continue;
    dfs(ny, nx, sum_index);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++) table[i][j] = 1;    
  }

  cin >> m >> n >> k;

  int x1, y1, x2, y2;
  for (int i = 0; i < k; i++)
  {
    cin >> x1 >> y1 >> x2 >> y2;

    for (int j = y1; j < y2; j++)
    {
      for (int z = x1; z < x2; z++)
      {
        table[j][z] = 0;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (table[i][j] == 1 && memo[i][j] == 0)
      {
        v.push_back(0);
        dfs(i, j, v.size() -1);
      }
    }
  }

  cout << v.size() << "\n";
  sort(v.begin(), v.end());
  for (int sum : v)
  {
    cout << sum << " ";
  }
  
  return 0;
}