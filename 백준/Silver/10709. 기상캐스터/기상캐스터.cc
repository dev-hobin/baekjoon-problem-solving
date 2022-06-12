#include <iostream>

using namespace std;

int h, w;
int m[101][101];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w;

  char c = 'n';
  for (int i = 0; i < h; i++)
  {
    int cnt = -1;
    for (int j = 0; j < w; j++)
    {
      cin >> c;
      if (c == 'c')
      {
        cnt = 0;
        m[i][j] = 0;
      }
      else if (cnt == -1) m[i][j] = -1;
      else
      {
        ++cnt;
        m[i][j] = cnt;
      }
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++) cout << m[i][j] << " ";
    cout << "\n";
  }
  
  return 0;
}