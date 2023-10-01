/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 20:20:41
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

bool ok(vector <int> &a){

	for (int i = 0; i <= n - 2; i += 1){
		if (abs(a[i] - a[i + 1]) == 1) return false;
	}
	return true;
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	vector <int> a(n);
	int i = 1;
	for (int &j : a) j = i++;

	do {
		if (ok(a)){
			for (int j : a) cout << j;
			cout << '\n';
		}
	} while (next_permutation(all(a)));

		 
}
