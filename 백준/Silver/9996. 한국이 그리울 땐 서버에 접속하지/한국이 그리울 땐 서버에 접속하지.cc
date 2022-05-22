#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s;
string file_name;

vector<string> split(string input, string delimiter)
{
  vector<string> res;
  long long pos = 0;
  string token = "";
  while ((pos = input.find(delimiter)) != string::npos)
  {
    token = input.substr(0, pos);
    res.push_back(token);
    input.erase(0, pos + delimiter.length());
  }
  res.push_back(input);
  return res;
}

int main()
{
  cin >> n;
  cin.ignore();

  getline(cin, s);
  vector<string> splited = split(s, "*");

  while (getline(cin, file_name))
  {
    if (file_name.length() < 2) {
      cout << "NE" << "\n";
      continue;
    }
    
    int pos = file_name.find(splited[0]);
    if (pos != 0 || pos == string::npos)
    {
      cout << "NE" << "\n";
      continue;
    }

    file_name.erase(0, splited[0].length());
    pos = file_name.rfind(splited[1]);
    if (file_name.length() == (pos + splited[1].length())) cout << "DA" << "\n";
    else cout << "NE" << "\n";
  }

  return 0;
}