/**    
* LANG: C++ 
* author: atom 
* created: 12.06.2022 08:28:35
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


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	int n;
	cin >> n;
	vector <pii> v(2 * n);
	vector <int> diff;
	int sum = 0;
	for (auto &i : v){
		cin >> i.F >> i.S;
		sum += i.F;
		diff.pb(i.S - i.F);
	}
	sort(all(diff));
	FOR(i, 0, n - 1) sum += diff[i];
	cout << sum << '\n'; 
}
