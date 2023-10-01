/**    
* LANG: C++ 
* author: atom 
* created: 23.05.2022 21:25:36
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

int t, n, m;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> n;
        ll a[n];
        for (int &i : a) cin >> i;
        cin >> m;
        ll b[m];
        ll sum = 0;
        for (int &i : b) cin >> i, sum += 1ll * i;
        int pos = sum % n;
        cout << a[pos] << '\n';

	}	 
}
