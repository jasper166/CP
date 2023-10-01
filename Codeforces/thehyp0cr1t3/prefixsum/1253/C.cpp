/**    
* LANG: C++ 
* author: atom 
* created: 16.06.2022 19:53:27
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

int n, m;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	int a[n + 1];
	FOR(i, 1, n) cin >> a[i];
	ll prefix[n + 1];
	sort(a + 1, a + n + 1);
	prefix[0] = 0;
	ll cur = 0;

/*		2 3 4 4 6 6 7 8 19
cur		2 5 9 13 19 25 32 40 59
prefix	2 5 11 18 ...

*/
	for (int i = 1; i <= n; i++){
		cur += a[i];
		prefix[i] = cur;
		if (i >= m) prefix[i] += prefix[i - m];

		cout << prefix[i] << ' ';
	}
	cout << '\n';	 
}
