#include <iostream>
#include <stack>
#include <string>

// g++ -std=c++14 -Wall a.cpp -o test.out

using namespace std;

int n, res;
string s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    stack<char> st;

    for (char c : s)
    {
      if (st.size() && st.top() == c) st.pop();
      else st.push(c);
    }
    if (st.size() == 0) res++;
  }

  cout << res;
  
  return 0;
}