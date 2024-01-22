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

vector <int> primes;
bool pr[N];
void prepare() {
	memset(pr, 1, sizeof pr);
	pr[0] = pr[1] = 0;
	for (int i = 2; i <= N; ++i) {
		if (pr[i]) {
			primes.push_back(i);
			for (int j = 2 * i; j <= N; j += i)
				pr[j] = 0;
		}
	}		
}

int func(int x) {
	int ret = 0;
	for (int i : primes) {
		while (x % i == 0) {
			++ret;
			x /= i;
		}
	}

	if (x != 1) ++ret;
	return ret;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();

    int t; cin >> t;
    while (t--) {
    	int a, b, k;
    	cin >> a >> b >> k;

    	int g = __gcd(a, b);
    	if (k == 1) {
    		if (a == b) {
    			cout << "NO\n";
    			continue;
    		}
    		if (g == a || g == b) {
    			cout << "YES\n";
    			continue;
    		}
    		cout << "NO\n";
    	}

    	int y = func(a) + func(b);
		cout << (k <= y? "YES\n" : "NO\n"); 
    }

}

