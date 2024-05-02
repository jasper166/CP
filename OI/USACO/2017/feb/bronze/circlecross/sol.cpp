#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string s; cin >> s;
    map <char, pair <int, int>> cnt;
    for (int i = 0; i < s.size(); ++i) {
    	char x = s[i];
    	if (!cnt.count(x))
    		cnt[x] = {i, -1};
    	else 
    		cnt[x].second = i;
    }

    int ans = 0;
    for (char x = 'A'; x <= 'Z'; ++x) {
    	for (char y = 'A'; y <= 'Z'; ++y) {
    		if (cnt[x].second > cnt[y].first && cnt[x].first < cnt[y].first && cnt[y].second > cnt[x].second) {
    			++ans;
    		}
    	}
    }
    cout << ans << "\n";
}

