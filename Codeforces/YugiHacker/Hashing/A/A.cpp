/**    
* LANG: C++ 
* author: atom 
* created: 24.05.2022 22:11:22
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
	vector <pair<int, int>> a(n);
	int j = 1;
	for (auto &i : a){
		int x; cin >> x;
		i = make_pair(x, j++);
	}
	sort(all(a));
	ll sum = 0;
	for (int i = 0; i <= n - 2; i++){
		sum += 1LL * (abs(a[i].S - a[i + 1].S));
	}
	cout << sum << '\n';
}
