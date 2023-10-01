/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 19:41:06
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...) 42
#endif

int n;
vector <int> a;

void next_permu(){
	// find i index that ai < a(i + 1)
	int i = n - 2; 
	while (i >= 0 && a[i] > a[i + 1]) i--;
	// find the first number that larger than ai from n to i : j
	if (i == -1)
		for (int k = 1; k <= n; k++) cout << k << ' ';
	else {
			int j = n - 1;
		while (j >= i && a[j] < a[i]) j--;
	// swap ai, aj 
		swap(a[i], a[j]);
		sort(a.begin() + i + 1, a.end());
		for (int i : a) cout << i << ' ';
	}

	// sort i + 1 -> n;
	cout << '\n';
}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n; 
	a.resize(n);
	for (int &i : a) cin >> i;
	vector <int> b = a;
	next_permu();
	
	// next_permutation(all(b));
	// for (int i : b) cout << i << ' ';


}
