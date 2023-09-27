/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 19:57:59
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
vector <string> ans;
vector <int> bin;

bool ok(){
	for (int i = 1; i <= n; i++){
		if (bin[i] == 0) return false;
	}
	return true;
}

void gen(){
	bin.resize(n + 1);
	for (int i = 1; i <= n; ++i) bin[i] = 0;
	string tmp = "";
	for (int i = 1; i <= n; ++i) tmp += 'A';
	ans.pb(tmp);


	while (!ok()){
		int i = n;
		while (i >= 1 && bin[i] == 1){
			bin[i] = 0;
			--i;
		}
		bin[i] = 1;
		string tmp = "";
		for (int i = n; i >= 1; --i)
			tmp = (char) (bin[i] + 'A') + tmp;
		ans.pb(tmp);

	}
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	gen();
	sort(all(ans), greater <string> ());
	for (string i : ans) cout << i << '\n';
	cout << '\n';
			 
}
