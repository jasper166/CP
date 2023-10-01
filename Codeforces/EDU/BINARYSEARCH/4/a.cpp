/**    
* LANG: C++ 
* author: atom 
* created: 07.07.2022 17:57:43
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = double;
#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;
constexpr int INF = INT_MAX;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int a[MAX], pre[MAX];
int n, d;
pii ans;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> d;
	FOR(i, 1, n){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	ld v[n + 1];
	pair <ld, int> suff[n + 1];
	// bs on average, any length is ok if it has maximum average
	// check ans with case which all elements are 0
	// check if average is possible 
	ld l = 0, r = 1e9;
	FOR (c, 0, 200){
		ld m = (l + r) / 2;
		ld avg = m;
 
		FOR (i, 0, n) v[i] = pre[i] - avg * i;
		suff[n] = {(ld) v[n], n};

		FORD(i, n - 1, 0){
			if (suff[i + 1].F > v[i])
				suff[i] = suff[i + 1];
			else 
				suff[i] = {v[i], i};
		}
		bool ok = false;
		FOR(i, 1, n){
			if (n - i + 1 >= d && v[i - 1] <= suff[d + i - 1].F){
				ok = true;
				ans = {i, suff[d + i - 1].S};
				break;
			}
		}
		if (ok) l = m;
		else r = m;
	}
	if (ans.F == 0 && ans.S == 0){
		cout << 1 << " " << n << '\n';
	}
	else cout << ans.F << " " << ans.S << '\n';
}
/* problem link: 

*/
