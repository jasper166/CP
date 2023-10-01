/**    
* LANG: C++ 
* author: atom 
* created: 23.06.2022 09:02:40
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define end;
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, a[MAX], pre[MAX][2], suff[MAX][2];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);


	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		if (i & 1){
			pre[i][0] = pre[i - 1][0];
			pre[i][1] = pre[i - 1][1] + a[i];
		}
		else {
			pre[i][1] = pre[i - 1][1];
			pre[i][0] = pre[i - 1][0] + a[i];
		}
	}
	for (int i = n; i >= 1; --i){
		if (i & 1){
			suff[i][0] = suff[i + 1][0];
			suff[i][1] = suff[i + 1][1] + a[i];
		}
		else {
			suff[i][1] = suff[i + 1][1];
			suff[i][0] = suff[i + 1][0] + a[i];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i){
		if (i & 1){
			int tmp = pre[i][1] + suff[i][0] - 2 * a[i];
			int tmp2 = pre[i][0] + suff[i][1] - 2 * a[i];
			ans += (tmp == tmp2);
		}
		else {
			int tmp = pre[i][0] + suff[i][1] - 2 * a[i];
			int tmp2 = pre[i][1] + suff[i][0] - 2 * a[i];
			ans += (tmp == tmp2);
		}
	}
	
	cout << ans << '\n';
}
