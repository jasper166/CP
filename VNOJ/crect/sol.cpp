#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 4e2 + 5;

char a[MAX][MAX];
int n, m;
int lt[MAX], g[MAX];

ll f[MAX];
ll cnt1[10];
ll cnt2[10][10];
ll cnt3[10][10][10]; 
// cntx : chua duy nhat x ki tu
// mo rong bai toan: dem so hcn thoa man dk bat ki??

ll cal(vector <char> S) {
    // dem so hcn chua it nhat 1 ki tu thuoc S;
    ll ans = 0;
    // debug(S);
    for (int j = 1; j <= m; j++)
        f[j] = g[j] = lt[j] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool safe = 0;
            for (char c : S)
                if (c == a[i][j])
                    safe = 1;
            safe? g[j]++ : g[j] = 0;
        }

        stack <int> st;
        for (int j = 1; j <= m; j++) {
            while (!st.empty() && g[st.top()] >= g[j])
                st.pop();
            lt[j] = st.empty()? 1 : st.top() + 1;
            st.push(j);
        }

        for (int j = 1; j <= m; j++) {
            f[j] = 1ll * g[j] * (j - lt[j] + 1) + f[lt[j] - 1];
            ans += f[j];
        }
    }

    return ans;
}

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j - 1];
    }

    for (char X = 'A'; X <= 'E'; X++) {
        int x = X - 'A';
        vector <char> S;
        S.push_back(X);
        cnt1[x] = cal(S);
    }

    for (char X = 'A'; X <= 'E'; X++) {
        for (char Y = X + 1; Y <= 'E'; Y++) {
            vector <char> S;
            S.push_back(X); 
            S.push_back(Y);
            int x = X - 'A';
            int y = Y - 'A';
            cnt2[x][y] = cal(S) - cnt1[x] - cnt1[y];
        }
    }

    ll ans = 0;
    for (char X = 'A'; X <= 'E'; X++) {
        for (char Y = X + 1; Y <= 'E'; Y++) {
            for (char Z = Y + 1; Z <= 'E'; Z++) {
                vector <char> S;
                S.push_back(X);
                S.push_back(Y);
                S.push_back(Z);
                int x = X - 'A';
                int y = Y - 'A';
                int z = Z - 'A';
                cnt3[x][y][z] = cal(S) - cnt2[x][y] - cnt2[y][z] - cnt2[x][z] - cnt1[x] - cnt1[y] - cnt1[z];
                ans += cnt3[x][y][z];
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

