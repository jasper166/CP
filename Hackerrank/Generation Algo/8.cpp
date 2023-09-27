/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 23:58:59
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
vector <int> b;
bool ok(){
	for (int i = n - 1; i >= 1; --i)
		if (b[i] < b[i + 1]) return true;
	return true;
}


void permu_num(){
	b.resize(n + 1);
	for (int i = 1; i <= n; ++i) b[i] = i;

	int k = 1, flag = 0;
	while (ok()){
		for (int i = 1; i <= n; i++)
			if (a[i] == b[i]) flag++;
		if (flag == n) break;

		int i = n - 1;
		while (i >= 1 && b[i] > b[i + 1]) --i;
		int j = n;
		while (j >= 1 && b[j] < b[i]) --j;

		swap(b[i], b[j]);
		sort(b.begin() + i + 1, b.end());

		flag = 0;
		k++;
	}
	cout << k << '\n';

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	permu_num();
		 
}
