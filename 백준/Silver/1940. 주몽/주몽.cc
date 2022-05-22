#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int N, M, count_num = 0;
vector<int> base;
vector<int> b;

void combi(int start, int choice, vector<int> &base, vector<int> &b)
{ 
  if(b.size() == choice)
  {
    if (accumulate(b.begin(), b.end(), 0) == M) count_num++;
    return;
  }
  for(int i = start + 1; i < base.size(); i++)
  { 
    b.push_back(base[i]);
    combi(i, choice, base, b);
    b.pop_back();
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  int v;
  while(cin >> v) base.push_back(v);

  combi(-1, 2, base, b);

  cout << count_num;
  
  return 0;
}