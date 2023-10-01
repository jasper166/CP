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

int n, k;
string s;


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> k >> s;
		int ans = n;
		int v[n + 1];
		v[0] = 0;
		int i = 0;
		for (char &c : s){
			v[i + 1] = (c == 'B');  
			v[i + 1] += v[i];
			i++;
		}
		for (int j = k; j <= n; j++)
			if (k + v[j - k] < v[j] + ans) ans = k - v[j] + v[j - k];
			// ans = min(ans, k - v[j] + v[j - k]);
		cout << ans << '\n';
	} 
}
