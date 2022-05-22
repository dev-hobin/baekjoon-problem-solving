#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
ll a,b,c;
map<ll, ll> memo;

ll calculate(ll base, ll exponent, ll mod)
{
  auto search = memo.find(exponent);
  if (search != memo.end())
  {
    return search -> second;
  }

  if (exponent == 1)
  {
    return base % mod;
  }

  ll half = exponent / 2;
  ll num1 = calculate(base, half, mod);
  ll num2 = calculate(base, exponent - half, mod);

  memo[exponent] = ((num1 % mod) * (num2 % mod)) % mod;

  return memo[exponent];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;

  cout << calculate(a, b, c) << "\n";

  return 0;
}