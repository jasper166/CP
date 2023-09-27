/**    
* LANG: C++ 
* author: atom 
* created: 22.05.2022 16:03:44
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


int t, k;
string n;

void one(){
	ll m = stoll(n);
	vector <int> ans;
	while (m){
		ans.pb(m % k);
		m /= k;
	}
	for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i];
	cout << '\n';
}


void two(){
	ll ans = 0;
	for (int i = 0; i <= (int) n.length() - 1; ++i){
		ans = (ans * k) + n[i] - '0';
	}
	cout << ans << '\n';

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t >> n >> k;
	if (t == 1) one();
	else two();
		 
}
