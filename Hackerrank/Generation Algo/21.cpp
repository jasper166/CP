/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 17:53:23
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n;
vector <int> a;


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> n;
	a.resize(n);
	for (int &i : a) cin >> i;
	ll res = 1e18;
	for (int i = 1; i <= (1 << n); i++){
		ll sum0 = 0, sum1 = 0;
		for (int j = 0; j <= n - 1; j++){
			if (i & (1 << j)) sum1 += a[j];
			else sum0 += a[j];
		}
		res = min(abs(sum0 - sum1), res);
	}
	cout << res << '\n';

}
