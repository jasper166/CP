test.cpp
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
//@etohari
using namespace std;
using namespace __gnu_pbds;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define my_wife "Dao Bich Ngoc"
#define bit(mask,i) ((mask >> i)&1)
#define cntbit(mask) __builtin_popcountll(mask)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define sz(s) (int)s.size()
#define __lcm(a,b) ((int64_t)a / __gcd(a, b) * b)
#define rand(l, r) uniform_int_distribution < int64_t > (l, r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ordered_set tree < pair < int, int >, null_type, less < pair < int, int > >, rb_tree_tag,tree_order_statistics_node_update >

const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int DX[] = { };
const int DY[] = { };

void etohari() {
	int m, n, s;
	cin >> m >> n >> s;
	
	vector < vector < int > > a(m, vector < int > (n));

	for (auto&vt : a){
		for (auto&v : vt){
			cin >> v;
		}
	}

	vector < int > id_a(m);
	vector < int > id_b(n);
	iota(all(id_a), 0);
	iota(all(id_b), 0);

	for (int i = 0; i < s; i ++){
		int k;
		cin >> k;
		k--;
		stable_sort(all(id_b), [&](int u, int v){
			return a[u][k] < a[v][k];
		});
	}

	if (id_a == id_b){
		cout << 0;
		return;
	}

	vector < int > id(n);
	vector < int > res(n + 10);
	iota(all(id), 0);

	do{            
		iota(all(id_a), 0);
		for (int i = 0; i < n; i ++){
			int k = id[i];
			stable_sort(all(id_a), [&](int u, int v){
				return a[u][k] < a[v][k];
			});
			if (id_a == id_b){
				vector < int > t(id.begin(), id.begin() + i + 1);
				if (sz(t) < sz(res) || (sz(res) == sz(t) && t < res)){
					res = t;
				}
				break;
			}
		}        
	}while(next_permutation(all(id)));

	cout << sz(res) << "\n";
	
	for (auto&v : res)cout << v + 1  << " ";
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int test = 1;
        // cin >> test;

	for (int i_test = 1; i_test <= test; i_test++) {
		etohari();
	}

	return (0 ^ 0);
}
/*
        Hi I'm Powder
        fb.com/hai290605
        ICPC WORLD FINALS GO GO
*/
