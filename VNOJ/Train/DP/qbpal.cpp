/**
* LANG: C++
* author: atom
* created: 17.07.2022 18:43:18
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
void __print(const pair<T, V> &x) {cerr << "{"; __print(x.first); cerr << ", "; __print(x.second); cerr << "}\n";}
template<typename T>
void __print(const T &x) {
	int f = 0;
	cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";
}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

int n;
string s;

// struct bigNum{
// 	operator + (){
		
// 	}
// }

string add(string a, string b){
	while (a.size() < b.size()) a = '0' + a;
	while (b.size() < a.size()) b = '0' + b;
	string ret = "";
	int carry = 0;
	for (int i = a.size() - 1; i >= 0; i--){
		int sum = (a[i] + b[i] - 2 * '0') + carry;
		ret = (char) (sum % 10 + '0') + ret;
		carry = sum / 10;
	}
	int pos = 0;
	string ans = "";
	while (ret[pos] == '0') pos++;
	for (int i = pos; i < ret.size(); i++)
		ans += ret[i];
	return ret;
}

string sub(string a, string b){
	while (a.size() < b.size()) a = '0' + a;
	while (b.size() < a.size()) b = '0' + b;
	string ret = "";
	int borrow = 0;
	for (int i = a.size() - 1; i >= 0; i--){
		int diff = (a[i] - b[i]) - borrow;
		if (diff < 0){
			diff += 10;
			borrow = 1;
		}
		ret = (char) (diff % 10 + '0') + ret;
	}
	int pos = 0;
	string ans = "";
	while (ret[pos] == '0') pos++;
	for (int i = pos; i < ret.size(); i++)
		ans += ret[i];
	return ret;
}

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> s;
	n = s.size();
	s = '$' + s;
	// cout << sub("9997", "4500");
	string dp[n + 1][n + 1];
	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			if (i == j) dp[i][j] = "1";
			else {
				if (i == j - 1) {
					if (s[i] == s[j]) dp[i][j] = "3";
					else dp[i][j] = "2";
				}
				else {
					if (s[i] == s[j])
						dp[i][j] = add(add(dp[i + 1][j], dp[i][j - 1]), "1");
					else
						dp[i][j] = sub(add(dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1]);
				}
			}
		}
	}
	cout << dp[1][n] << "\n";

}
/* problem link:

*/

