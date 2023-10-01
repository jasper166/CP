/**    
* LANG: C++ 
* author: atom 
* created: 01.06.2022 21:43:37
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

int n, h;
int a[10002];


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> h;
	for (int i = 0; i <= n - 1; i++) cin >> a[i];

	auto ok = [&] (int m){
		vector <int> b(a, a + m);
		sort(all(b), greater <int> ());
		ll bottles = 0;
		for (int i = 0; i <= (int) (b.size() - 1); i++){
			if (i % 2 == 0) bottles += (b[i]);
			if (bottles > h) return false;
		}
		return true;
	};

	int l = 0, r = n, ans = 0;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (ok(mid)){
			ans = max(mid, ans);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ans << '\n';
}
