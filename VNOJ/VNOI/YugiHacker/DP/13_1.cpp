/**    
* LANG: C++ 
* author: atom 
* created: 04.06.2022 17:59:02
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
int n, k, e[MAX];
ll s, dp[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	deque < int > dq;
	for(int i = 1; i <= n; i++)
		cin >> e[i],
		s += e[i];
	dq.push_back(0);
	for(int i = 1; i <= n + 1; i++){
		if(i - k - 1> dq.front())dq.pop_front();
	    dp[i] = dp[dq.front()] + e[i];
		while(!dq.empty() && dp[dq.back()] > dp[i])dq.pop_back();
		dq.push_back(i);
	}
	debug(dp[n + 1]);
	cout << s - dp[n + 1];
	return 0;
}