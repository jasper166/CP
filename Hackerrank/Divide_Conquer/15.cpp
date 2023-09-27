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
	ll n, k;
	ll a[12][12];
};

Matrix operator* (Matrix A, Matrix B){
		int n = A.n;
		Matrix ans;
		ans.n = n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) ans.a[i][j] = 0; 
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; k++){
					ans.a[i][k] += A.a[i][j]* B.a[j][k];
					ans.a[i][k] %= MOD; 
				}
		return ans;
}

Matrix myPow(Matrix A, ll k, ll n){
	Matrix ans = A;
	ans.n = n;
	--k;
	while (k){
		if (k & 1) 
			ans = (ans * A);
		A = (A * A);
		k >>= 1;
	}
	return ans;
}



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, k;
	Matrix M;
	cin >> n >> k;
	M.n = n;
	M.k = k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> M.a[i][j];
	// Matrix ans = M * M;
	// ans = ans * M;
	Matrix ans =  myPow(M, k, n);
	ll res = 0;
	for (int i = 0; i < n; i++){
		res += ans.a[i][n - 1]; 
		res %= MOD; 
	}
	cout << res << '\n';
}
