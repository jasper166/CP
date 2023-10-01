/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 07:02:17
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

ll a, b;

void egypt(ll x, ll y){
	if (!x || !y) return;
	
	if (y % x == 0){
		cout <<"1/" << y / x;
		return;
	}
	if (x % y == 0){
		cout << x / y;
		return;
	} 
	if (x > y){
		int j = x / y;
		if (j == 1) cout << "1/";
		cout << j << " + ";
		egypt(x % y, y);
		return;
	}
	int j = y / x + 1;
	cout << "1/" << j << " + ";
	egypt(x * j - y, y * j);
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> a >> b;
	egypt(a, b);	 
}
