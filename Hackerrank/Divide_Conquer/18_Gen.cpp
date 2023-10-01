/**    
* LANG: C++ 
* author: atom 
* STRESS_TEST
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
	return uniform_int_distribution<long long>(l, h)(rng);
}

string Rand_string(long long n){
	string s = "";
	for (int i = 0; i <= n - 1; i++){
		s += (char) (Rand(0, 25) + 'a');
	}
	return s;
}

ll len(ll n){
	ll i = log2(n);
	return pow(2, i + 1) - 1;
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n = Rand(5, 100000);
	int l = Rand(1, len(n));
	int r = Rand(l, len(n));
	cout << n << ' ' << l << ' ' << r << '\n';
	return 0;
}