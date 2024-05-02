#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int M = 2019;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    string s; cin >> s;
    vector <int> cnt(M, 0);

    int p = 1;
    int cur = 0;
    int n = s.size();
    ll ans = 0;
    cnt[0] = 1;
    for (int i = n - 1; i >= 0; --i) {
    	cur = (cur + p * (s[i] - '0') % M) % M;
    	ans += cnt[cur];
    	cnt[cur]++;
    	p = (p * 10) % M;

    	debug(cur, i);
    }

    cout << ans << "\n";

    return 0;
}

	