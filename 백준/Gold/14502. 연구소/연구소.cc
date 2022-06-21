#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, max_count;
int arr[10][10];
vector<pair<int, int>> vpoint_pairs;
vector<pair<int,int>> cand;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y_idx, int x_idx, int (&temp)[10][10])
{
  if (temp[y_idx][x_idx] == 1) return;
  for (int i = 0; i < 4; i++)
  {
    int y = y_idx + dy[i];
    int x = x_idx + dx[i];
    if (y < 1 || y > n || x < 1 || x > m) continue;
    if (temp[y][x] == 1) continue;
    if (temp[y][x] == 2) continue;
    temp[y][x] = 2;
    dfs(y, x, temp);
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
    for (int j = 1; j <= m; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == 0) cand.push_back(make_pair(i,j));
      if (arr[i][j] == 2) vpoint_pairs.push_back(make_pair(i,j));
    } 
  }

  bool is_spread = false;
  for (pair<int, int> pi : vpoint_pairs)
  {
    for (int i = 0; i < 4; i++)
    {
      int y = pi.first + dy[i];
      int x = pi.second + dx[i];
       if (y < 1 || y > n || x < 1 || x > m) continue;
      if (arr[y][x] == 0) is_spread = true;
    }
  }

  if (!is_spread) {
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (arr[i][j] == 0) count++;
      }
    }
    cout << count;
    return 0;
  }

  vector<bool> checker(cand.size(), false);
  for (int i = 0; i < 3; i++) checker[i] = true;

  do {
    int count = 0;
    int temp[10][10];
    
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        temp[i][j] = arr[i][j];
      } 
    }

    for (int i = 0; i < cand.size(); i++)
    {
      if (checker[i])
      {
        int y, x;
        tie (y, x) = cand[i];
        temp[y][x] = 1;
      }
    }

    for (pair<int, int> pi : vpoint_pairs) dfs(pi.first, pi.second, temp);

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (temp[i][j] == 0) count++;
      }
    }

    if (max_count < count) max_count = count;
  } while (prev_permutation(checker.begin(), checker.end()));

  cout << max_count;

  return 0;
}