/**    
* LANG: C++ 
* author: atom 
* created: 06.06.2022 16:19:18
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
	for (int & i : a) cin >> i;
	int diff = 0, ans = 0;
	map <int, int> pos, neg; 
	pos[0] = 1;
	for (int i : a){
		if (i & 1) diff++;
		else diff--;
		if (diff >= 0){
			ans += pos[diff];
			pos[diff]++;
		}
		else {
			ans += neg[-diff];
			neg[-diff];
		}
	}
	cout << ans << '\n';
		 
}
