/**    
* LANG: C++ 
* author: atom 
* created: 22.05.2022 21:30:33
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
string s;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
 	
 	cin >> t;
 	while (t--){
 		cin >> n >> s;
 		int cnt = 0;
 		char in = s[n / 2];
 		for (int i = n / 2 - 1; i >= 0; i--){
 			if (s[i] != in) break;
 			else cnt++;
 		}
 		cnt *= 2;
 		if (n & 1) cnt++;
 		cout << cnt << '\n';
 	}
		 
}
