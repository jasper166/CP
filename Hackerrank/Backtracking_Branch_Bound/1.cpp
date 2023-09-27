/**    
* LANG: C++ 
* author: atom 
* created: 30.05.2022 17:52:48
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

int n, k, s;
int cur = 0, cnt = 0;
vector <int> a(22);
bool b[22];

void bt(int i){

	if (i == k){
		cnt++;
		return;
	}

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> s;
	for (int i = 1; i <= n; ++i) a[i] = i;

	for (int i = 0; i <= (1 << n) - 1; ++i){
		int d = 0, cur = 0;
		vector <int> ans;
		for (int j = 0; j <= n - 1; j++){
			if (i & (1 << j)){
				cur += a[j + 1];
				d++;
				ans.pb(a[j + 1]);
			}
			// if (d == k) break;
		}
		if (cur == s && d == k){
			cnt++;
			// cout << cur << '\n';
			// for (int v : ans) cout << v << ' ';
			// cout << '\n';
		}
	}
	// bt(1);
	cout << cnt << '\n';
}
