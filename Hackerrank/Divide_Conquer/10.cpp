/**    
* LANG: C++ 
* author: atom 
* created: 09.06.2022 06:30:31
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


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n];
	for (int &i : a) cin >> i;

	auto it1 = upper_bound(a, a + n, 0);
	auto it2 = lower_bound(a, a + n, 0);
	if (it2 != a + n){
		int j = it1 - a;
		int i = it2 - a;
		cout << j - i << '\n';
	}	 
	else cout << "0\n";
}
