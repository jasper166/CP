/**    
* LANG: C++ 
* author: atom 
* created: 06.06.2022 19:45:22
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

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int s[n];
	for (int &i : s) cin >> i;
	vector <int> prev(n, 1), pos(n, 1);
	int ans = 0;
	for (int i = n - 2; i >= 0; i--){
		if (s[i] < s[i + 1])
			pos[i] = pos[i + 1] + 1;
		ans = max(ans, pos[i]);
	}
	for (int i = 1; i <= n - 1; i++){
		if (s[i - 1] < s[i]) prev[i] = prev[i - 1] + 1;
		ans = max(ans, prev[i]);	 
	}

	for (int i = 0; i <= n - 3; ++i)
		if (s[i] < s[i + 2])
			ans = max(ans, prev[i] + pos[i + 2]);

	cout << ans << '\n';
}
