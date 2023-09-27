/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 00:30:37
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

int n, k;
vector <int> ans;


bool ok(){
	for (int i = k; i >= 1; --i)
		if (ans[i] != n) return true;
	return false;
}


void rep_combi_gen(){

	ans.resize(k + 1);
	for (int i = 1; i <= k; ++i) ans[i] = 1;

	while (ok()){

		for (int i = 1; i <= k; ++i) cout << ans[i];
		cout << '\n';

		int i = k;
		while (i >= 1 && ans[i] == n) --i;
		ans[i]++;
		for (int j = i + 1; j <= k; j++) ans[j] = 1;
	}
	for (int i = 1; i <= k; ++i) cout << ans[i];
	cout << '\n';
	
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	rep_combi_gen();
		 
}
