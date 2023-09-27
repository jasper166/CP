/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 20:23:44
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
vector <string> ans;

bool ok(){
	for (int i = n - 1; i >= 1; --i){
		if (a[i] < a[i + 1]) return true;
	}
	return false;
}


void rpermu_gen(){
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) a[i] = i;

	while (ok()){
		string tmp = "";
		for (int i = 1; i <= n; i++) tmp += (char) (a[i] + '0');
		ans.pb(tmp);

		int i = n - 1;
		while (i >= 1 && a[i] > a[i + 1]) --i;

		int j = n;
		while (j >= i && a[j] < a[i]) --j;
		
		swap(a[i], a[j]);
		
		sort(a.begin() + i + 1, a.end());
	}
	string tmp = "";
	for (int i = 1; i <= n; i++) tmp += (char) (a[i] + '0');
	ans.pb(tmp);
	
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << '\n';

}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	rpermu_gen();
		 
}
