/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 19:27:15
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
vector <int> a;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	set <int> s;
	for (int i = 0; i <= n - 1; ++i){
		int x;
		cin >> x;
		s.insert(x);
	} 
	for (int i : s) a.pb(i);
	sort(all(a), greater <int>());
	do {
		for (int i : a) cout << i << ' ';
		cout << '\n';
	} while (prev_permutation(all(a)));

		 
}
