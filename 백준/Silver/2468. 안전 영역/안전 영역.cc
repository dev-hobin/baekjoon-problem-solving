#include <iostream>

using namespace std;

int n, max_sum = -1;

int table[101][101];
int memo[101][101];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int h)
{
  memo[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
    if (table[ny][nx] <= h) continue;
    if (memo[ny][nx] == 1) continue;
    dfs(ny, nx, h);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++) cin >> table[i][j];
  }
  
  for (int h = 0; h <= 100; h++)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
         if (table[i][j] > h && memo[i][j] != 1)
         {
           sum++;
           dfs(i, j, h);
         }
      }
    }
    if (sum > max_sum) max_sum = sum;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++) memo[i][j] = 0;
    }
  }
  
  cout << max_sum;
  return 0;
}