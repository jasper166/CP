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
const int MAX = 2e5 + 5;

int n, k;
int a[MAX];
multiset <int> st;

void run_case() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sumL = 0, sumR = 0;
    for (int i = 0; i < k; i++) 
        st.insert(a[i]);
    auto iter = next(st.begin(), (k - 1) / 2);
    for (auto it = iter; it != st.begin(); it--)
        sumL += *it;
    sumL += *st.begin();
    sumR = accumulate(a, a + k, 0ll) - sumL;
    
    auto ins = [&] (int x) {
        st.insert(x);
        if (x < *iter) {
            if (k & 1){
                sumL += x - *iter;
                sumR += *iter;
                iter--;
            }
            else
                sumL += x;
        }
        else {
            if (k & 1)
                sumR += x;
            else {
                // cout << "!" << *iter << "\n";
                iter++;
                sumR += x - *iter;
                sumL += *iter;
            }
        }
    };

    auto del = [&] (int x) { 
        // cout << *iter << "\n";   
        if (x <= *iter) {
            if (x == *iter && k % 2 == 0) {
                sumR += *iter - x; 
                sumL -= x;
                iter--;
            }
            else {
                if (k & 1) {
                    iter++;
                    sumL += *iter - x;
                    sumR -= *iter;
                }
                else {
                    sumL -= x;
                }
            }
            
        }
        else {
            if (k & 1)
                sumR -= x;
            else {
                sumL -= *iter;
                sumR += *iter - x;
                iter--;
            }
        }
        if (k & 1)
            st.erase(st.lower_bound(x));
        else {
            auto it = st.upper_bound(x);
            --it;
            st.erase(it);
        }
    };

    vector <ll> ans;
    for (int i = k; i <= n; i++) {
        int med = ((k & 1)? *iter : 0);
        ans.push_back(sumR - sumL + med);
        if (i == n)
            break;
        ins(a[i]);
        del(a[i - k]);
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

