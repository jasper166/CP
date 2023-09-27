/**    
* LANG: C++ 
* author: atom 
* created: 24.05.2022 22:33:19
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

string s;
int n;
int cnt[10];

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> s;
	string res;

	int sum = 0;
	n = s.size();
	for (int i = 0; i <= n - 1; i++){
		cnt[s[i] - '0']++;
		sum += (s[i] - '0');
	}
	if (cnt[0] == 0 || sum % 3 != 0) res = "-1";
	else {
		for (int i = 9; i >= 0; i--){
			while (cnt[i]){
				res += (char) (i + '0');
				cnt[i]--;
			}
		}
	}
	cout << res << '\n';
}
