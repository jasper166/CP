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


string s;
int n;

int Rand(int l, int r){
	return rand() % (r + l - 1) + l; 
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	srand(time(NULL));
	n = Rand(3, 12);
	cout << n << '\n';
}
