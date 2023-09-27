/**    
* LANG: C++ 
* author: atom 
* created: 16.06.2022 14:22:59
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

string s;
int t;


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> s;
		int zero = 0, one = 0;
		for (char c : s){
			if (c == '1') one++;
			else zero++;
		}
		int ans = min(zero, one);
		int Pone = 0, Pzero = 0;
		for (char c : s){
			if (c == '1'){
				Pone++;
				one--;
			}
			else {
				Pzero++;
				zero--;
			}
			ans = min({ans, Pone + zero, Pzero + one});
		}
		cout << ans << '\n';
	}
		 
}
