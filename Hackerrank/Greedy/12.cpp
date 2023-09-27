/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 01:21:11
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
	int x = -1, y = -1;

	for (int i = 0; i * 4 <= n; i++){
		int j = (n - 4 * i) / 7;
		if (j >= 0 && 4 * i + 7 * j == n){
			x = i;
			y = j;
			break;
		}
	}
	// cout << x << ' ' << y << '\n';
	string ans = "";
	if (x >= 0 && y >= 0){
		for (int i = 1; i <= x; i++) ans += '4';
		for (int i = 1; i <= y; i++) ans += '7';	
	}
	else ans = "-1";
	cout << ans << '\n';
}
