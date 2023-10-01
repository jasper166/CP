 
#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f


int n, C;
//B7
int f[25005];
int a[MAX];
// ket qua toi uu tai vi tri thu i voi khoi luong cai tui la j
// f(n,S):
//O(n * S);
// f(S):
//O(S);
// O(n * S);

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> C >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = C; j >= 1; j--) {
            if (j >= a[i])
                f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }
    cout << f[C] << "\n";

    return 0;
}