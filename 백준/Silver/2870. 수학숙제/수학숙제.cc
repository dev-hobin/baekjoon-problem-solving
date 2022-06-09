#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> row;
vector<string> res;

string str_eraze(string s)
{
  while (s[0] == '0')
  {
    if (s.length() == 1) return s;
    s.erase(0, 1);
  }
  return s;
}
bool cmp(string a, string b)
{
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    row.push_back(s);
  }

  for (string r : row)
  {
    string num_str = "";
    for (char c : r)
    {
      int code = (int)c;
      if (code >= 97 && code <= 122)
      {
        if (num_str != "")
        {
          res.push_back(str_eraze(num_str));
        }
        num_str = "";
      } else num_str += c;
    }
    if (num_str != "") res.push_back(str_eraze(num_str));
  }
  
  sort(res.begin(), res.end(), cmp);

  for (string r : res) cout << r << "\n";

  return 0;
}