#include <iostream>
#include <algorithm>

using namespace std;

int a[9];
int pos[9] = {0, };
int res[7];

int main()
{
    for (int i = 0; i < 9; i++) cin >> a[i];
    for (int i = 0; i < 7; i++) pos[i] = 1;
    
    do {
        int sum = 0;
        int j = 0;
        for (int i = 0; i < 9; i++) {
			if (pos[i] == 1) {
                sum += a[i];
                res[j++] = a[i];
            }
		}
        if (sum == 100) break;
    } while (prev_permutation(pos, pos + 9));
        
    sort(res, res + 7);
    for (int i = 0; i < 7; i++) cout << res[i] << "\n";
}