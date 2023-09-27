/**    
* LANG: C++ 
* author: atom 
* created: 18.06.2022 19:31:16
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	vector <pii> a(n);
	FOR(i, 0, n - 1) cin >> a[i].F >> a[i].S;
	ll ans = 0;
	sort(all(a), [&] (const pii &a, const pii &b) -> bool{
		return a.S > b.S;
	});
	
	vector <bool> used(MAX, true);
	FOR(i, 0, n - 1){
		FORD(j, a[i].F - 1, 0){
			if (used[j]){
				used[j] = false;
				ans += a[i].S;
				break;
			}
		}
	}


	cout << ans << '\n';

}
