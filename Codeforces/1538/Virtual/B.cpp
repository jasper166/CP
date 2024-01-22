#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int INF = 1e9;
void run() {
	int n; cin >> n;
	vector <int> a(n);
	for (int& x : a) cin >> x;

	bool ok = *min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end());
	if (n == 1 || ok) {
		cout << "0\n";
		return;
	}

	ll sum = accumulate(a.begin(), a.end(), 0ll);
	if (sum % n) {
		cout << "-1\n";
		return;
	}

	int req = sum / n;

	int need = 0, have = 0;
	int lb = 0, rb = 0;
	for (int x : a) {
		if (x < req) {
			lb += x;
			++need;
		}
		if (x > req) {
			rb += x;
			++have;
		}
	}

	if (need * req - lb <= rb - have * req) cout << have << "\n";
	else cout << "-1\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int t = 1; 
    cin >> t;
    while (t--) {
    	run();
    }
}

