#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
 
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif
 
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif
 
    int T; 
    cin >> T;
    while (T--) {
    	int n, m;
    	cin >> n >> m;
 
    	if (n <= 4 && m <= 4) {
    		int sz = (n * m);
	    	int opt = -1;
	    	int ans = 0;
	    	for (int msk = 0; msk < (1 << sz); ++msk) {
	    		vector <vector <int>> a(n, vector <int> (m));
	    		for (int i = 0; i < sz; ++i) {
	    			if (msk & (1 << i)) {
	    				int r = i / m;
	    				int c = i % m;
	    				a[r][c] = 1;
	    			}
	    		}
 
	    		int A = 0, B = 0;
		    	for (int i = 0; i < n; ++i) {
		    		int r = 0, b = 0;
		    		for (int j = 0; j < m; ++j) {
		    			if (a[i][j]) ++r;
		    			else ++b;
		    		}
		    		if (r > b) ++A;
		    	}
 
		    	for (int j = 0; j < m; ++j) {
		    		int r = 0, b = 0;
		    		for (int i = 0; i < n; ++i) {
		    			if (a[i][j]) ++r;
		    			else ++b;
		    		}
		    		if (b > r) ++B;
		    	}
 
		    	// debug(A, B, msk);
		    	if (A + B > ans) {
		    		ans = A + B;
		    		opt = msk;
		    	}
	    	}
 
	    	vector <vector <int>> a(n, vector <int> (m));
	    	for (int i = 0; i < sz; ++i) {
	    		if (opt & (1 << i)) {
	    			int r = i / m;
					int c = i % m;
					a[r][c] = 1;
	    		}
	    	}
 
	    	cout << ans << "\n";
	    	for (int i = 0; i < n; ++i) {
	    		for (int j = 0; j < m; ++j) {
	    			cout << (a[i][j]? "+" : "-");
	    		}
	    		cout << "\n";
	    	}
	    	continue;
	    }
 
	    // sub2
	    if (n <= 4 || m <= 4) {
	    	if (min(n, m) == n) {
	    		int r = n / 2;
	    		if (n % 2 == 0) --r;
	    		cout << (m + r) << "\n";
	    		for (int i = 1; i <= r; ++i) {
	    			for (int j = 1; j <= m; ++j)
	    				cout << "+";
	    			cout << "\n";
	    		}
 
	    		for (int i = r + 1; i <= n; ++i) {
	    			for (int j = 1; j <= m; ++j)
	    				cout << "-";
	    			cout << "\n";
	    		}
	    		continue;
	    	}
 
	    	if (min(n, m) == m) {
	    		int c = m / 2;
	    		if (m % 2 == 0) --c;
	    		cout << (n + c) << "\n";
	    		for (int i = 1; i <= n; ++i) {
	    			for (int j = 1; j <= m; ++j) {
	    				cout << (j <= c? "-" : "+");
	    			}
	    			cout << "\n";
	    		}
	    		continue;
	    	}
	    }
 
	    //sub3
	    if (min(n, m) <= 5) {
	    	if (min(n, m) == n) {
	    		cout << (m + (n + 1)/ 2) << "\n";
	    		for (int i = 1; i <= m; ++i) 
	    			cout << ((i <= m / 2 + 1)? "+" : "-");
	    		cout << "\n";
	    		for (int i = 1; i <= m; ++i) 
	    			cout << ((i < m / 2)? "-" : "+");
	    		cout << "\n";
	    		for (int i = 1; i <= m; ++i) 
	    			cout << ((m / 2 <= i && i <= m / 2 + 1)? "-" : "+");
	    		cout << "\n";
 
	    		for (int i = 4; i <= n; ++i) {
	    			for (int j = 1; j <= m; ++j) 
	    				cout << "-";
	    			cout << "\n";
	    		}
	    		continue;
	    	}
 
	    	if (min(n, m) == m) {
	    		cout << (n + (m + 1)/ 2) << "\n";
 
	    		vector <vector <char>> a(n + 5, vector <char> (m + 5, '+'));
	    		for (int i = 1; i <= n; ++i) 
	    			a[i][1] = ((i <= n / 2 + 1)? '-' : '+');
 
	    		for (int i = 1; i <= n; ++i) 
	    			a[i][2] = ((i < n / 2)? '+' : '-');
 
	    		for (int i = 1; i <= n; ++i) 
	    			a[i][3] = ((n / 2 <= i && i <= n / 2 + 1)? '+' : '-');
 
	    		for (int i = 1; i <= n; ++i) {
	    			for (int j = 1; j <= m; ++j) 
	    				cout << a[i][j];
	    			cout << "\n";
	    		}
	    		continue;
	    	}
	    }

	    // sub4: ans = n + m - 2;
	    if ((n & 1) && (m & 1)) {
	    	vector <vector <char>> a(n + 5, vector <char> (m + 5, '-'));

            int x = (n + 1) / 2;
            cout << (n + m - 2) << "\n";
            for (int i = 1; i < x; ++i)
                for (int j = 1; j <= m; ++j) 
                    a[i][j] = ((j <= m / 2 + 1)? '+' : '-');

            a[x][(m / 2 + 1)] = '+';

            for (int i = x + 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j) 
                    a[i][j] = ((j >= m / 2 + 1)? '+' : '-');


            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) 
                    cout << a[i][j];
                cout << "\n";
            }
            continue;
	    }

        /*
            odd, odd : n + m - 2;
            min_even, max_odd : n + m - 3;
            max_even, min_odd : n + m - 2;
            even, even : n + m - 3;
        */

        if (m >= n) {
            vector <vector <char>> a(n + 5, vector <char> (m + 5, '-'));
            vector <int> col(m + 5);

            int require = (m / 2) + 1;
            int add = 0;
            int cnt = 0;
            int r = 1, c = 1;
            while (r <= n) {
                a[r][c] = '+'; 
                col[c]++;
                ++c; ++cnt;
                if (cnt == require) {
                    bool fail = false;
                    for (int j = 1; j <= m; ++j) {
                        if (col[j] > n - (n / 2 + 1)) 
                            fail  = true;
                    }
                    if (fail) {
                        for (int j = 1; j <= m; ++j)
                            a[r][j] = '-';
                        break;
                    }

                    cnt = 0;
                    ++r;
                    ++add;
                }
                if (c == m + 1) c = 1;
            }
            
            // n - (n / 2 + 1) : max '*' in a colum;
            int ans = m + add;

            cout << ans << "\n";
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) 
                    cout << a[i][j];
                cout << "\n";
            }

        } 
        else {
            vector <vector <char>> a(n + 5, vector <char> (m + 5, '+'));
            vector <int> row(n + 5);

            int require = (n / 2) + 1;
            int add = 0;
            int cnt = 0;
            int r = 1, c = 1;
            while (c <= m) {
                a[r][c] = '-'; 
                row[r]++;
                ++r; ++cnt;
                if (cnt == require) {
                    bool fail = false;
                    for (int j = 1; j <= n; ++j) {
                        if (row[j] > m - (m / 2 + 1)) 
                            fail  = true;
                    }
                    if (fail) {
                        for (int j = 1; j <= n; ++j)
                            a[j][c] = '+';
                        break;
                    }

                    ++c;
                    ++add;
                    cnt = 0;
                }
                if (r == n + 1) r = 1;
            }
            
            int ans = n + add;
            cout << ans << "\n";
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) 
                    cout << a[i][j];
                cout << "\n";
            }
        }
    }
    
    
    return 0;
}