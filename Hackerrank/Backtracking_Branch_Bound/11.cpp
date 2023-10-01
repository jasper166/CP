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
int a[22];
vector <string> ans;
vector <int> num;
void myPrint(){
	for (string s : ans){
		// for (int j = 0; j < (int) s.size(); j++) cout << s[j] << ' ';
		// cout << '\n';
		cout << s << '\n';
	}
}

void bt(int i){
	if (num.size() >= 2){
		string tmp = "";
		for (int j : num) tmp += (to_string(j) + " ");
		ans.pb(tmp);
	}
	for (int j = i; j <= n; j++){
		if (num.empty() || a[j] > num[num.size() - 1]){
			num.pb(a[j]);
			bt(j + 1);
			num.pop_back();
		}
	}

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	bt(1);
	sort(all(ans));
	myPrint();
}
