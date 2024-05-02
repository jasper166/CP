#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 9;
struct Node {
	vector <int> c; // current state to array
	vector <int> pos; // pos(X): current index of value X
	int dep, pa; // current distant to start node, parent of current node
	Node(vector <int> _c) {
		init(_c);
	}
	void init(vector <int> _c) {
		dep = 0;
		pa = -1;
		c = _c;
		pos.resize(N);
		iota(pos.begin(), pos.end(), 0);
		for (int i = 0; i < N; ++i)
			pos[c[i]] = i;
	}

	int getHash() {
		int sum = 0;
		for (int i = 0; i < N; ++i) sum = sum * 10 + c[i];
		return sum;
	}
	bool isSolvable() {
		int inv = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (c[i] > c[j] && c[i] && c[j]) ++inv;
			}
		}
		return (inv % 2 == 0);
	}

	bool isEqual(Node &ot) {
		return getHash() == ot.getHash();
	}
	void swapCell(int i, int j) {
		swap(pos[c[i]], pos[c[j]]);
		swap(c[i], c[j]);
	}
	void rand(){
		vector <int> nc;
		nc.resize(N);
		iota(nc.begin(), nc.end(), 0);
		random_shuffle(nc.begin(), nc.end());

		init(nc);
	}
};


const Node GOAL = Node({1, 2, 3, 4, 5, 6, 7, 8, 0});

vector <int> adj[N];
vector <pair <int, int>> cor(N);

void init() {
	// Building the adjacent list of index
	adj[0] = {1, 3};
	adj[1] = {0, 2, 4};
	adj[2] = {1, 5};
	adj[3] = {4, 0, 6};
	adj[4] = {3, 5, 1, 7};
	adj[5] = {4, 2, 8};
	adj[6] = {7, 3};
	adj[7] = {6, 8, 4};
	adj[8] = {7, 5};
	// Cordinate of each index
	cor[0] = {1, 1}; cor[1] = {1, 2}; cor[2] = {1, 3};
	cor[3] = {2, 1}; cor[4] = {2, 2}; cor[5] = {2, 3};
	cor[6] = {3, 1}; cor[7] = {3, 2}; cor[8] = {3, 3};
}

int manhattanDistance(Node x) {
	int sum = 0;
	for (int _ = 1; _ < N; ++_) {
		int i = x.pos[_];
		int j = GOAL.pos[_];
		int dx = (int) abs(cor[i].first - cor[j].first);
		int dy = (int) abs(cor[i].second - cor[j].second);
		sum += (dx + dy);
	}
	return sum;
}

int hammingDistance(Node x) {
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (x.c[i] == 0) continue;
		sum += (x.c[i] != i + 1);
	}
	return sum;
}

int heuristicFunction(Node x) {
	return manhattanDistance(x) + hammingDistance(x);
}

class Solver {
	public : 
		Solver(Node _st, Node _en, int _cmd) : st(_st), en(_en), cmd(_cmd) {};
		virtual ~Solver() {};
		struct cmpUniformCost {
			bool operator() (Node x, Node y) {
				int costX = x.dep;
				int costY = y.dep;
				return (costX > costY);
			} 
		};

		struct cmpGreedyBest {
			bool operator() (Node x, Node y) {
				int costX = heuristicFunction(x);
				int costY = heuristicFunction(y);
				return (costX > costY);
			} 
		};

		struct cmpAStar {
			bool operator() (Node x, Node y) {
				int costX = heuristicFunction(x) + x.dep;
				int costY = heuristicFunction(y) + y.dep;
				return (costX > costY);
			} 
		};

