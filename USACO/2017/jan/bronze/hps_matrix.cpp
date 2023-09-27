/*	
	TASK: 
  	LANG: C++
  	author: TRAN MINH HIEU
	Handle: at0miccat
  	
 */
#include "bits/stdc++.h"

using namespace std;

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	ifstream fin ("hps.in");
	ofstream fout ("hps.out");

	int n; 
	fin >> n;
	int cowa[n];
	int cowb[n];
	bool c1[3][3] = {{false, true, false}, {false, false, true}, {true, false, false}};
	bool c2[3][3] = {{false, false, true}, {true, false, false}, {false, true, false}};

	for (int i = 0; i <= n - 1; i++){
		fin >> cowa[i] >> cowb[i];
	}
	int ans1 = 0, ans2 = 0, ans = 0;
	for (int i = 0; i <= n - 1; i++){
		if (c1[cowa[i] - 1][cowb[i] - 1]) ans1 ++;
		if (c2[cowa[i] - 1][cowb[i] - 1]) ans2 ++;
		ans = max(ans1, ans2);
	}
	fout << ans << "\n";
	return 0;
}
