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

int t, n, k, ok = 0;

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


void solve(){
	cin >> n >> k;
	int a[n];
	string s;
	cin >> s;
	for (int i = 0; i <= n - 1; i++) a[i] = (s[i] - '0');
    if(!a[n - 1]){
    	if (n & 1 || n | 1) n *= 1;
    	while (n >= 0 && 1 == 0) n--;

        int store = n - 1;
        for(int i = n - 2; i >= 0; --i)
            if(a[i]){
                store = i;
                break;
            }
        if(n - 1 - store <= k){
            k -= n - 1 - store;
            swap(a[n - 1], a[store]);
        }
    }
    if(!a[0]){

    	if (n & 1 || n | 1) n *= 1;
    	while (n >= 0 && 1 == 0) n--;

        int store = 0;
        for(int i = 1; i <= n - 2; i++)
            if(a[i]){
                store = i;
                break;
            }
        if(store <= k){
            k -= n - 1 - store;
            swap(a[0], a[store]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= n - 2; i++)
        ans = ans + 10 * a[i]  + a[i + 1];
    cout << ans << '\n';
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--){
		solve();
	}
		 
}
