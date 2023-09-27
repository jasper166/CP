/**    
* LANG: C++ 
* author: atom 
* created: 24.05.2022 09:08:33
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
string s;

ll f1[MAX], f2[MAX], base = 31, myP[MAX];

ll get_hash_1(int x, int y){
	return (f1[y] - f1[x - 1] * myP[y - x + 1] % MOD + MOD) % MOD;
}


ll get_hash_2(int x, int y){
	return (f2[y] - f2[x - 1] * myP[y - x + 1] % MOD + MOD) % MOD;
}

bool ok(int i, int j){
	return (get_hash_1(i, j) == get_hash_2(n - j + 1, n - i + 1));
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;

	string rs = string(s.rbegin(), s.rend());
	
	s = ' ' + s;
	rs = ' ' + rs;
	myP[0] = 1;
	for (int i = 1; i <= n; i++){
		f1[i] =  (f1[i - 1] * base + s[i] - 'a' + 1) % MOD;
		f2[i] =  (f2[i - 1] * base + rs[i] - 'a' + 1) % MOD;
		myP[i] = (myP[i - 1] * base) % MOD;
	} 
		
	for (int i = 1; i <= n; ++i) cout << f1[i] << " " << f2[i] << '\n';

		
	int ans = -1;
	for (int i = 1; i <= n; ++i){
		// even
		int l = 0, r = min(n - i, i);
		while (l <= r){
			int m = (l + r) / 2;
			if (ok(i - m + 1, i + m)){
				ans =  max(ans, 2 * m);
				l = m + 1;
			}
			else r = m - 1;
		}
		//odd
		l = 0, r = min(i, n - i);
		while (l <= r){
			int m = (l + r) / 2;
			if (ok(i - m, i + m)){
				ans = max(ans, 2 * m + 1);
				l = m + 1;
			}
			else r = m - 1;
		}
	}
	cout << ans << '\n';
}
