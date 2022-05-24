#include <iostream>

using namespace std;

int t, n, m, k;

int table[51][51];
int memo[51][51];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
  if (table[y][x] != 1) return;
  if (memo[y][x] == 1) return;
  
  memo[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    dfs(ny, nx);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  for (int i = 0; i < t; i++)
  {
    cin >> n >> m >> k;
    int res = 0;
    for (int j = 0; j < k; j++)
    {
      int y, x;
      cin >> y >> x;
      table[y][x] = 1;
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (table[i][j] != 1 || memo[i][j] == 1) continue;
        res++;
        dfs(i, j);
      }
    }
    
    cout << res << "\n";

    for (int z = 0; z < n; z++)
    {
      fill(table[z], table[z] + m, 0);
      fill(memo[z], memo[z] + m, 0);
    };
  }

  return 0;
}