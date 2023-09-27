/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 20:15:40
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
vector <int> a;

bool ok(){
	for (int i = 1; i <= k; i++)
		if (a[i] != n - k + i) return true;
	return false;
}


void gen(){
	a.resize(k + 1);
	for (int i = 1; i <= k; i++) a[i] = i;

	while (ok()){
		for (int i = 1; i <= k; i++) cout << a[i];
		cout << '\n';

		int i = k;
		while (i >= 1 && a[i] == n - k + i) --i;
		a[i]++;
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
	for (int i = 1; i <= k; i++) cout << a[i];
	cout << '\n';

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	gen();

}
