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
const int N = 2e5 + 5;

int n, k, b[N], h[N];
int check[N];

void run_case() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (i != b[i]) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
		return;
	}

	for (int i = 0; i <= n; i++) {
		check[i] = -1;
	}

	for (int i = 1; i <= n; i++) {
		int p = i;
		while (check[p] == -1) {
			check[p] = i;
			p = b[p];
		}
		if (check[p] != i) continue;
		int x = p;
		int cnt = 0;
		do {
			cnt++;
			x = b[x];
		} while (x != p);
		if (cnt != k) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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
