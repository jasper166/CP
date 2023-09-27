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

ifstream fin ("blocks.in");
ofstream fout ("blocks.out");

int cnt[26], cnt_a[26], cnt_b[26];

void marking(string a, string b){
	memset(cnt_a, 0, sizeof(cnt_a));
	memset(cnt_b, 0, sizeof(cnt_b));
	int l1 = a.length();
	int l2 = b.length();
	for (int i = 0; i <= l1 - 1; i++){
		cnt_a[a[i] - 'a']++;
	}
	for (int i = 0; i <= l2 - 1; i++){
		cnt_b[b[i] - 'a']++;
	}
	for (int i = 0; i <= 25; i++){
		cnt[i] += max(cnt_a[i], cnt_b[i]);
	}
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	int n;
	fin >> n;
	vector <pair<string, string>> b(n);
	for (auto &i : b){
		fin >> i.F >> i.S;
    marking(i.F, i.S);
	}	
	for (int i : cnt)
		fout << i << "\n";
	return 0;
}
