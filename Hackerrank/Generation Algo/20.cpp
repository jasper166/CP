/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 16:33:11
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

void panlin_bin(){

	queue <string> q;
	q.push("00");
	q.push("11");
	ans.pb("00");
	ans.pb("11");
	while (!q.empty()){
		string k = "0" + q.front() + "0";
		string l = "1" + q.front() + "1";
		if ((int) k.size() <= n) ans.pb(k), q.push(k);;
		if ((int) l.size() <= n) ans.pb(l), q.push(l);;
		q.pop();
	}

	sort (all(ans));
	for (string s : ans) cout << s << '\n';
	
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	panlin_bin();

		 
}
