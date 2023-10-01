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
bool used[20];

void bt(int i, int t, int cur){
	if (cur == k){
		cout << '[';
		for (int j = 1; j <= t - 2; j++) cout << b[j] << ' ';
		cout << b[t - 1] << "]\n";
		ok = true;
		return;
	}
		for (int j = i; j <= n; j++){
			if (!used[j] && cur + a[j] <= k){
				used[j] = true;
				b[t] = a[j];
				bt(j, t + 1, cur + a[j]);
				used[j] = false;
			}
		}
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a, a + n + 1);
	memset(used, false, sizeof(used));
	bt(1, 1, 0);
	if (!ok) cout << "-1\n";
		 
}
