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
const int MAX = 102;

ifstream fin ("triangles.in");
ofstream fout ("triangles.out");



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);


	int n;
	fin >> n;
	int x[MAX], y[MAX];
	int ans = 0;
	for (int i = 0; i <= n - 1; i++)
		fin >> x[i] >> y[i];
	for (int i = 0; i <= n - 1; i++)
		for (int j = 0; j <= n - 1; j++)
			for (int k = 0; k <= n - 1; k++)
				if (x[i] == x[j] && y[j] == y[k]){
					int tmp = abs(y[i] - y[j]) * abs(x[j] - x[k]);
					ans = max(ans, tmp);
				}
	fout << ans << "\n";
	return 0;
}
