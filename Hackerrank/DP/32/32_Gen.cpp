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

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	ll a = Rand(100, 1000);
	ll b = Rand(a, 1000);
	cout << a << ' ' << b << '\n';
	return 0;
}