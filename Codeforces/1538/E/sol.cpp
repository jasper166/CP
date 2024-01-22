#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif


string fun = "haha";

int count(string t) {
	int p = fun.size();
	int ret = 0;
	for (int i = 0; i + p - 1 < (int) t.size(); ++i) {
		string x = t.substr(i, p);
		if (x == fun) ++ret;
	}
	return ret;
}

struct Node {
	string prf, suf;
	ll cnt;
	Node() {
		prf = suf = "";
		cnt = 0;
	}
	Node(string _s) {
		prf = _s.substr(0, 3);
		suf = _s.substr(max(0, (int) (_s.size()) - 3), 3);
		cnt = count(_s);
	};
};

Node merge(Node x, Node y) {
	Node z;
	z.cnt = x.cnt + y.cnt + count(x.suf + y.prf);
	// check if x's prefix and y's suffix can form any "haha";
	z.prf = x.prf;
	for (int i = 0; z.prf.size() < 3; ++i) z.prf += y.prf[i];
	z.suf = y.suf;
	for (int i = (int) x.suf.size() - 1; z.suf.size() < 3; --i) z.suf = x.suf[i] + z.suf;	
	return z;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    // merge(Node("hhihi"), Node("haha"));
   	int t; cin >> t;
   	while (t--) {

   		int q; cin >> q;

   		ll ret = 0;
   		map <string, Node> mp;
   		for (int i = 1; i <= q; ++i) {
   			string x, y, z, cmd, op;
   			cin >> x >> cmd;
   			// assign
   			if (cmd == ":=") {
   				cin >> y;
   				mp[x] = Node(y);
   			}
   			else {
   				cin >> y >> op >> z;
   				mp[x] = merge(mp[y], mp[z]);
   			}
   			// add
   			ret = mp[x].cnt;
   		}
   		cout << ret << "\n";
   	}
    
}

