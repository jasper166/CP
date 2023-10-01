/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 00:08:55
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
vector <int> b;
bool ok(){
	for (int i = k ; i >= 1; i--)
		if (b[i] != n - k + i) return true;
	return false;
}

long long nCk(){
	int m = max(n - k, k);
	ll res = 1;
	for (int i = m + 1; i <= n; ++i) res *= (1LL * i);
	for (int i = 2; i <= n - m; i++) res /= (1LL * i);
	return res;
}


void combi_num(){
	b.resize(k + 1);
	for (int i = 1; i <= k; ++i) b[i] = i;

	int h = 1, flag = 0;
	while (ok()){
		for (int i = 1; i <= k; i++)
			if (a[i] == b[i]) flag++;
		if (flag == k) break;

		int i = k;
		while (i >= 1  && b[i] == n - k + i) --i;
		b[i]++;
		for (int j = i + 1; j <= k; ++j) b[j] = b[j - 1] + 1; 

		flag = 0;
		h++;
	}
	// cout << h << '\n';
	cout << nCk() - h + 1 << '\n';

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	a.resize(k + 1);
	for (int i = 1; i <= k; ++i) cin >> a[i];
	combi_num();
		 
}
