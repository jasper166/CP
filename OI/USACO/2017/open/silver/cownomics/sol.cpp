#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1500;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	map <char, int> h;
	h['A'] = 1; h['C'] = 2; h['G'] = 3; h['T'] = 4;

	vector <vector <int>> spot(n, vector <int> (m)), plain(n, vector <int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char x; cin >> x;
			spot[i][j] = h[x];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char x; cin >> x;
			plain[i][j] = h[x];
		}
	}

	int ans = 0;
	array <int, 3> p = {1, 11, 121};
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				set <int> S;
				for (int c = 0; c < n; ++c) {
					int id = (spot[c][i] * p[0] + spot[c][j] * p[1] + spot[c][k] * p[2]);
					S.insert(id);
				}

				bool valid = 1;
				for (int c = 0; c < n; ++c) {
					int id = (plain[c][i] * p[0] + plain[c][j] * p[1] + plain[c][k] * p[2]);
					if (S.count(id)) valid = 0;
				}
				ans += valid;
			}
		}
	}    

	cout << ans << "\n";
}

