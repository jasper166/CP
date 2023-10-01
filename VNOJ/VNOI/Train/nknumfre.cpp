/**    
* LANG: C++ 
* author: atom 
* created: 16.06.2022 09:42:51
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
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int a, b;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> a >> b;
	int cnt = 0;
	FOR(i, a, b){
		string x = to_string(i);
		string y = string(x.rbegin(), x.rend());
		if (__gcd(stoi(y), i) == 1){
			// cout << y << ' ' << i << '\n';
			cnt++;
		}
	}
	cout << cnt << '\n';
		 
}
