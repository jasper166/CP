/**    
* LANG: C++ 
* author: atom 
* STRESS_TEST
**/
#include "bits/stdc++.h"
using namespace std;

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

	int n = Rand(2, 8), m = Rand(1, 10);
	cout << n << " " << m << '\n';
	for (int i = 1; i <= m; i++){
		int x = Rand(1, n), y = Rand(1, n);
		while (x == y){
			y = Rand(1, n);
		}
		cout << x << " " << y << '\n';
	}
	
	return 0;
}