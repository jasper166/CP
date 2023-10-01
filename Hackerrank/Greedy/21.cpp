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

int t, a, b;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> a >> b;
		cout << min({a , b, (a + b) / 3}) << '\n';
	}
	
}
