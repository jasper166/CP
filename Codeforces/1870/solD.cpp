#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, k;
int c[N];
inline void giveAns(vector <int> ans) {
    for (int x : ans) cout << x << " ";
    cout << "\n";
    return; 
}
void run_case() {
    map <int, int> mp;
    vector <pii> dp, ndp;

    cin >> n;
    REP(i, n) {
        cin >> c[i];
        mp[c[i]] = i;
    }
    cin >> k;

    mp[-1] = -1;
    int pos = 0;
    int mi = *min_element(c, c + n);
    for (auto &[x, cnt] : mp) {
        if (x > mi * 2) break;
        if (cnt >= pos) {
            int nxt;
            if (!dp.empty()) {
                int have = x - dp.back().fi;
                nxt = k / have;
                nxt = min(dp.back().se, nxt);
                k -= nxt * have;
                if (nxt != dp.back().se)
                    dp.back().se -= nxt;
                else 
                    dp.pop_back();
            }
            else {
                nxt = k / x;
                k -= nxt * x;
                k = min(k, x - 1);
            }
            dp.push_back(make_pair(x, nxt));
            pos = max(pos, cnt);
        }
    }
    ndp.push_back({-1, -1});
    REP(i, (int) dp.size()) ndp.push_back(dp[i]);
    dp.swap(ndp);

    int sum = 0;
    vector <int> ans(n, 0);
    PER(i, (int) dp.size()) {
        auto [x, y] = dp[i];
        sum += y;
        FORD (j, mp[x], mp[dp[i - 1].fi] + 1)
            ans[j] += sum;
    }
    giveAns(ans);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
