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

// #define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e4 + 5;


int n;
vector <ll> a;

bool workable_right(ll x, ll rad) {
	int nxt = 0;
	while (x < a.back()) {
		// cout << nxt << " " << x << "\n";
		while (nxt + 1 < n && x + rad >= a[nxt + 1]) ++nxt;
		// cout << a[nxt] << " " << x << "\n";
		if (a[nxt] == x) return 0;
		x = a[nxt];
		rad -= 2;
	}
	return 1;
}

bool workable_left(int x, int rad) {
	for (auto& i : a) i *= -1;
	reverse(a.begin(), a.end());
	// for (int i : a) cout << i << " ";
	// cout << "\n";
	bool ans = workable_right(-x, rad);
	for (auto& i : a) i *= -1;
	reverse(a.begin(), a.end());
	return ans;
}


void run_case() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] *= 2;
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	n = a.size();

	// for (int i : a) cout << i << " ";
	// cout << "\n";

	// cout << (workable_left(22, 0));
	ll lo = 0, hi = 2 * INF;
	ll ans = -1;
	while (lo <= hi) {
		ll mi = (lo + hi) / 2;
		// cout << lo << " " << hi << "\n";
		ll l = a.front(), r = a.back();
		ll pos = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (workable_right(m, mi)) {
				pos = m;
				r = m - 1;
			}
			else 
				l = m + 1;
		}
		// cout << pos << "\n";
		if (workable_left(pos, mi)) {
			ans = mi;
			hi = mi - 1;
		}
		else 
			lo = mi + 1;
	}	
	cout << (ans / 2) << (ans & 1? ".5" : ".0") << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    setIO("angry");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
