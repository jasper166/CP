/**    
* LANG: C++ 
* author: atom 
* created: 31.05.2022 21:33:50
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

int t, n;

void solve(){
	cin >> n;
	int a[n];
	map<int, vector<int>> mp;
	vector <int> res;
	int ans;
	int k = 0;
	for (int i : a){
		cin >> i;
		mp[i].pb(k++ + 1);
	}
		
        
        bool flag = true;
        for (auto i : mp){
            if (i.S.size() > 1){
            	for (int j = 1; j < mp[i.F].size(); ++j) res.pb(mp[i.F][j]);
                res.pb(mp[i.F][0]);
                            }
            else{
                ans =  -1;
                flag = false;
                break;
            }

        }
        if (flag)
            for (auto i: res) cout << i << ' ';
    	else cout << ans;
    	cout << '\n';
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		solve();
	}
		 
}
