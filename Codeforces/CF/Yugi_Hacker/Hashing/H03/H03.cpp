/**    
* LANG: C++ 
* author: atom 
* created: 24.05.2022 08:30:49
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


string s, t;

ll H1[MAX], H2[MAX], myPow[MAX], base = 31;

ll getHash_1(int i, int j){
	return (H1[j] - H1[i - 1] * myPow[j - i + 1] % MOD + MOD) % MOD;
}

ll getHash_2(int i, int j){
	return (H2[j] - H2[i - 1] * myPow[j - i + 1] % MOD + MOD) % MOD;
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> t;
	int n = s.size(), m = t.size();
	string ans = s;
	s = ' ' + s;
	t = ' ' + t;
	myPow[0] = 1;
	for (int i = 1; i <= MAX - 1; ++i) myPow[i] = (myPow[i - 1] * base) % MOD;

	for (int i = 1; i <= n; ++i)
		H1[i] = (H1[i - 1] * base + s[i] - 'a' + 1) % MOD;
	for (int i = 1; i <= m; ++i)
		H2[i] = (H2[i - 1] * base + t[i] - 'a' + 1) % MOD;

	int lim = min(n, m), res = 0;
	for (int i = 1; i <= lim; i++){
		if (getHash_1(n - i + 1, n) == getHash_2(1, i))
			res = max(res, i);
	}

	for (int i = res + 1; i <= m; i++) ans += (char) (t[i]);

	cout << ans << '\n';
}
