/**    
* LANG: C++ 
* author: atom 
* created: 09.06.2022 06:54:52
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

struct Matrix{	
	ll n, m;
	ll a[12][12];
};

Matrix operator* (Matrix A, Matrix B){
		int a = A.n;
		int b = A.m;
		int c = B.m;
		Matrix ans;
		ans.n = a;
		ans.m = c;
		for (int i = 0; i < a; i++){
			for (int j = 0; j < c; j++) ans.a[i][j] = 0; 
		}
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < c; ++j)
				for (int k = 0; k < b; k++){
					ans.a[i][j] += A.a[i][k]* B.a[k][j];
					ans.a[i][j] %= MOD; 
				}
		return ans;
}

Matrix myPow(Matrix A, ll k){
	Matrix ans = A;
	--k;
	while (k){
		if (k & 1) 
			ans = (ans * A);
		A = (A * A);
		k >>= 1;
	}
	return ans;
}

ll fib(ll n){
	Matrix ans, coe;
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 1; j++) coe.a[i][j] = 1;
	coe.a[1][1] = 0;
	coe.n = 2;
	coe.m = 2;
	ans = myPow(coe, n - 1);
	return ans.a[0][0];
}



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	cout << fib(n) << '\n';
}
