#include <iostream>

using namespace std;

int n, m, j, c;
int arr[21];
int left_index, right_index;

void move(int left, int right, int target)
{
  if (left <= 0 || right > n) return;
  if (left > target) 
  {
    c++;
    left_index = left - 1;
    right_index = right - 1;
    move(left_index, right_index, target);
  }
  else if (right < target)
  {
    c++;
    left_index = left + 1;
    right_index = right + 1;
    move(left_index, right_index, target);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> j;
  left_index = 1;
  right_index = m;
  for (int i = 1; i <= j; i++) cin >> arr[i];
  
  for (int i = 1; i <= j; i++) move(left_index, right_index, arr[i]);

  cout << c;

  return 0;
}