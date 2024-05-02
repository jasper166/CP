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

ifstream fin ("measurement.in");
ofstream fout ("measurement.out");
 

map <string, int> cow;

struct cows{
	int day;
	int change;
	string name;
};

bool cmp(cows a, cows b){
	return (a.day < b.day);
}

void ini(){
	cow.insert({"Mildred", 7});
	cow.insert({"Elsie", 7});
	cow.insert({"Bessie", 7});
}

void print(){
	for (auto i : cow)
		cout << i.F << " " << i.S << "\n";
}

pair <string, int> Winner = {"BessieElsieMildred", 7};

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	ini();
	int n;
	fin >> n;
	cows c[n];
	for (auto &i : c) fin >> i.day >> i.name >> i.change;

	sort(c, c + n, cmp);
	int ans = 0;

	for (auto i : c){

		cow[i.name] += i.change; 
		pair <string, int> preWinner = Winner;
		Winner.F = "";
		auto it = *max_element (
			cow.begin(), cow.end(), 
			[](const auto &x, const auto &y) {
                return x.second < y.second; 
            	}
            );
		Winner.S = it.S;

		for (auto it2 = cow.begin(); it2 != cow.end(); it2++){
			if (it2->S == Winner.S)
				Winner.F += it2->F;
		}

		if (preWinner.F != Winner.F) 
			ans++;
	}
	
	fout << ans << "\n";
	return 0;
}
