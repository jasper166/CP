	/*	
		TASK: 
	  	LANG: C++
	  	author: TRAN MINH HIEU
		Handle: at0miccat
	  	
	 */
	#include "bits/stdc++.h"
	#define F first
	#define S second
	using namespace std;

	ifstream fin ("hps.in");
	ofstream fout ("hps.out");

	int main(){
		ios_base:: sync_with_stdio(false);
		cin.tie(0);
		

		int n; 
		fin >> n;
		vector <pair<int, int>> t(n);
		int hps[102] = {0};
		for (auto &i : t){
			fin >> i.F >> i.S;
			hps[i.F * 10 + i.S]++;
		}

		int ans = 0;

		for (auto i : t){
			if (i.F != i.S){
				int cnt = hps[i.F * 10 + i.S];
				int j = i.S * 10 + (6 - i.F - i.S);
				int k = (j % 10) * 10 + (6 - j % 10 - j / 10);
				cnt += hps[j] + hps[k];
				ans = max(ans, cnt);
			}
		}
		fout << ans << "\n";
		return 0;
	}
