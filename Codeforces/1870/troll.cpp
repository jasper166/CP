#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define           f    first
#define           s    second
#define           pb    push_back
#define           ep    emplace
#define           eb    emplace_back
#define           lb    lower_bound
#define           ub    upper_bound
#define       all(x)    x.begin(), x.end()
#define      rall(x)    x.rbegin(), x.rend()
#define   uniquev(v)    sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define     mem(f,x)    memset(f , x , sizeof(f))
#define        sz(x)    (int)(x).size()
#define  __lcm(a, b)    (1ll * ((a) / __gcd((a), (b))) * (b))
#define          mxx    *max_element
#define          mnn    *min_element
#define    cntbit(x)    __builtin_popcountll(x)
#define       len(x)    (int)(x.length())

const int N = 1e5 + 100;
ll c[N];

void xuat_tinh(vector <ll> a) {
    for (auto x : a)
        cout << x << " ";

    cout << '\n';
}

ll solve() {
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector <int> st, val;
    for (int i = 0; i < n; i++) {
        while (sz(st) && c[i] <= c[st.back()]) {
            val.pop_back();
        }

        st.push_back(i);
        val.pb(c[i]);
    }


    ll k;
    cin >> k;

    vector <ll> a(n, 0), b(n, 0), f(n, 0);
    for (int i = 0; i <= st[0]; i++) {
        a[i] = k / c[st[0]];
    }

    if (a[0] == 0) {
        xuat_tinh(a);
        return 0;
    }

    ll cur = (k % c[st[0]]) + c[st[0]];
    for (int i = 0; i <= st[0]; i++) {
        b[i] = k / c[st[0]] - 1; 
    }

    for (int i = sz(st) - 1; i >= 0; i--) {
        if (c[st[i]] <= cur) {
            for (int j = 0; j <= st[i]; j++)
                b[j]++;

            break;
        }
    }

    if (c[st[0]] * 2 <= k) {
        ll cur = (k % c[st[0]]) + c[st[0]] * (ll)2;
        for (int i = 0; i <= st[0]; i++) {
            f[i] = k / c[st[0]] - 2;
        }

        ll x = -1, y = -1;
        for (int i = 1; i < sz(st); i++) {
            ll re = cur - c[st[i]];
            if (re >= c[st[i]]) {
                ll p = upper_bound(all(val), re) - val.begin() - 1;
                x = i, y = p;
            }
        }

        for (int i = 0; i <= y; i++) {
            f[i] += bool(i <= x) + bool(i <= y);
        }
    }

    xuat_tinh(max({a, b, f}));
    return 0;
}

void solve(){
	ll n = rd; vector<ll> C = rdv(n), K(n, 0); ll k = rd, pos = 0, mn = 1e18;
	map<ll, ll> m; vector<pll> F; m[-1] = -1;
	for (int i = 0; i < n; i++){
		m[C[i]] = i; mn = min(mn, C[i]);
	}
	for (auto &x : m){
		if (x.s < pos){
			continue;
		}
		if (x.f >= mn * 2){
			break;
		}
		if (dp.empty()){
			ll nxt = k / x.f;
			dp.eb(x.f, nxt); k -= nxt * x.f;
			k = min(k, x.f - 1);
		} else {
			ll have = x.f - dp.back().f;
			ll nxt = k / have;
			nxt = min(dp.back().s, nxt); k -= nxt * have;
			if (nxt == dp.back().s){
				dp.pop_back();
			} else {
				dp.back().s -= nxt;
			}
			dp.eb(x.f, nxt);
		}
		pos = max(pos, x.s);
	}
	dp.insert(dp.begin(), {-1, -1});
	for (int i = dp.size() - 1, sum = 0; i > 0; i--){
		sum += F[i].s;
		for (int j = m[F[i].f]; j > m[F[i - 1].f]; j--){
			K[j] += sum;
		}
	}
	cout << K << '\n';

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        //cout << solve() << '\n';
    }

    return 0;
}