/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
using namespace std;
using ll = long long;
 
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;
 
int orz(){
 
	ll n;
	scanf("%lld", &n);
	ll ans = n * (n + 1) / 2;
	if (ans & 1) printf("NO\n");
	else {
		set < ll > s;
		ll k = n, sum = 0;
		while (sum != ans / 2){
			if (sum + k <= ans / 2) {
				sum += k;
				s.insert(k);
			}
			k--;
		}
 
		vector < ll > other;
		for (int i = 1; i <= n; i++)
			if (s.find(i) == s.end()) other.push_back(i);
 
		printf("YES\n%d\n", s.size());
		for (auto it : s) printf("%d ", it);
		printf("\n%d\n", other.size());
		for (int i = 0; i <= other.size() - 1; i++) printf("%d ", other[i]);
		printf("\n");
	}
 
	return 0;
}
