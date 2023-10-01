/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 13:11:54
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

int n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int a[n];
	int k = 1;
	for (int &i : a) i = k++;

	vector <string> ans;
	for (int i = 1; i < (1 << n); ++i){
		string tmp = "";
		for (int j = 0; j <= n - 1; j++){
			if (i & (1 << j)) tmp = tmp + to_string(a[j]) + ' ';
		}
		ans.pb(tmp);
	}
	sort(all(ans));
	for (int i = 0; i <= (1 << n) - 1; ++i) cout << ans[i] << '\n';
}
