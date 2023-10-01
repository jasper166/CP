/**    
* LANG: C++ 
* author: atom 
* created: 05.07.2022 12:37:54
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
void __print(const T &x) {int f = 0; 
	cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
 
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif
// #define int long long 

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;
constexpr ll INF = 1e18;

ll a, b, c, d, diff;

ll maxDiff(ll *ar){
    diff = -INF;
    FOR(i, 0, 3)
    	FOR(j, 0, 3)
            if(i != j) diff = max(diff, ar[i] - ar[j]);

    return diff;
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	int n1;
	cin >> n1;
	ll caps[n1];
	for (ll &i : caps) cin >> i;
	sort(caps, caps + n1);

	int n2;
	cin >> n2;
	ll shirts[n2];
	for (ll &i : shirts) cin >> i;
	sort(shirts, shirts + n2);

	int n3;
	cin >> n3;
	ll pants[n3];
	for (ll &i : pants) cin >> i;
	sort(pants, pants + n3);

	int n4;
	cin >> n4;
	ll shoes[n4];
	for (ll &i : shoes) cin >> i;
	sort(shoes, shoes + n4);
	
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
	ll maxi = INF;
	a = b = c = d = -1;
	while (i1 < n1 && i2 < n2 && i3 < n3 && i4 < n4){
		ll ar[] = {caps[i1], shirts[i2], pants[i3], shoes[i4]};
		diff = maxDiff(ar); 
		if (diff < maxi){
			maxi = diff;
			a = i1, b = i2, c = i3, d = i4;
			// debug(c, s, p ,sh);
		}	
		if (caps[i1] <= shirts[i2] && caps[i1] <= pants[i3] && caps[i1] <= shoes[i4])
			i1++;
		else if (shirts[i2] <= caps[i1] && shirts[i2] <= pants[i3] && shirts[i2] <= shoes[i4])
			i2++;
		else if (pants[i3] <= caps[i1] && pants[i3] <= shirts[i2] && pants[i3] <= shoes[i4])
			i3++;
		else if (shoes[i4] <= caps[i1] && shoes[i4] <= shirts[i2] && shoes[i4] <= caps[i1])
			i4++;
	}
	// debug(i1, i2, i3, i4);

	diff = -INF;
	// if (i2 >= n2 || i1 >= n1) diff = INF;
	ckmax(diff, abs(shirts[i2] - caps[i1]));
	// debug(diff);
	// if (i3 >= n3 || i2 >= n2) diff = INF;
	ckmax(diff, abs(pants[i3] - shirts[i2]));
	// debug(diff);
	// if (i4 >= n4 || i3 >= n3) diff = INF;
	ckmax(diff,  abs(shoes[i4] - pants[i3]));
	// debug(diff);

	if (diff < maxi) a = i1, b = i2, c = i3, d = i4;

	cout << caps[a] << " " << shirts[b] << " " << pants[c] << " " << shoes[d] << '\n';


	// debug(a);

	#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif		 
}
/* problem link: 
	https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D
    similar on IB: https://www.interviewbit.com/problems/array-3-pointers/
	die from debugging ;-;
*/

