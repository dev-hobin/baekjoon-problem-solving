#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string s;

int table[104][104];
int memo[104][104];
queue<pair<int, int>> q;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int y, int x)
{
  memo[y][x] = 1;
  pair<int, int> pi = {y, x};
  q.push(pi);
  while (q.size())
  {
    int qy, qx;
    tie(qy, qx) = q.front();
    q.pop();
    
    for (int i = 0; i < 4; i++)
    {
      int ny = qy + dy[i];
      int nx = qx + dx[i];

      if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
      if (table[ny][nx] != 1) continue;
      if (memo[ny][nx] != 0) continue;
      memo[ny][nx] = memo[qy][qx] + 1;
      pair<int, int> pi = {ny, nx};
      q.push(pi);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  
  for (int i = 1; i <= n; i++)
  {
    cin >> s;
    int j = 1;
    for (char ch : s)
    {
      table[i][j++] = (int)(ch - '0');
    }
  }
  
  bfs(1,1);
  
  cout << memo[n][m];

  return 0;
}