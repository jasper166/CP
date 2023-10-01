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

	cin >> n;
	int a[n];
	for (int &i : a) cin >> i;
	ll kadane = -1e9, cur = 0;
	for (int i : a){
		if (cur < 0){
			cur = 0;
		}
		cur += i;
		kadane = max(kadane, cur);

	}
	cout << kadane << '\n';
}
