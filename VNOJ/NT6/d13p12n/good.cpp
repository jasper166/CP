#include <bits/stdc++.h>
#define task "p12n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<string, int> ii;

ll n, m, k;
ll a[10], stt[8][8][8][8][8][8][8], cnt, l[6000][3][400];
double t[10];
double dd[10][10][10][10][5][110];
map<ii, double> M;

void sub1()
{
    if (a[1] == 3 && a[2] == 2 && a[3] == 1)
        cout << "5.00000";
    if (a[1] == 1 && a[2] == 2 && a[3] == 3)
        cout << "0.00000";
    if (a[1] == 2 && a[2] == 3 && a[3] == 1)
        cout << "4.00000";
    if (a[1] == 2 && a[2] == 1 && a[3] == 3)
        cout << "1.00000";
    if (a[1] == 1 && a[2] == 3 && a[3] == 2)
        cout << "1.00000";
    if (a[1] == 3 && a[2] == 1 && a[3] == 2)
        cout << "4.00000";
}

double sub2(ll h[], int p, int ds)
{
    if (dd[h[1]][h[2]][h[3]][h[4]][p][ds] != 0)
    {
        return dd[h[1]][h[2]][h[3]][h[4]][p][ds];
    }
    bool ok = true;
    for (int i = 1; i <= n - 1; i++)
    {
        if (h[i] > h[i + 1])
        {
            ok = false;
            break;
        }
    }
    if (ok || ds == 100)
    {
        dd[h[1]][h[2]][h[3]][h[4]][p][ds] = 0;
        return 0;
    }
    double res = 0, gmin = 1e9 + 7;
    for (int i = 1; i <= n - 1; i++)
    {
        swap(h[i], h[i + 1]);
        t[i] = sub2(h, 1 - p, ds + 1) + 1;
        res += t[i];
        gmin = min(gmin, t[i]);
        swap(h[i], h[i + 1]);
    }
    if (!p)
    {
        dd[h[1]][h[2]][h[3]][h[4]][p][ds] = gmin;
        return gmin;
    }
    else
    {
        dd[h[1]][h[2]][h[3]][h[4]][p][ds] = (double)res / (n - 1);
        return (double)res / (n - 1);
    }
}

double solve(ll h[], int p, int ds)
{
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (h[i] > h[i + 1])
        {
            flag = false;
            break;
        }
    }
    if (flag || ds == 400)
    {
        return 0;
    }
    if (!stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]])
    {
        stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]] = ++cnt;
    }
    if (l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds] != -1)
    {
        return l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds];
    }
    double res = 0, gmin = 1e9 + 7;
    for (int i = 1; i <= n - 1; i++)
    {
        swap(h[i], h[i + 1]);
        t[i] = solve(h, 1 - p, ds + 1) + 1;
        res += t[i];
        gmin = min(gmin, t[i]);
        swap(h[i], h[i + 1]);
    }
    if (p == 0)
    {
        l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds] = gmin;
        return gmin;
    }
    else
    {
        l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds] = (double)res / (n - 1);
        return (double)res / (n - 1);
    }
}

void sol()
{
    cnt = 1;
    stt[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]] = 1;
    memset(l, -1, sizeof(l));
    cout << fixed << setprecision(5) << solve(a, 0LL, 1LL);
}

void solve_sub2()
{
    cout << fixed << setprecision(5) << sub2(a, 0, 1);
}

void progress()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 3)
    {
        sub1();
    }
    else if (n == 4)
    {
        solve_sub2();
    }
    else sol();
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
    ll nt = 1;
    // cin >> nt;
    for (; nt--;)
    {
        progress();
    }
}

