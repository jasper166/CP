#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 21;

ll grid[N][N];
map <ll, ll> cnt[N][N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n, m;
    ll k;
    cin >> n >> m >> k;

    
    for (int i = 0; i < n; ++i) 
    	for (int j = 0; j < m; ++j)
    		cin >> grid[i][j];

    int total_moves = n + m - 2;
    // from (0, 0): RD..RD is equivalent to 10..10 -> subset brute-force by splitting path into 2 parts
   	int m1 = total_moves / 2;

   	for (int msk = 0; msk < (1 << m1); ++msk) {
   		int r = 0, c = 0;
   		ll sum = grid[r][c];
   		vector <pair <int, int>> path;
   		for (int i = 0; i < (m1); ++i) {
   			(msk & (1 << i)? r++ : c++);
   			sum ^= grid[r][c];
   		}
   		if (0 <= r && r < n && 0 <= c && c < m) {
   			cnt[r][c][sum]++;
   		}
   	}

   	ll ans = 0;
   	int m2 = total_moves - m1;
   	for (int msk = 0; msk < (1 << m2); ++msk) {
   		int r = n - 1, c = m - 1;
   		ll sum = grid[r][c];
   		for (int i = 0; i < m2; ++i) {
   			(msk & (1 << i)? r-- : c--);
   			sum ^= grid[r][c];
   		}
   		if (0 <= r && r < n && 0 <= c && c < m) {
   			ans += cnt[r][c][k ^ sum ^ grid[r][c]];
   		}
   	}
   	cout << ans << "\n";
}

