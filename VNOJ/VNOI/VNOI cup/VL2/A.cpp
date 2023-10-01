/**    
* LANG: C++ 
* author: atom 
* created: 24.06.2022 23:07:58
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
#define end cout << '\n'
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m;
pair<int, pii> a[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		a[i].S.S = i;
		cin >> a[i].S.F >> a[i].F;
	}
	sort(a + 1, a + n + 1);
	bool flag = true;
	for (int i = 2; i <= n; i++){
		if (a[1].F < a[i].S.F){
			cout << "YES\n" << a[i].S.S << ' ' << a[1].S.S << '\n';
			flag = false;
			break;
		}
	}
	if (flag) cout << "NO\n";

}
/* problem link: 

*/
