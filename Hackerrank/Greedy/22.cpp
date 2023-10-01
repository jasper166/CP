/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 07:02:17
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

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector <int> div;
	for (int i = 2; i <= sqrt(n); ++i){
		if (n % i == 0){
			div.pb(i);
			n /= i;
		}
	}
	if (n != 1) div.pb(n);

	int a, b, c;
	a = b = c = 1;

	for (int i = 0; i <= (int) div.size() - 1; i++){
		if (a == 1) a *= div[i]
		else if (b == 1 || a == b) b *= div[i];
		else c *= div[i];
	}
	bool flag = true;
	if (a == 1 || b == 1 || c == 1 || a == b || a == c || b == c) flag = false;
	cout << (flag? "YES" : "NO") << '\n';

}
