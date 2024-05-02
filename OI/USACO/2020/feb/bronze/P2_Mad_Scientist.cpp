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
	ifstream fin ("breedflip.in");
	ofstream fout ("breedflip.out");

	int n;
	string a, b;
	fin >> n >> a >> b;
	bool flag[n + 1];
	int ans = 0;
	for (int i = 0; i <= n - 1; i++)
		flag[i] = (a[i] == b[i]);
	for (int i = 0; i <= n - 2; i++){
		if (!flag[i]){
			ans++;
			while (!flag[i] && i <= n -1) i++;
		}
	}
	fout << ans << "\n";

	return 0;
}
