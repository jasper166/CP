/**    
* LANG: C++ 
* author: atom 
* created: 02.06.2022 22:28:52
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


int Rand(int l, int r){
	return rand() % (r + l - 1) + l; 	
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	srand(time(0));

	int a = Rand(1, 10);
	cout << a;		 
}	
