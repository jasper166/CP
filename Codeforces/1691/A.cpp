/**    
* LANG: C++ 
* author: atom 
* created: 31.05.2022 21:33:50
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

int t;

void solve(){

	int n;
	cin >> n;
	int a[n];
	int odd = 0, even = 0;
	for (int &i : a){
	    cin >> i;
	    if (i & 1) odd++;
	    else even++;
	}
	cout << min(odd, even) << '\n';
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		solve();
	}
		 
}
