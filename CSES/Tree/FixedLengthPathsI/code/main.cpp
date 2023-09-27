#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

const int BUF_SZ = 1 << 15;

// BeginCodeSnip{Input}
inline namespace Input {
char buf[BUF_SZ];
int pos;
int len;
char next_char() {
	if (pos == len) {
		pos = 0;
		len = (int)fread(buf, 1, BUF_SZ, stdin);
		if (!len) { return EOF; }
	}
	return buf[pos++];
}

int read_int() {
	int x;
	char ch;
	int sgn = 1;
	while (!isdigit(ch = next_char())) {
		if (ch == '-') { sgn *= -1; }
	}
	x = ch - '0';
	while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
	return x * sgn;
}
}  // namespace Input
// EndCodeSnip
// BeginCodeSnip{Output}
inline namespace Output {
char buf[BUF_SZ];
int pos;

void flush_out() {
	fwrite(buf, 1, pos, stdout);
	pos = 0;
}

void write_char(char c) {
	if (pos == BUF_SZ) { flush_out(); }
	buf[pos++] = c;
}

void write_int(int x) {
	static char num_buf[100];
	if (x < 0) {
		write_char('-');
		x *= -1;
	}
	int len = 0;
	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
	write_char((char)('0' + x));
	while (len) { write_char(num_buf[--len]); }
	write_char('\n');
}

// auto-flush output when program exits
void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output
// EndCodeSnip

int n, k;
int dep[MAX];
vector <int> adj[MAX];

int cnt[MAX], sz[MAX];
bool vis[MAX];
int nCur;
int getCentroid(int u, int p, int Size) {
    for (int v : adj[u]) {
        if (v != p && !vis[v] && sz[v] > Size)
            return getCentroid(v, u, Size);
    }
    return u;
}

int reSubsize(int u, int p) {
    sz[u] = 1;
//    debug(u, p);
    for (int v : adj[u]) {
        if (v != p && !vis[v]) {
            sz[u] += reSubsize(v, u);
        }
    }
    return sz[u];
}

ll ans = 0;
int maxDep = 0;
void process(int u, int p, bool t, int d = 1) {
    if (d > k)
        return;
    if (t) cnt[d]++;
    else {
        ans += cnt[k - d];
    }
//    debug(u, t);
    maxDep = max(maxDep, d);
    for (int v : adj[u]) {
        if (v != p && !vis[v])
            process(v, u, t, d + 1);
    }
}

void decompose(int u, int p) {
    nCur = reSubsize(u, 0);
    int x = getCentroid(u, 0, nCur >> 1);
    dep[x] = 0;
    // Consider the root;
    vis[x] = 1;
    maxDep = 0;
    vector <int> valid;
    for (int v : adj[x]) {
        if (!vis[v]) {
            process(v, x, 0);
            process(v, x, 1);
            valid.push_back(v);
        }
    }
    for (int i = 1; i <= maxDep; ++i) cnt[i] = 0;
    // Make new tree layer;
    for (int v : valid)
        decompose(v, x);

}


void run_case() {
    init_output();
    n = read_int(); k = read_int();
    for (int i = 1; i < n; ++i) {
//        int u, v;
//        cin >> u >> v;
        int u = read_int();
        int v = read_int();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
//    debug(n, k);
    cnt[0] = 1;
    decompose(1, 0);
    write_int(ans);
}

signed main() {
//    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
