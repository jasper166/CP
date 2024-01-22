#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = sqrt(1e9 + 5);
bool p[N];
vector <int> primes;
void prepare() {
	memset(p, 1, sizeof p);
	p[0] = p[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (p[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j <= N; j += i)
				p[j] = 0;
		}
	}
}

int count(int x) {
	int ret = 0;
	for (int i : primes) {
		if (x % i == 0) {
			while (x % i == 0) {
				x /= i;
				++ret;
			}
		}
	}
	if (x != 1) ret++;
	return ret;
}

void run() {
	int a, b, k;
	cin >> a >> b >> k;

	// 0 operation
	if (a == b && k == 0) {
		cout << "YES\n";
		return;
	}

	// 1 operation
	if (k == 1) {
		int g = __gcd(a, b);
		if (a == b) {
			cout << "NO\n";
			return;
		}
		if (g == a || g == b) {
			cout << "YES\n";
			return;
		}
		cout << "NO\n";
		return;
	}

	// other case requires minimum 2 operations
	int ret = count(a) + count(b);
	cout << (2 <= k && k <= ret? "YES\n" : "NO\n");
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();
    int t = 1; cin >> t;
    while (t--) {
    	run();
    }
}

