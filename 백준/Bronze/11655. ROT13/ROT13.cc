#include <iostream>
#include <string>
using namespace std;
string s;
string result;
int UPPER_CASE_START = 65;
int UPPER_CASE_END = 90;
int LOWER_CASE_START = 97;
int LOWER_CASE_END = 122;
int main()
{
  getline(cin, s);
  for (int i = 0; i < s.length(); i++)
  {
    int code = (int)s[i];
    if (code >= UPPER_CASE_START && code <= UPPER_CASE_END)
    {
      code += 13;
      if (code > UPPER_CASE_END) code = code - UPPER_CASE_END + UPPER_CASE_START - 1;
    }
    else if (code >= LOWER_CASE_START && code <= LOWER_CASE_END) 
    {
      code += 13;
      if (code > LOWER_CASE_END) code = code - LOWER_CASE_END + LOWER_CASE_START - 1;
    }
    result += (char)code;
  }
  cout << result;
  return 0;
}