		void process() {
			init();

			// BFS
			if (cmd == 1) {
				queue <Node> q;
				q.push(st);
				vis[st.getHash()] = 1;
				pa[0] = -1;
				int cnt = 0;

				while (!q.empty()) {
					Node u = q.front(); q.pop();
					int p = cnt;
					opts.push_back(u);
					pa[cnt] = u.pa;

					if (u.isEqual(en)) break;

					int current_cell = u.pos[0];
					for (int next_cell : adj[current_cell]) {
						Node v = u;
						v.swapCell(current_cell, next_cell);

						int val = v.getHash();
						
						if (!vis[val] && v.isSolvable()) {
							vis[val] = true;
							v.dep = u.dep + 1;
							v.pa = cnt;
							q.push(v);
						}
					}
					++cnt;
				}
				debug(cnt);
			}

			if (cmd == 2) {
				priority_queue <Node, vector <Node>, cmpUniformCost> q;

				q.push(st);
				vis[st.getHash()] = 1;
				pa[0] = -1;
				int cnt = 0;

				while (!q.empty()) {
					Node u = q.top(); q.pop();
					int p = cnt;
					opts.push_back(u);
					pa[cnt] = u.pa;

					if (u.isEqual(en)) break;
					
					int current_cell = u.pos[0];
					for (int next_cell : adj[current_cell]) {
						Node v = u;
						v.swapCell(current_cell, next_cell);

						int val = v.getHash();
						
						if (!vis[val] && v.isSolvable()) {
							vis[val] = true;
							v.dep = u.dep + 1;
							v.pa = cnt;
							q.push(v);
						}
					}
					++cnt;
				}
				debug(cnt);
			}

			if (cmd == 3) {
				priority_queue <Node, vector <Node>, cmpGreedyBest> q;

				q.push(st);
				vis[st.getHash()] = 1;
				pa[0] = -1;
				int cnt = 0;

				while (!q.empty()) {
					Node u = q.top(); q.pop();
					int p = cnt;
					opts.push_back(u);
					pa[cnt] = u.pa;

					if (u.isEqual(en)) break;
					
					int current_cell = u.pos[0];
					for (int next_cell : adj[current_cell]) {
						Node v = u;
						v.swapCell(current_cell, next_cell);

						int val = v.getHash();
						
						if (!vis[val] && v.isSolvable()) {
							vis[val] = true;
							v.dep = u.dep + 1;
							v.pa = cnt;
							q.push(v);
						}
					}
					++cnt;
				}
				debug(cnt);
			}

			if (cmd == 4) {
				priority_queue <Node, vector <Node>, cmpAStar> q;

				q.push(st);
				vis[st.getHash()] = 1;
				pa[0] = -1;
				int cnt = 0;

				while (!q.empty()) {
					Node u = q.top(); q.pop();
					int p = cnt;
					opts.push_back(u);
					pa[cnt] = u.pa;

					if (u.isEqual(en)) break;
					
					int current_cell = u.pos[0];
					for (int next_cell : adj[current_cell]) {
						Node v = u;
						v.swapCell(current_cell, next_cell);

						int val = v.getHash();
						
						if (!vis[val] && v.isSolvable()) {
							vis[val] = true;
							v.dep = u.dep + 1;
							v.pa = cnt;
							q.push(v);
						}
					}
					++cnt;
				}
				debug(cnt);
			}	
		}

		void showSolution() {
			vector <vector <int>> ans;
			int p = opts.size() - 1;

			while (pa[p] != -1) {
				ans.push_back(opts[p].c);
				p = pa[p];
			}
			ans.push_back(opts[p].c);
			reverse(ans.begin(), ans.end());

			int sz = ans.size();
			cout << "Pattern is solvable in " << sz << " " << (sz <= 1? "step" : "steps") << ":\n";
			for (int i = 0; i < sz; ++i) {
				cout << "Step " << i + 1 << ":\n";
				auto x = ans[i];
				for (int r = 0; r < N; ++r) {
					cout << x[r] << " ";
					if (r % 3 == 2) cout << "\n";
				}
				cout << "\n";
			}
		}
	private :
		vector <Node> opts; // Storing potential states
		map <int, int> pa; // Storing parent states
		map <int, bool> vis; // Avoid over-lapping state calculation
		Node st, en;
		int cmd;
};

signed main() {

    cout << "Initial State: \n";
    vector <int> inp(N);
    for (int i = 0; i < N; ++i) cin >> inp[i];
    cout << "\n";
	
	
	Node Init(inp);
    while (!Init.isSolvable()) {
    	cout << "Impossible solution! Try another!: \n";
	    for (int i = 0; i < N; ++i) cin >> inp[i];
	    cout << "\n";
    }

    Init.init(inp);

    cout << "Choose search algorithm:\n";
    cout << "1. Breadth-First\n";
    cout << "2. Uniform-Cost\n";
    cout << "3. Greedy-Best\n";
    cout << "4. AStar\n";
    int cmd; cin >> cmd;

    cout << "Solving...\n";

    Solver sol(Init, GOAL, cmd);
    sol.process();
	sol.showSolution();
    // debug(Init.c);

}	

/*
	8 6 2 1 0 3 5 4 7
	1 - 27924
	2 - 29801
	3 - 463
	4 - 84

*/