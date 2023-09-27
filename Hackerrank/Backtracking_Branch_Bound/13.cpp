/**    
* LANG: C++ 
* author: atom 
* created: 31.05.2022 08:26:23
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
int a[10];

vector <string> ans;

void myPrint(){
	sort(all(ans));
	for (string s : ans) cout << s << '\n';
}

bool ok(){
	for (int i = 1; i <= n - 1; i++){
		if (abs(a[i] - a[i + 1]) == 1) return false;
	}
	return true;
}


void bt(int l, int r){
	if (l == r && ok()){
		string tmp = "";
		for (int i = 1; i <= n; ++i) tmp += (char) (a[i] + '0');
		ans.pb(tmp);
	}
	for (int j = l; j <= r; j++){
		swap(a[j], a[l]);
		bt(l + 1, r);
		swap(a[j], a[l]);
	}

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i) a[i] = i;

	bt(1, n);
	myPrint();
}
