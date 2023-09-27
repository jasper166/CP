/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 14:56:55
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

bool ok(string s){
    if (s[0] != '8' || s[n - 1] != '6') return false;
    if (s.find("88") != string:: npos) return false;
    if (s.find("6666") != string:: npos) return false;
    return true;
} 

void logfat_gen(){

	queue <string> q;
	q.push("86");
	while(!q.empty()){
		string k = q.front();
		string l = k + "6";
		string j = k + "8";
		if ((int) l.size() == n && ok(l)) ans.pb(l);
		if ((int) j.size() == n && ok(j)) ans.pb(j);
		if ((int) j.size() > n) break;
		q.push(l);
		q.push(j);
		q.pop();
	}
	for (string s : ans) cout << s << '\n';

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	logfat_gen();	 
}
