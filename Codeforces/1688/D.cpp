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


int t;
ll n, k, ok = 1;

void bt(int j, int cur){
	vector <int> ans;
	vector <vector<int>> res;
	int a[100];
	if (cur == 0){
		res.pb(ans);
		ok = 1;
		return;
	}
 
	while (j <= n && cur - a[j] >= 0){
		ans.pb(a[j]);
		bt(j, cur - a[j]);
		j++;
		ans.pop_back();
	}
 
}



int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);;

	cin >> t;
	while (t--){
		cin >> n >> k;
		ll a[n + 1];
		for(int i = 1; i <= n; i++) cin >> a[i];
   		ll ans = 0;


   		int dp[n + 1][4];
		dp[0][0] = 0;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= 3; j++){
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = (dp[i - 1][j] % MOD + (dp[i - 1][j - 1] % MOD * a[i] % MOD)) % MOD;
			}
		}



    	if(n <= k){
    		ans = accumulate(a + 1, a + n + 1, ans);
    		ans += n * k - n * (n - 1) / 2 - n;	
    	}
    	else{
        	ll sum = 0;
        	for(int i = 1; i <= n; i++){
          	  sum += a[i];
            	if(i > k) sum -= a[i - k];
            	if (sum > ans) ans = sum;
       	}
       	ans += k * (k + 1) / 2  - k;
   	 }
   	 cout << ans << '\n';
	}
		 
}
