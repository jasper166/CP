/**    
* LANG: C++ 
* author: atom 
* created: 22.05.2022 16:50:34
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
ll dp[MAX], base = 31, myP[MAX];
int n, m;

ll get_hash(int l, int r){
	return (dp[r] - dp[l - 1] * myP[r - l + 1] % MOD + MOD) % MOD ;
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> s >> t;
	m = (int) t.length();
	n = (int) s.length();
	ll h1 = 0;

	for (int i = 0; i <= m - 1; i++) h1 = (h1 * base + t[i] - 'a' + 1) % MOD;
	

	myP[0] = 1;
	for (int i = 1; i <= MAX - 1; i++) myP[i] = (myP[i - 1] * base) % MOD;

	dp[0] = s[0] - 'a' + 1;
	for (int i = 1; i <= n - 1; i++)
		dp[i] = (dp[i - 1] * 31 + s[i] - 'a' + 1) % MOD; 

	
	for (int i = 0; i <= n - m; i++){
		if (h1 == get_hash(i, i + m - 1))
			cout << i + 1 << ' ';
	}
	cout << '\n';
}
