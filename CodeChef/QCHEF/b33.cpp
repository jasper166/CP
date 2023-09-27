#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;

const int MOD = 1e9 + 7;
const int LIM = 4444444444;
const int MAX = 1e3 + 2;
// B33
int f[MAX][1 << 12];
int n, m;
vector <int> adj[1 << 12];

void get(int i, int cur_msk, int nxt_msk) {
    if (i >= n) {
        adj[cur_msk].push_back(nxt_msk);
        return;
    }
    // neu nhu o hien tai da duoc lap
    if (cur_msk & (1 << i)) {
        get(i + 1, cur_msk, nxt_msk);
        return;
    }
    // dat vien gach 1 x 2 (chieu ngang)
    get(i + 1, cur_msk, nxt_msk | (1 << i));
    // dat vien gach 2 x 1 (chieu doc)
    if (i + 1 < n && (cur_msk & (1 << (i + 1))) == 0)
        get(i + 2, cur_msk, nxt_msk);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;

    // Tim tat ca trang thai tiep theo tu trang thai hien tai
    for (int msk = 0; msk < (1 << n); msk++) {
        get(0, msk, 0);
    }
    // for (auto x : adj[0]) cout << x << "\n";
    f[0][0] = 1; 
    // 0 la tt duoc dien full 
    // tinh tu cot 1 -> m - 1
    for (int i = 1; i <= m; i++) {
        for (int msk = 0; msk < (1 << n); msk++) {
            for (int nxt : adj[msk])
                f[i][nxt] = (f[i][nxt] + f[i - 1][msk]) % MOD;
        }
    }
    cout << f[m][0] << "\n";
}