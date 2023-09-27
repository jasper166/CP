/*	
	TASK: 
  	LANG: C++
  	author: TRAN MINH HIEU
	Handle: at0miccat
  	
 */
#include "bits/stdc++.h"

using namespace std;

struct speed{
	int l, s;
};

void cal(int *road, speed *r){
	int i = 0;
	int pre = r[i].l;
	for (int j = 1; j <= 100;){
		while (j <= pre && j <= 100){
			road[j++] = r[i].s;
		}
		i++;
		pre += r[i].l; 
	}
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	ifstream fin ("speeding.in");
	ofstream fout ("speeding.out");
	int n, m;
	fin >> n >> m;
	speed r[n], b[m];
	int ans = 0;

	for (int i = 0; i <= n - 1; i++) fin >> r[i].l >> r[i].s;
	for (int i = 0; i <= m - 1; i++) fin >> b[i].l >> b[i].s;

	int road1[102], road2[102];
	cal(road1, r);
	cal(road2, b);
	
	for (int k = 1; k <= 100; k++) 
		ans = max(ans, (road2[k] - road1[k]));
	fout << ans << "\n";
	return 0;
}
