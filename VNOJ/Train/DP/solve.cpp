/**
* LANG: C++
* author: atom
* created: 17.07.2022 09:52:28
**/
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
const int MAX = 110;
int n, r, len;
vector <vector<int>> adj(MAX);
int a[MAX][MAX], pos[MAX], dp[1 << 16][12], vis[1 << 16][12];
typedef pair <int, pii> Node;

int orz() {

	scanf("%d%d", &n, &r);
	memset(a, 0x3f, sizeof(a));
	FOR(i, 1, n) FOR(j, 1, n) {
		int x;
		scanf("%d", &x);
		if (x) a[i][j] = x;
	}
	// debug(adj);
	cin.ignore();
	string s;
	FOR(j, 1, r) {
		getline(cin, s);
		stringstream ss;
		ss << s;
		memset(dp, 0x3f, sizeof(dp));
		memset(pos, -1, sizeof(pos));
		int found;
		int m = 0;
		vector <int> paths;
		while (ss >> found) {
			dp[1 << m][m] = 0;
			paths.push_back(found);
			pos[found] = m++;
		}
		priority_queue<Node, vector <Node>, greater <Node>> pq;
		pq.push(make_pair(0, make_pair(1, 0)));
		while (!pq.empty()) {
			int x = pq.top().F;
			int y = pq.top().S.F;
			int z = paths[pq.top().S.S];
			pq.pop();
			if (vis[y][z] == j) continue;
			vis[y][z] = j;
			for (int i = 0; i < paths.size(); i++) {
				if (y >> i & 1) continue;
				int &tmp = dp[1 << i | y][i];
				if (tmp > x + a[z][paths[i]]) {
					tmp = x + a[z][paths[i]];
					pq.push(make_pair(tmp, make_pair(1 << i | y, i)));
				}
			}
		}
		// int tmp = 0
		// cout << (int) 0x3f3f3f3f << "\n";
		int ret = dp[(1 << paths.size()) - 1][paths.size() - 1];
		if (ret == 0x3f3f3f3f) ret = 0;
		cout << ret << "\n";
		// debug(paths[i]);
	}
}
/* problem link:

*/

