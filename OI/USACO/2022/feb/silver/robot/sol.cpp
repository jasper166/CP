#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int BASE = 1e9 + 7;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n; 
    pair <int, int> g;
    vector <pair <int, int>> pack;

    cin >> n;
    cin >> g.first >> g.second;

    pack.resize(n);
    for (auto& [x, y] : pack) cin >> x >> y;
    
    vector <ll> cnt[n + 5];
	for (int i = 0; i <= n; ++i) cnt[i].resize((1 << (n / 2)) + 5);
    unordered_map <ll, int> h; 
	int id = 0;
	// f(z, k) : hashing cordinates of (x, y) to z: numbers of way to reach Z using k instructions
	// Solving first half
	int sz = n / 2;
	vector <pair <int, int>> fp;
	for (int i = 0; i < sz; ++i)
		fp.push_back(pack[i]);
	// debug(fp);

	for (int msk = 0; msk < (1 << sz); ++msk) {
		ll x = 0, y = 0;
		ll dx = 0, dy = 0;
		int k = 0;	
		for (int i = 0; i < sz; ++i) {
			if (msk & (1 << i)) {
				dx += fp[i].first;
				dy += fp[i].second;
				++k;
			}
		}
		x += dx;
		y += dy;
		ll z = (1LL * x * BASE + y); // hashing
		if (!h.count(z)) h[z] = ++id;
		int val = h[z];
		cnt[k][val]++;
	}

	// Solving second half
	vector <ll> ans(n + 5);
	vector <pair <int, int>> sp;
	for (int i = sz; i < n; ++i)
		sp.push_back(pack[i]);
	sz = n - sz;

	for (int msk = 0; msk < (1 << sz); ++msk) {
		ll x = g.first, y = g.second;
		ll dx = 0, dy = 0;
		int k = 0;	
		for (int i = 0; i < sz; ++i) {
			if (msk & (1 << i)) {
				dx += sp[i].first;
				dy += sp[i].second;
				++k;
			}
		}
		x -= dx;
		y -= dy;
		ll z = (1LL * x * BASE + y); // hashing
		if (!h.count(z)) continue;
		int val = h[z];
		for (int i = k; i <= n; ++i)
			ans[i] += cnt[i - k][val];
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";
}

