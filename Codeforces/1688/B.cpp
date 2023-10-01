/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 20:00:36
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

int n, t;


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		for (int &i : a) cin >> i;

		auto cnt = [&](int x){
			int ans = 0;
			while (x){
				ans++;
				x /= 2;
				if (x & 1) break;
			}
			return x;
		};

		bool odd = false;
		int  sum = MOD, d = 0;
		for (int i : a){
			if (i & 1) odd = true;
			else {
				sum = min(sum, cnt(i));
				d++;
			}
		}
		cout << (odd? d : sum + d - 1) << '\n';
	}
		 
}
