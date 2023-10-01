 
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f
const int MOD = 1e9 + 7;
const int LIM = 4444444444;

vector <int> nums;
void prepare() {
    queue <int> q;
    q.push(4);
    q.push(7);

    while (!q.empty()) {
        auto x = q.front(); q.pop();
        if (x > LIM)
            break;
        nums.push_back(x);
        q.push(x * 10 + 4);
        q.push(x * 10 + 7);
    }
    sort(nums.begin(), nums.end());
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    prepare();
    int a, b;
    cin >> a >> b;
    int cur = a;
    ll ans = 0;
    for (; cur < b; ) {
        auto iter = lower_bound(nums.begin(), nums.end(), cur);
        int nxt = *iter;
        // cout << nxt << "\n";
        if (nxt >= b)
            break;
        int cnt = (nxt - cur + 1);
        ans += 1ll * cnt * nxt;
        cur = nxt + 1;
    }
    // cout << ans << " " << cur << "\n";
    auto iter = lower_bound(nums.begin(), nums.end(), cur);
    int nxt = *iter;
    int cnt = (b - cur + 1);
    ans += 1ll * cnt * nxt;

    cout << ans << "\n";
}