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

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int LG = 20;

vector <pii> qs[N];
int n, q;
int a[N];
int ans[N], pw[N], basis[LG];
int sz = 0;
void add(int cur_vec) {
	for (int i = 0; i < LG; ++i) {
		if ((cur_vec & (1 << i)) == 0) continue;
		if (!basis[i]) {
			// if there's no basis vector with ith bit set -> insert current vector
			basis[i] = cur_vec;
			++sz;
		}
		// subtract basis vector from current vector
		cur_vec ^= basis[i];
	}
}

bool have(int x) {
	for (int i = 0; i < LG; ++i) {
		if ((x & (1 << i)) == 0) continue;
		if (!basis[i])
			return 0;
		x ^= basis[i];
	}
	return 1;
}

void run_case() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= q; ++i) {
		int l, x;
		cin >> l >> x;
		qs[l].push_back({x, i});
	}

	pw[0] = 1;
	for (int i = 1; i <= n; ++i) pw[i] = (pw[i - 1] * 2ll) % MOD;
	for (int i = 1; i <= n; ++i) {
		add(a[i]);
		for (auto [x, id] : qs[i]) {
			if (have(x))
				ans[id] = pw[i - sz];
		}
	}

	for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";

}

/*
	XOR basis: 
	check if x is representable by basis vectors of current l
	yes-> ans would be 2^(l - b) as each subset of (l - b) non-basis, we can combine to xor sum = x
	no-> 0
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
