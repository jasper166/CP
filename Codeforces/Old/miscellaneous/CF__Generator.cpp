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

int a[102][102];

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	srand(time(0));
	int n = rand() % 5 + 1;
	int t = rand() % n + 1;
	int s = rand() % n + 2;
	int u = rand() % n + 2;
	int v = rand() % n + 2;
	cout << n << '\n';
	cout << t << ' ' << s << ' ' << u << ' ' << v << '\n';
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++){
			a[i][j] = rand() % 1 + 0;
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}