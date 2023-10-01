/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 09:56:51
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

ll n, k;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	ll f[93];
	f[1] = f[2] = 1;
	for (int i = 3; i <= 92; i++) f[i] = f[i - 1] + f[i - 2];
	while (true){
		if (f[n - 2] < k && k <= f[n - 1] + f[n - 2]){
			k -= f[n - 2];
			--n;
		}
		else if (1 <= k && k <= f[n - 2]) n -= 2;
		if (n <= 2){
			break;
		}
		debug(k);
		debug(n);
	} 
	if (n == 2) cout << "B\n";
	else if (n == 1) cout << "A\n";
}
