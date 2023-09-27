#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// B18
const int MAX = 1e4 + 5;

int a[MAX];
int n;
int cnt[5];

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = cnt[4];
    ans += cnt[3];
    cnt[1] -= cnt[3];
    if (cnt[1] < 0) cnt[1] = 0;
    
    ans += cnt[2] / 2;
    cnt[2] %= 2;
    // 0 hoac 1
    if (cnt[1] || cnt[2]) {
        if (cnt[2]) {
            ans++;
            cnt[1] -= 2;
        }
        
        if (cnt[1] < 0)
            cnt[1] = 0;

        ans += cnt[1] / 4;    
        cnt[1] %= 4;
        if (cnt[1]) ans++;
    }
    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
