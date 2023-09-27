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

#define int long long
using pii = pair < int, int >;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, a[N];
void run_case() {
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	ll pos = 0, even = 0, parity = n & 1, mx = -INF, sum = 0;
	FORD(i, n , 1) {
		if (!parity) {
			if (a[i] >= 0){
				even += a[i];
				pos = a[i]; 
				mx = -INF;
			}
		} 
		else {
			mx = max(mx, a[i]);
			if (mx >= 0){
				sum += mx; 
				sum += even;
				mx = -INF; 
				even = pos = 0;
			}
			
		}
		parity ^= 1;
	}
	int ans = sum;
	if (n == 1)
		ans = max(0ll, a[1]);
	else {
		if (a[2] <= 0)
		mx = 0;
		ans += max({0LL, mx + even, even - pos});
	}
	cout << ans << "\n"; 

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
