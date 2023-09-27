/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 09:56:51
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
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		int h[3] = {n / 3, n / 3, n / 3};
		if (n % 3 == 2){
			h[0]++;
			h[1] += 2;
			h[2]--;
		}
		else if (n % 3 == 1){
			h[1] += 2;
			h[2]--;
		}
		else {
			h[1]++;
			h[2]--;
		}
		for (int i : h) cout << i << ' ';
		cout << '\n';
	} 
}
