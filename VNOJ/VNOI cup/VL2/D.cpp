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
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, k, q;
int a[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	cin >> q;
	while (q--){
		pii b;
		cin >> b.F >> b.S;
		vector <int> c(n + 1, 0);
		FOR(i, b.F, b.S) c[a[i]]++;
		int ans = 0;
		bool flag = true;
		FOR(i, 1, n){
			if (c[i] && c[i] != k){
				ans = i;
				flag = false;
				break;
			}
		}
		cout << (flag? 0 : ans) << '\n';
	}
		 
}
/* problem link: 

*/
