/*	
	TASK: dualpal
  	LANG: C++
 
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define PII pair<int, int>
#define debug(x) printf(#x " is %d \n", x)
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

char convert[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int a, b;

string bString(int n, int k){
	string res = "";
	while (n){
		int r = n % k;
		res = convert[r] + res;
		n /= k;
	}
	return res;
}

bool checkPanlin(int k, int n){
	string s = bString(n, k);
	int l = (int) s.length();
	for (int i = 0; i <= (l - 1) / 2; i++)
		if (s[i] != s[l - 1 - i]) return false;
	return true;
}


bool ok(int n){
	int cnt = 0;
	for (int i = 2; i <= 10; i++){
		if (checkPanlin(i, n)) cnt++;
		if (cnt >= 2) return true;
	}
	return false;
}

int orz(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	cin >> a >> b;
	int cnt = 0;
	for (int i = b + 1; cnt < a; i++){
		if (ok(i)){
			cout << i << "\n";
			cnt++;
		}
	
	}
	return 0;
}
