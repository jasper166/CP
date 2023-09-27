/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 14:38:18
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


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a) cin >> i;

	vector <int> store;
	for (int i = 0; i <= n - 1; ++i){
		if (store.empty()) store.pb(a[i]);
		auto it = lower_bound(all(store), a[i]);
		if (it != store.end()) {
			int k = it - store.begin();
			store[k] = a[i];
		}
		else store.pb(a[i]);
	}
	cout << store.size() << '\n';
		
}
