#include <iostream>
#include <vector>

using namespace std;

int memo[26] = {0,};
vector<char> ch;

int main()
{
    char c;
    while (cin >> c) ch.push_back(c);
    
    for (int i = 0; i < ch.size(); i++)
    {
        int index = (int)ch[i] - 97;
        memo[index] += 1;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << memo[i] << " ";
    }
}