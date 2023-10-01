/**
* LANG: C++
* author: atom
* created: 15.07.2022 14:33:30
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
constexpr int MAX = 32;
constexpr int INF = INT_MAX;

int n, cur;
char a [MAX][MAX];
bool vis[MAX][MAX];
vector < pair <pii, pii> > PCL;
int color_count[32];
pii t[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool rect(pii s, pii e){
	for (int i = s.F; i <= e.F; i++) for (int j = s.S; j <= e.S; j++)
		vis[i][j] = false;
	for (int i = 0; i < 26; i++) color_count[i] = 0;
	auto bfs = [&] (int x, int y, char color){
		queue <pii> q;
		q.push({x, y});
		vis[x][y] = true;
		while (!q.empty()){
			pii c = q.front(); q.pop();
			for (int i = 0; i <= 3; i++){
				int nx = c.F + t[i].F;
				int ny = c.S + t[i].S;
				if (s.F <= nx && nx <= e.F && s.S <= ny && ny <= e.S){
					if (!vis[nx][ny] && a[nx][ny] == color){
						vis[nx][ny] = true;
						cur++;
						q.push({nx, ny});
					}
				}
			}
		}	
		return;
	};
	int color_num = 0;
	for (int i = s.F; i <= e.F; i++) for (int j = s.S; j <= e.S; j++){
		if (!vis[i][j]){
			int c = a[i][j] - 'A';
			if (color_count[c] == 0) color_num++;
			color_count[c]++;
			bfs(i, j, a[i][j]);
		}
	}
	bool found_one = false, found_other = false;
	if (color_num != 2) return false;
	for (int i = 0; i < 26; i++){
		if (color_count[i] == 1) found_one = true;
		if (color_count[i] >= 2) found_other = true;
	}

	return found_one && found_other;
}

bool isValid(pair <pii, pii> x){
	for (auto i : PCL){
		if (i == x) continue;
		if (x.F.F >= i.F.F && x.F.S >= i.F.S 
			&& x.S.F <= i.S.F && x.S.S <= i.S.S){
			// debug(i);
			return false;
		} 
	}
	return true;
}


int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);

	cin >> n;
	int ret = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	for (int k = n; k >= 1; k--) for (int l = n; l >= 1; l--){
		pii TL = {i, j}, DR = {k, l};
		if (TL.F > DR.F || TL.S > DR.S) continue;
		if (rect(TL, DR)) PCL.push_back({TL, DR});
	} 
	for (auto i : PCL)
		if (isValid(i)) ret++;
	cout << ret << "\n";


}
/* problem link:
	http://www.usaco.org/index.php?page=viewproblem2&cpid=740
*/

