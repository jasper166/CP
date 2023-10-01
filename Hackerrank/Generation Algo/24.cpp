/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 19:41:01
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

char c;
int n, k;
vector <int> a;
vector <string> ans;

bool ok(){
	for (int i = k; i >= 1; i--){
		if (a[i] != n) return true;
	}
	return false;
}


void combi(){

	a.resize(k + 1);
	for (int i = 1; i <= k; i++) a[i] = 1;

	while (ok()){
		string tmp = "";
		for (int i = 1; i <= k; i++){
			tmp += (char) (a[i] - 1 + 'A');
		}
		ans.pb(tmp);

		int i = k;
		while (i >= 1 && a[i] == n) --i;
		a[i]++;
		for (int j = i + 1; j <= k; j++) a[j] = 1;

	}
	string tmp = "";
	for (int i = 1; i <= k; i++){
		tmp += (char) (a[i] - 1 + 'A');
	}
	ans.pb(tmp);


	for (string s : ans) cout << s << '\n';

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c >> k;
	n = c - 'A' + 1;
	// debug(n);
	combi();
}
