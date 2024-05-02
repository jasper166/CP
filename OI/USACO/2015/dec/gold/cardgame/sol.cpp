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

int n;
bool card[N];
int a[N];
void run_case() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		a[i] = x;
		card[x] = 1;
	}

	vector <int> bessie;
	for (int i = 1; i <= 2 * n; ++i) {
		if (!card[i])
			bessie.push_back(i);
	}

	set <int> lhs, rhs;
	for (int i = 0; i < n; ++i) {
		if (i < n / 2)
			rhs.insert(bessie[i]);
		else 
			lhs.insert(bessie[i]);
	}

	// debug(bessie);
	debug(lhs, rhs);
	int ans = 0;
	for (int i = 1; i <= n / 2; ++i) {
		auto it = lhs.upper_bound(a[i]);
		if (it != lhs.end()) {
			ans++;
			lhs.erase(it);
		}
	}

	for (int i = n / 2 + 1; i <= n; ++i) {
		auto it = rhs.lower_bound(a[i]);
		if (it != rhs.begin()) {
			ans++;
			rhs.erase(prev(it));
		}
	}

	cout << ans << "\n";
		
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

    // setIO("cardgame");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
