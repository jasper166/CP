#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1e6 + 5;
const ll INF = 1e18 + 5;

int n, k;
ll a[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> k;    
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll sum = accumulate(a + 1, a + 1 + n, 0LL);
    ll mx = *max_element(a + 1, a + 1 + n);
    if (sum % k || mx > sum / k) {
        cout << "-1\n";
        return 0;
    }

    using T = pair <ll, ll>;
    priority_queue <T> q;
    for (int i = 1; i <= n; ++i)
        q.push(make_pair(a[i], i));

    vector <vector <ll>> ans;
    // Take k max values
    while ((int) q.size() >= k) {
        int take = 0;
        vector <T> opts;
        while (!q.empty()) {
            if (take == k) break;
            opts.push_back(q.top());
            q.pop();
            ++take;
        }

        ll y = (q.empty()? -1 : q.top().first);
        // subtract value
        ll x;
        if (y == -1) x = opts.back().first;
        else x = min(1LL * opts.back().first, (sum - y * k) / k); 
        
        vector <ll> ids;
        ids.push_back(x);
        for (auto [val, id] : opts) {
            a[id] -= x;
            ids.push_back(id);
            if (a[id] > 0)
                q.push(make_pair(a[id], id));
        }
        sum -= 1LL * k * x;
        ans.push_back(ids);
    }

    cout << (int) ans.size() << "\n";
    for (auto x : ans) {
        for (ll j : x) cout << j << " ";
        cout << "\n";
    }
}


