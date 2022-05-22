#include <iostream>

using namespace std;

int LOWEST = -10000001;
int d, k, max_sum = LOWEST;
int a[100004];
int psum[100004];

int main()
{
  cin >> d >> k;
  int i = 0;
  while(cin >> a[++i]);
  for (int i = 1; i <= d; i++) psum[i] = psum[i-1] + a[i];
  for (int i = k; i <= d; i++)
  {
    int sum = psum[i] - psum[i-k];
    if (sum > max_sum) max_sum = sum;
  }
  cout << max_sum;
  return 0;
}