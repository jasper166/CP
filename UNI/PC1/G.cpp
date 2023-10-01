#include <bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE 1

string to_string(char x) {return (string) "\'" + x + "\'";}
string to_string(const string &x) {return '\"' + x + '\"';}
string to_string(const char *x) {return to_string((string) x);}
string to_string(bool x) {return x ? "true" : "false";}
template<typename T, typename V> string to_string(const pair<T, V> &x)
{return '(' + to_string(x.first) + ',' + to_string(x.second) + ')';}
template<typename T> string to_string(const T &x)
{int f = 0; string r; for (auto &i: x) r += (f++ ? "," : "") + to_string(i); return '{' + r + '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v)
{cerr << to_string(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define pb push_back
#define endl '\n'
#define f first
#define s second
#define pii pair<int, int>
#define INF INT_MAX
//#define ll long long
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define reset(A) memset(A, 0, sizeof(A))

#ifndef ONLINE_JUDGE
#define debug(...)
#else
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#endif



const int MAXN = 1e5 + 5;

// code start here

const int base = 1e9 + 7;

const int N = 1e5 + 5;
const int M = 4;

#define int long long

struct Node{
	int length;
	int hash;
};

#define ll long long
#define ls root << 1
#define rs root << 1 | 1
string s;
Node ST[MAXN << 2], lazy[MAXN << 2];

ll pre[MAXN] = {};


long long my_pow(int x, int y){
	if(y == 0)
		return 1;
	if(y & 1)
		return my_pow(x, y - 1) * (x % base) % base;
	ll value = my_pow(x, y / 2) % base;
	return value * value % base;
}

void build(int root, int left, int right){
	if(left > right) return;
	if(left == right){
		ST[root].length = 1;
		ST[root].hash = s[left] - '0';
		return;
	}
	int mid = (left + right) >> 1;
	build(ls, left, mid);
	build(rs, mid + 1, right);
	ST[root].length = ST[ls].length + ST[rs].length;
	ST[root].hash = (ST[ls].hash * my_pow(10, ST[rs].length) % base + ST[rs].hash) % base;
}

void down(int id){
	Node node = lazy[id];
	if(node.length == -1) 
		return;
    lazy[id*2].hash = node.hash;
	ST[id * 2].hash = (1LL * pre[ST[id * 2].length] * node.hash) % base;
	
    lazy[id*2+1].hash = node.hash;
    ST[id * 2 + 1].hash = (1LL * pre[ST[id * 2 + 1].length] * node.hash) % base;


    lazy[id].hash = lazy[id].length = -1;
}

void update(int root, int left, int right, int l, int r, int value){
	if(left > r || right < l)
		return;
	if(left >= l && right <= r){
		int cur_len = right - left + 1;
		lazy[root].length = cur_len;
		lazy[root].hash = value;
		ST[root].length = cur_len;
		ST[root].hash = 1LL * pre[cur_len] * value % base;
		return;
	}
	
	down(root);
	
	int mid = (left + right) >> 1;
	update(ls, left, mid, l, r, value);
	update(rs, mid + 1, right, l, r, value);
	ST[root].hash = (ST[ls].hash * my_pow(10, ST[rs].length) % base + ST[rs].hash) % base;
	
}
Node def;


Node get(int root, int left, int right, int l, int r){
	if(l > r) return def;
	if(left > r || right < l) return def;

	if(left >= l && right <= r){
		return ST[root];
	}
	
	down(root);
	int mid = (left + right) >> 1;
	Node nl = get(ls, left, mid, l, r);
	Node nr = get(rs, mid + 1, right, l, r);
	
	ST[root].hash = (ST[ls].hash * my_pow(10, ST[rs].length) % base + ST[rs].hash) % base;

	
	Node result;
	result.length = nl.length + nr.length;
	result.hash = (nl.hash * my_pow(10, nr.length) % base + nr.hash) % base;
	return result;
}

void solution() {
	def.hash = def.length = 0;
	pre[1] = 1;
	for(int i= 2; i<MAXN; i++) pre[i] = (pre[i - 1] * 10 + 1) %  base;
	for(int i=1; i<MAXN; i++) lazy[i].hash = lazy[i].length = -1;
	int n, m, k;
	cin >> n >> m;

	cin >> s;
	s = '_' + s;
	
	build(1, 1, n);
//	for(int i=1; i<11; i++) cout << ST[i].hash << " " << ST[i].length << " ";
	
	while(m--){
		int type, u, v, w;
		cin >> type >> u >> v >> w;
		if(type == 1){
			update(1, 1, n, u, v, w);
			//	for(int i=1; i<11; i++) cout << ST[i].hash << " " << ST[i].length << " ";

		}else{
			int sz = v - u + 1;
			if(w > sz || u > v){
				cout << "NO" << endl;
				continue;
			}
			Node n1 = get(1, 1, n, u, v - w);
			Node n2 = get(1, 1, n, u + w, v);
			
		//	cout << n1.hash << " " << n2.hash << endl;
			cout << (n1.length == n2.length && n1.hash == n2.hash? "YES" : "NO") << endl;
		}
	}
	
}




int32_t main(){	
	
	
	cin.tie(nullptr); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int testcase = 1;	
	//cin >> testcase; cin.ignore();
	while(testcase--) solution();

	return 0;
}