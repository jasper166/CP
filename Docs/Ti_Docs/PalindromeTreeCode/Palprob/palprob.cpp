#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 42, sigma = 26;
int len[maxn], link[maxn], hlink[maxn];
int to[maxn][sigma], cnt[maxn];
int s[maxn], dp[maxn];
int sz, last, n;
void init()
{
    memset(cnt, 0, sizeof(cnt));
    memset(to, 0, sizeof(to));
    memset(dp, 0, sizeof(dp));
    link[0] = hlink[0] = 1;
    n = last = 0;
    len[1] = -1;
    s[n++] = -1;
    sz = 2;
}
int get_link(int v)
{
    while(s[n - 1] != s[n - len[v] - 2])
        v = link[v];
    return v;
}
void add_letter(char c)
{
    s[n++] = c -= 'a';
    last = get_link(last);
    if(!to[last][c])
    {
        len[sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        hlink[sz] = to[get_link(hlink[last])][c];
        while(len[hlink[sz]] * 2 > len[sz])
            hlink[sz] = link[hlink[sz]];
        dp[sz] = 1 + dp[hlink[sz]] * (len[hlink[sz]] == len[sz] / 2);
        to[last][c] = sz++;
    }
    last = to[last][c];
    cnt[last]++;
}
void solve()
{
    init();
    string s;
    cin >> s;
    for(auto c: s)
        add_letter(c);
    int64_t ans = 0;
    for(int i = sz - 1; i > 1; i--)
    {
        cnt[link[i]] += cnt[i];
        ans += cnt[i] * dp[i];
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    freopen("PALPROB.INP", "r", stdin);
    freopen("PALPROB.OUT", "w", stdout);
    cin >> t;
    while(t--)
        solve();
}
