/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 21:31:57
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
// 
// #define debug(x...) cout << "#L" <<__LINE__<< ": " <<" [" << #x << "] = ["; _print(x); cout << '\n';

int n;
vector <string> ans;
vector <string> a;
vector <int> b;

bool ok(){
	for (int i = n - 1; i >= 1; i--)
		if (b[i] < b[i + 1]) return true;
	return false;
}

void gen(){
	b.resize(n + 1);
	for (int i = 1; i <= n; ++i) b[i] = i;
	while (ok()){
		for (int i = 1; i <= n; ++i){
			cout << a[b[i]] << ' ';
		}
		cout << '\n';


		int i = n - 1;
		while (i >= 1 && b[i] > b[i + 1]) --i;

		int j = n;
		while (j >= i && b[j] < b[i]) --j;

		swap(b[j], b[i]);
		
		sort(b.begin() + i + 1, b.end());


	}
	for (int i = 1; i <= n; ++i){
		cout << a[b[i]] << ' ';
	}
	cout << '\n';


}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	gen();

}
