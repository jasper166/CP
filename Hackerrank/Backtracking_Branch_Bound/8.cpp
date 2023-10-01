/**    
* LANG: C++ 
* author: atom 
* created: 30.05.2022 22:38:33
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

int n, k;
int a[50];
int sum = 0, ok = 0;

void Try(int i, int cur){
	if (cur == sum){
		ok = 1;
		return;
	}
	if (cur > sum || ok) return;
	if (i <= n - 1 && cur + a[i + 1] <= sum)
		Try(i + 1, cur + a[i + 1]);
	if (i <= n - 1) Try(i + 1, cur);
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
	sort (a + 1, a + n + 1);
	
	if (sum % k) cout << "0\n";
	else {
		sum /= k;
		Try(0, 0);
		cout << ok << '\n';
	}
}
