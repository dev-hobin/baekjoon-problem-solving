#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (getline(cin, str))
  {
    if (str == ".") break;
    
    stack<char> stk;
    bool flag = true;
    for (char c : str)
    {
      if (c != '(' && c != ')' && c != '[' && c != ']') continue;
      if (stk.empty())
      {
        if (c == ']' || c == ')') flag = false; 
        else stk.push(c);
      }
      else if (stk.top() == '(' && c == ')') stk.pop();
      else if (stk.top() == '[' && c == ']') stk.pop();
      else if (stk.top() == '(' && c == ']') flag = false;
      else if (stk.top() == '[' && c == ')') flag = false;
      else stk.push(c);
    }
    if (!stk.empty()) flag = false;

    if (flag) cout << "yes" << "\n";
    else cout << "no" << "\n";
  }
  
  return 0;
}