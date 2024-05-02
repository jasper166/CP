#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

int mn, mx;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);


    int n, t;
    cin >> n >> t;
    string s; cin >> s;

    vector <int> ill(n);
    for (int i = 0; i < n; ++i) ill[i] = (s[i] == '1');

    vector <array <int, 3>> list(t);
	for (int i = 0; i < t; ++i) {
		int at, a, b;
		cin >> at >> a >> b;
		list[i] = {at, a - 1, b - 1};
	}

	sort(list.begin(), list.end());

	auto able = [&] (int x, int y) -> bool {
		vector <int> n_ill(n);
		vector <int> cnt(n);

		n_ill[x] = 1;
		for (auto [at, a, b] : list) {
			if (n_ill[a]) cnt[a]++;
			if (n_ill[b]) cnt[b]++;
			if (cnt[a] <= y && n_ill[a]) 
				n_ill[b] = 1;
			if (cnt[b] <= y && n_ill[b]) 
				n_ill[a] = 1;
		}
		for (int i = 0; i < n; ++i)
			if (n_ill[i] != ill[i])
				return 0;
		return 1;
	};


	vector <int> candidate;
	mn = 1e9, mx = -1;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y <= t + 1; ++y) {
			if (able(x, y)) {
				mn = min(mn, y);
				mx = max(mx, y);
				candidate.push_back(x);
			}
		}
	}

	sort(candidate.begin(), candidate.end());
	candidate.resize(unique(candidate.begin(), candidate.end()) - candidate.begin());

	cout << candidate.size() << " " << mn << " ";
	if (mx >= t) cout << "Infinity\n";
	else cout << mx << "\n";

}

