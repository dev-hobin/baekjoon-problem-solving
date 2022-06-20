#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string str;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> str;
    stack<char> st;
    for (char ch : str)
    {
      if (st.empty() || st.top() == ch) st.push(ch);
      else if (st.top() != ch)
      {
        if (st.top() == ')' && ch == '(') break;
        else st.pop();
      }
    }
    if (!st.empty()) cout << "NO" << "\n";
    else cout << "YES" << "\n";
  }

  return 0;
}