/**    
* LANG: C++ 
* author: atom 
* created: 30.05.2022 19:49:23
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
int a[20], b[20];
bool ok = false;
// int cur = 0, sum = 0;
vector <int> ans;
int m;

void myPrint(){
		cout << '[';
		m = ans.size();
		for (int j = 0; j <= m - 2; j++) cout << ans[j] << ' ';
		cout << ans[m - 1] << "]\n";
		ok = true;
}


void bt(int i, int cur){
	if (cur == k){
		myPrint();
		return;
	}
	if (i <= n - 1 && cur + a[i + 1] <= k){
		ans.pb(a[i + 1]);
		bt(i + 1, cur + a[i + 1]);
		ans.pop_back();
	}
	if (i <= n - 1) bt(i + 1, cur);

}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a + 1, a + n + 1);
	bt(0, 0);
	if (!ok) cout << "-1\n";
		 
}
