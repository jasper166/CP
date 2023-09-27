/**
 *Author: Le Son - TK2._CHT
 *Spawn: 01/10/2006 - Ha Tinh City - VN
 *School: Ha Tinh High School for the Gifted
**/
#include <bits/stdc++.h>
#define task "testa"
using namespace std;
typedef long long ll;
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
const int maxN = 2e2 + 9;
const int maxK = 1e5 + 5;
int n, m, k;
bitset<maxK> a[maxN];
string s, ss;
vector<int> adj[maxN];
bool DD[maxK];

void progress()
{
    cin >> m >> n >> k;
    cin >> s >> ss;
    int stt = k;
    for (int i = 0; i < stt; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(i);
        adj[m + v].emplace_back(i);
    }

    for (int i = 0; i < m + n; i++)
    {
        int t = s[i] != ss[i];
        for (int eid : adj[i])
        {
            a[i][eid] = 1;
        }
        a[i][k] = t;
    }

    for (int i = 0; i < m + n; i++)
    {
        bool check = false;
        for (int j = 0; j < k; j++)
        {
            if (!a[i][j])
            {
                continue;
            }
            check = true;
            for (int k = 0; k < m + n; k++)
            {
                if (i == k || !a[k][j])
                {
                    continue;
                }
                a[k] ^= a[i];
            }
            break;
        }

        if (!check)
        {
            if (a[i][k] == 1)
            {
                cout << -1 << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < m + n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (a[i][j])
            {
                DD[j] = a[i][k];
                break;
            }
        }
    }

    cout << count(DD, DD + k, 1) << '\n';
    vector<ll> vt;
    for (int i = 0; i < k; i++)
    {
        if (DD[i])
        {
            vt.emplace_back(i + 1);
        }
    }
    for(int x : vt)
    {
        cout << x << " ";
    }
}

// main
int main()
{
    // Written by Shyn_
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll nt = 1;
    // cin >> nt;
    for (; nt--;)
    {
        progress();
    }
}
/** LeSonnn_ **/
/** LCG **/

