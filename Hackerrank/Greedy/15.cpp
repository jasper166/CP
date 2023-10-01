/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 01:21:11
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

int s, d;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> d;
	string ans = "";
	stack <int> stk;
	int k = d;
	while (s){
		if (s > 9) stk.push(9), s -= 9;
		else {
			stk.push(s);
			s = 0;
		}
		d--;
	}

	if (d < 0) ans = "-1";
	else {
		if (d > 0){
			ans += '1';
			k--;
			while (k > stk.size()) ans += '0', k--;			
			ans += (char)(stk.top() - 1 + '0');
			stk.pop();
		}
		while (!stk.empty()){
				ans += (char) (stk.top() + '0');
				stk.pop();
		}
	}
	cout << ans << '\n';
		 
}
