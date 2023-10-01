/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 11:56:07
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
int cnt;

void out(){
	string tmp = "";
	for (int i = 1; i <= cnt; ++i){
		tmp += to_string(a[i]);
		if (i != cnt) tmp += "+";
	}
	ans.pb(tmp);

}

bool ok(int i){
	return (i != 0);
}

void sum_gen(){

	a.resize(n + 1);
	a[1] = n;
	cnt = 1;
	int i = cnt;
	while (ok(i)){
		
		out();

		i = cnt;
		while (i >= 1 && a[i] == 1) --i;
		if (i == 0) break;
		
		a[i]--;
		int need = cnt - i + 1;
		// debug(cnt);
		cnt = i + 1;
		int d = need / a[i], rem = need % a[i];
		// debug(d);
		if (d)
			for (int j = 1; j <= d; ++j, cnt++)
				a[cnt] = a[i];
		if (rem)
			a[cnt++] = rem;
		--cnt;
	}
	cout << ans.size() << '\n';
	for (string k : ans)
		cout << k << '\n';
}



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	sum_gen();	 
}
