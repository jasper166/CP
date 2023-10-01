/**    
* LANG: C++ 
* author: atom 
* created: 31.05.2022 07:02:52
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

int n, ok = 0, sum = 0;
int a[22];

void bt(int i, int cur){
	if (cur == sum){
		ok = 1;
		 return;
	}
	if (i <= n - 1 && cur + a[i] <= sum)
		bt(i + 1, cur + a[i]);
	if (i <= n - 1)
		bt(i + 1, cur);
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
	if (sum % 2 == 0){
		sum /= 2;
		bt(0, 0);
	}
	cout << ok << '\n';
		 
}
