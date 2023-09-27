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


int atm[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int ans = 0;
	for (int i = 9; i >= 0; i--){
		int j = n / atm[i];
		if (j) n %= atm[i];
		ans += j;
	}	 
	cout << ans << '\n';
}
