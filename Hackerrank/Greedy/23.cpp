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

string s;

int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    map <int, int> mp;
    int n = (int) s.size();
    for (int i = 0; i <=  n - 1; i++){
        int len = (s[i] == '1')? 0 : -1;
        while (i <= n - 1 && s[i] == '1'){
            len++;
            i++;
        }
        mp[len]++;
    }
    vector <int> v;
    for (auto &it : mp){
    	if (it.F < 1) continue;
    	while (it.S){
    		v.pb(it.F);
    		it.S--;
    	}
    }
    int ans = 0;
    for (int i = (int) v.size() - 1; i >= 0; i -= 2)
    	ans += v[i];
    cout << ans << '\n';
}