 
#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1000005
#define INF 0x3f3f3f
const int MOD = 1e9 + 7;

int n, C;
//B14
int f[MAX];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    f[0] = f[1] = 1; 

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                f[i] = (f[i] + f[i - j]) % MOD;
            }
        }
    }
    cout << f[n] << "\n";

    return 0;
}