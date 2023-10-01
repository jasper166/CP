/**    
* LANG: C++ 
* author: atom 
* created: 31.05.2022 08:26:23
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

int n, x;
int a[22];
vector <vector<int>> res;
vector <int> ans;
int ok = 0;

void bt(int j, int cur){
	vector <int> ans;
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
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	bt(1, x);
	if (ok){
		cout << res.size() << '\n';
		for (auto j : res){
			int m = (int) j.size();
			cout << "{";
			for (int i = 0; i <= m - 2; i++) cout << j[i] << ' ';
			cout << j[m - 1] << "}\n";
		}
	}
	else cout << "-1\n";
}
