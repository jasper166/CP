#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m, x, y, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        for (int i = 1; i <= n; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            check[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j);
                }
            }
            cout << s << "\n";
        }
        cout << "\n";
    }
}