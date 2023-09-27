/**    
* LANG: C++ 
* author: atom 
* created: 04.06.2022 14:29:42
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define mp make_pair
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
string ans = "";
int n, m;

pair<int, pii> max_pipii(pair<int, pii> a, pair<int, pii> b){
	return max(a, b);
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> t;
	n = s.size(), m = t.size();
	vector <vector<pair<int, pii>>> dp(n + 1, vector<pair<int, pii>> (m + 1, {0, {0, 0}}));

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; j++){
			if (s[i] == t[j]){
				dp[i + 1][j + 1] = max_pipii(dp[i + 1][j + 1], mp(dp[i][j].F + 1, mp(i, j)));
			}
			dp[i + 1][j] = max_pipii(dp[i + 1][j], mp(dp[i][j].F, mp(i, j)));
			dp[i][j + 1] = max_pipii(dp[i][j + 1], mp(dp[i][j].F, mp(i, j)));
		}
	}
	pair<int, pii> ans = {0, {0, 0}};
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++)
			ans = max_pipii(ans,  mp(dp[i][j].F, mp(i, j)));
	}
	// debug(ans);
	string tmp = "";
	pii cur = ans.S;
	while (cur.F && cur.S){
		int i = cur.F;
		int j = cur.S;
		pii previous = dp[i][j].S;
		if (previous == make_pair(i - 1, j - 1)){
			// assert;
			if (s[i - 1] == t[j - 1]) tmp = s[i - 1] + tmp;
		}
		cur = previous;
	}
	cout << tmp << '\n';
}