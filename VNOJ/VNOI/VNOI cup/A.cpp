/**    
* LANG: C++ 
* author: atom 
* created: 18.06.2022 19:31:16
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

int t, n;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

		cin >> n;
		int a[n], b[n];
		FOR(i, 0, n - 1) cin >> a[i];
		FOR(i, 0, n - 1) cin >> b[i];
	
		vector <char> c;
		if (a[0] != b[n - 1]){
			FOR(i, 1, n) c.pb('b');
			FOR(i, 1, n) c.pb('a');
		}
		else {
			c.pb('a');
			FOR(i, 1, n) c.pb('b');
			FOR(i, 1, n - 1) c.pb('a');
		}
		for (char x : c) cout << x;
		cout << '\n';
		 
}
