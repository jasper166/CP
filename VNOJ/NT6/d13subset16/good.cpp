/**
 *Author: Le Son - TK2._CHT
 *Spawn: 01/10/2006 - Ha Tinh City - VN
 *School: Ha Tinh High School for the Gifted
 **/
#include <bits/stdc++.h>
#define task "testa"
using namespace std;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> ii;
#pragma GCC optimize("Ofast")

// struct-----pair
#define mp make_pair
#define fi first
#define se second
#define all(a_) a_.begin(), a_.end()

// vector
#define pb push_back
#define eb emplace_back
#define sz(a) (int)(a.size())

// max - min
template <class shark>
inline bool minimize(shark &a, const shark &b) { return (a > b ? (a = b), 1 : 0); }
template <class shark>
inline bool maximize(shark &a, const shark &b) { return (a < b ? (a = b), 1 : 0); }

// declare
const int maxN = (1 << 20) + 10;
const int maxM = 1e3 + 11;
const int mod = 1e9 + 7;
const ll oo = 1e18;
const ll MOD = 998244353;
const ld PI = 4 * atan(1);
const double EPS = 1e-6;

ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
ll dxe[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll dye[] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;
ll l, r, w[maxN];
ii a[maxN];

bool check_sub5()
{
    for (int i = 1; i <= n; i++)
    {
        if (w[i] != i)
            return false;
    }
    return true;
}

int cnt_mask1, cnt_mask2;
pair<ll, int> mask1[maxN], mask2[maxN];

void sub1()
{
    int n1 = n / 2;
    int n2 = n - n1;
    mask1[cnt_mask1++] = mask2[cnt_mask2++] = pair(0, 0);

    for (int i = 1; i <= n1; i++)
    {
        for (int j = cnt_mask1 - 1; j >= 0; j--)
        {
            ll sum = mask1[j].fi + w[i];
            int mask = mask1[j].se | (1 << (i - 1));
            mask1[cnt_mask1++] = pair(sum, mask);
        }
    }

    for (int i = 1; i <= n2; i++)
    {
        for (int j = cnt_mask2 - 1; j >= 0; j--)
        {
            ll sum = mask2[j].fi + w[i + n1];
            int mask = mask2[j].se | (1 << (i - 1));
            mask2[cnt_mask2++] = pair(sum, mask);
        }
    }

    sort(mask2, mask2 + cnt_mask2);
    int ans_mask1 = 0, ans_mask2 = 0;

    for (int i = 0; i < cnt_mask1; i++)
    {
        ll new_l = l - mask1[i].fi;
        ll new_r = r - mask1[i].fi;
        int p = lower_bound(mask2, mask2 + cnt_mask2, pair(new_l, -1)) - mask2;
        // r - x>= y >= l - x;
        if (p != cnt_mask2 && mask2[p].fi <= new_r)
        {
            ans_mask1 = mask1[i].se;
            ans_mask2 = mask2[p].se;
            break;
        }
    }

    cout << (__builtin_popcount(ans_mask1) + __builtin_popcount(ans_mask2)) << "\n";

    for (int i = 0; i < n1; i++)
    {
        if ((ans_mask1 >> i) & 1)
        {
            cout << i + 1 << " ";
        }
    }

    for (int i = 0; i < n2; i++)
    {
        if ((ans_mask2 >> i) & 1)
        {
            cout << n1 + i + 1 << " ";
        }
    }
}

bool dp[88][150000];

void sub3()
{
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 150000; j++)
        {
            if (j >= w[i])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<int> ans;

    for (int j = l; j <= r; j++)
    {
        if (dp[n][j])
        {
            while (n > 0)
            {
                if (j >= w[n])
                {
                    if (dp[n - 1][j - w[n]])
                    {
                        ans.emplace_back(n);
                        j -= w[n];
                    }
                }
                n--;
            }
        }
    }

    cout << sz(ans) << "\n";

    for (int i = sz(ans) - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}

void sub4()
{
    map<int, int> cnt;

    for (int i = 1; i <= n; i++)
    {
        cnt[w[i]]++;
    }

    for (auto [x, y] : cnt)
    {
        int bot = 1, top = y, ans = 0;
        while (bot <= top)
        {
            int mid = (bot + top) >> 1;
            if (1ll * x * mid >= l)
            {
                ans = mid;
                top = mid - 1;
            }
            else
            {
                bot = mid + 1;
            }
        }
        if (ans == 0)
            continue;
        cout << ans << "\n";
        for (int i = 1; ans > 0; i++)
        {
            if (w[i] == x)
            {
                cout << i << " ";
                ans--;
            }
        }
        break;
    }
}

void sub5()
{
    ll sum = 0;
    vector<int> ans;
    for (int i = n; i >= 1; i--)
    {
        if (sum + w[i] <= l)
        {
            ans.emplace_back(i);
            sum += w[i];
        }
        else
        {
            if (sum + w[i] > r)
                continue;
            ans.emplace_back(i);
            sum += w[i];
        }
    }
    // reverse(all(ans));
    cout << sz(ans) << "\n";
    for (int &v : ans)
    {
        cout << v << " ";
    }
}

void sub6()
{
    ll gg = LLONG_MAX;
    ll ga = LONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        gg = min(gg, (ll)a[i].fi);
        ga = max(ga, (ll)a[i].fi);
    }
    assert(ga - gg <= r - l);
    sort(a + 1, a + n + 1);
    ll ss = 0;
    ll id = 1;
    vector<ll> ans;
    for (int i = 1; i <= n; i++)
    {
        ss += a[i].fi;
        while (id <= i && ss > r)
        {
            ss -= a[id].fi;
            id++;
        }
        if (ss >= l && id <= i)
        {
            for (int j = id; j <= i; j++)
            {
                ans.pb(a[j].se);
            }
            break;
        }
    }
    if (ans.empty())
    {
        cout << -1;
        return;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto v : ans)
    {
        cout << v << " ";
    }
}
// main
int main()
{
    // Written by Shyn_
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        a[i].fi = w[i];
        a[i].se = i;
    }

    if (n <= 40)
    {
        sub1();
    }
    else if (n <= 80)
    {
        sub3();
    }
    else if (check_sub5())
    {
        sub5();
    }
    else if(!check_sub5())
    {
        sub6();
    }
    else sub4();
}
/** LeSonnn_ **/
/** LCG **/

