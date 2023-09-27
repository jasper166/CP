/**    
 *  @Author: Hiu 
 *  @Handle: at0miccat
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define fi first
#define se second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;

// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif

int orz(){

    // ios_base:: sync_with_stdio(false);
    // cin.tie(nullptr);
	int n;
	scanf("%d", &n);
	int a[n];
	for (int &i : a) scanf("%d", &i);
	map <ll, int> mp;
	mp[0] = 1;
	ll prefix = 0;
	ll cnt = 0;
	for (int i = 0; i <= n - 1; ++i){
		prefix = (prefix + a[i] + n) % n;
		prefix = (prefix + n) % n;
		cnt += 1ll * mp[prefix];
		mp[prefix]++;
	}
    printf("%lld\n", cnt);
}