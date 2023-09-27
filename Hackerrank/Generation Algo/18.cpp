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

int t, n;
ll res[302];

void gen(){
	queue <string> q;
	q.push("8");
	vector <ll> ans;
	ans.pb(8);
	while (!q.empty() && q.front().size() <= 18){
		string k = q.front();
		string j = k + "8";
		string l = k + "0";
		ans.pb(stoll(j));
		ans.pb(stoll(l));
		q.push(j);
		q.push(l);
		q.pop();
	}
	sort(all(ans));
	// for (int i = 0; i <= 10; i++) cout << ans[i] << '\n';
	for (ll i = 1; i <= 300; i++){
		for (ll j : ans){
			if (j % i == 0){
				res[i] = j;
				break;
			}
		}
	}
	// int cnt = 0;
	// for (int i = 1; i <= 300; ++i)
	// 	if (res[i]) cnt++;
	// cout << cnt << '\n';
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	gen();
	cin >> t;
	while (t--){
		int x;
		cin >> x;
		cout << res[x] << '\n';
	}
		 
}
