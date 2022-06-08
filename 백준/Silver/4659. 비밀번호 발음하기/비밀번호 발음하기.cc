#include <iostream>
#include <string>
#include <vector>

// g++ -std=c++14 -Wall a.cpp -o test.out

using namespace std;

vector<string> vec;

bool isVowel(char c)
{
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  else return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  while (cin >> s)
  {
    if (s == "end") break;
    vec.push_back(s);
  }
  
  for(string v : vec)
  {
    if (v.find('a') == string::npos 
        && v.find('e') == string::npos 
        && v.find('i') == string::npos
        && v.find('o') == string::npos
        && v.find('u') == string::npos)
    {
      cout << "<" + v << ">" << " is not acceptable.\n";
      continue;
    }

    bool is_continuous = false;
    for (int i = 0; i < v.length(); i++)
    {
      if (i + 2 > v.length() - 1) break;
      if (isVowel(v[i]) && isVowel(v[i+1]) && isVowel(v[i+2])) is_continuous = true;
      if (!isVowel(v[i]) && !isVowel(v[i+1]) && !isVowel(v[i+2])) is_continuous = true;
    }
    if (is_continuous)
    {
      cout << "<" + v << ">" << " is not acceptable.\n";
      continue;
    }

    bool is_same_continuous = false;
    for(char c : v)
    {
      if (v.find(string({c, c})) != string::npos)
      {
        if (c != 'e' && c != 'o')
        {
          is_same_continuous = true;
          break;
        }
      }
    }
    if (is_same_continuous)
    {
      cout << "<" + v << ">" << " is not acceptable.\n";
      continue;
    }

    cout << "<" + v << ">" << " is acceptable.\n";
  }
  return 0;
}