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

ld a[MAX], pre[MAX], suff[MAX];
int n, d, pos[MAX];
pii ans = {1, 1};

bool ok(ld avg){
	FOR(i, 1, n)
		pre[i] = pre[i - 1] + (a[i] - avg);
	suff[1] = pre[1];
	pos[1] = 1;
	FOR(i, 2, n){
		if (suff[i - 1] <= pre[i]){
			suff[i] = suff[i - 1];
			pos[i] = pos[i - 1];
		}
		else {
			suff[i] = pre[i];
			pos[i] = i;
		}
	}
	FOR(i, d, n){
		// special case
		if (pre[i] >= 0){
			ans = {1, i};
			return true;
		}
		if (pre[i] >= suff[i - d]){
			ans = {pos[i - d] + 1, i};
			return true;
		}
	}
	return false;
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> d;
	FOR(i, 1, n){
		cin >> a[i];
	}
	// bs on average value, any length is ok if it has maximum average
	// check ans with case which all elements are 0
	// check if average is possible 
	ld l = 0, r = 1e9;
	FOR (c, 0, 200){
		ld m = (l + r) / 2;
		if (ok(m)) l = m;
		else r = m;
	}	
	cout << ans.F << " " << ans.S << '\n';
}
/* problem link: 

*/
/* check in O(n)
 using prefix sum: pre(i) = pre(i - 1) + a(i) - avg
 using another prefix array: suff
 if suff(i - 1) <= pre(i) -> we can begin to make a segment from here:
  	suff(i) = suff(i - 1)
  	pos(i) = pos(i - 1)
  else we try to create a new segment from current position
  	suff(i) = pre(i)
  	pos(i) = i

 */