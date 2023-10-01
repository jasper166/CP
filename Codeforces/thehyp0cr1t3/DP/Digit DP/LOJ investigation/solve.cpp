/**    
* LANG: C++ 
* author: atom 
* created: 23.06.2022 21:05:08
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define end cout << '\n'
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int t, a, b;
ll k;
ll dp[102][2][102][102];
bool visited[102][2][102][102];

ll memoi(string A, int pos, bool tight, int sum, int rem){
	if (pos == (int) A.size()){
		return (sum % k == 0 && rem % k == 0);
	}	

    if (visited[pos][tight][sum][rem])
    	return dp[pos][tight][sum][rem];
 	
 	visited[pos][tight][sum][rem] = true;

	ll ans = 0;
	int lim = tight? 9 : (A[pos] - '0');
	for (int i = 0; i <= lim; i++){
		ans += memoi(A, pos + 1, (i < A[pos] - '0')? true : tight, (sum + i) % k, (rem * 10 + i) % k);
	}
	return dp[pos][tight][sum][rem] = ans;
}


ll solve(string A){
	memset(visited, false, sizeof(visited));
	return memoi(A, 0, 0, 0, 0); 
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	FOR(i, 1, t) {
		cin >> a >> b >> k;
		string A = to_string(a - 1);
		string B = to_string(b);
		cout << "Case "<< i << ": " << solve(B) - solve(A) << '\n';
	}
		 
}
/* problem link: 
https://lightoj.com/problem/investigation
*/