#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string s, res;
map<int, int> _map;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];
    _map[(int)ch]++;
  }

  // 짝수일 경우
  if (s.length() % 2 == 0)
  {
    for (auto it : _map)
    {
      if (it.second % 2 == 1)
      {
        cout << "I'm Sorry Hansoo" << "\n";
        return 0;
      }
      
      for (int i = 0; i < it.second / 2; i++) res += (char)it.first;
    }

    string tail = res;
    reverse(tail.begin(), tail.end());
    res += tail;
  }

  // 홀수일 경우
  if (s.length() % 2 == 1)
  {
    int odd_count = 0;
    char middle_char;
    for (auto it : _map)
    {
      if (it.second % 2 == 1)
      {
        odd_count++;
        middle_char = (char)it.first;
      }
    }
    if (odd_count != 1)
    {
      cout << "I'm Sorry Hansoo" << "\n";
      return 0;
    }

    for (auto it : _map)
    {
      for (int i = 0; i < it.second / 2; i++) res += (char)it.first;
    }

    string tail = res;
    reverse(tail.begin(), tail.end());
    
    res += middle_char;
    res += tail;
  }

  cout << res;

  return 0;
}