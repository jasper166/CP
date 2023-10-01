/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 20:00:36
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

ll f[93];
int n, t;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	
	f[0] = f[1] = 1;
	for (int i = 2; i <= 92; ++i) f[i] = f[i - 1] + f[i - 2];
	cin >> t;
	while (t--){
		cin >> n;
		cout << f[n] << '\n';
	}

		 
}
