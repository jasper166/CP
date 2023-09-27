#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;

int s[maxn], to[maxn][26], len[maxn], link[maxn];
int n, sz, last;

void init()
{
    s[n++] = -1;
    link[0] = 1;
    len[1] = -1;
    sz = 2;
}

int get_link(int v)
{
    while(s[n - len[v] - 2] != s[n - 1]) v = link[v];
    return v;
}

int add_letter(char c)
{
    s[n++] = c -= 'a';
    last = get_link(last);
    if(!to[last][c])
    {
        len[sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        to[last][c] = sz++;
    }
    last = to[last][c];
    return len[last];
}

int main()
{
    freopen("LPS.INP","r",stdin);
    freopen("LPS.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(auto c: s)
        ans = max(ans, add_letter(c));
    cout << ans;
    return 0;
}
