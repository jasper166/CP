 
#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f


int n, C;
//B8
int f[25005];
int w[MAX], v[MAX];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> C;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = C; j >= 1; j--) {
            if (j >= w[i])
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[C] << "\n";

    return 0;
}