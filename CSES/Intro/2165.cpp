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

vector <pair<int, int> > v;
int step = 0;


void Tower(int n, int x, int y){
	if (n == 1){
		step++;
		v.push_back({x, y});
		return;
	}

	Tower(n - 1, x, 6 - x - y);
	Tower(1, x, y);
	Tower(n - 1, 6 - x - y, y);
	return;
}


int orz(){

	int n;
	scanf("%d", &n);
	Tower(n, 1, 3);
	printf("%d\n", step);
	for (auto i : v) 
		printf("%d %d\n", i.F, i.S);
	return 0;
}
