const int inf = 1e9;
const bool PERSISTENT = false; // set to true for persistence
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of −inf
	Node(vector <int> & v, int lo, int hi): lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	Node* set(int L, int R, int x, bool persist = PERSISTENT) {
		if (R <= lo || hi <= L) return this;
		Node* res = persist ? new Node(*this) : this;
		if (L <= lo && hi <= R) {
			res->mset = res->val = x;
			res->madd = 0;
		} else {
			res->push();
			res->l=res->l->set(L,R,x),res->r=res->r->set(L,R,x);
			res->val = max(res->l->val, res->r->val);
		}
		return res;
	}
	Node* add(int L, int R, int x, bool persist = PERSISTENT) {
		if (R <= lo || hi <= L) return this;
		Node* res = persist ? new Node(*this) : this;
		if (L <= lo && hi <= R) {
			if (res->mset != inf) res->mset += x;
			else res->madd += x;
			res->val += x;
		} else {
			res->push();
			res->l=res->l->add(L,R,x),res->r=res->r->add(L,R,x);
			res->val = max(res->l->val, res->r->val);
		}
		return res;
	}
	void push() {
		bool nw = PERSISTENT;
		if (!l) {
			nw = false;
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l=l->set(lo,hi,mset,nw),r=r->set(lo,hi,mset,nw),mset=inf;
		else if (madd)
			l=l->add(lo,hi,madd,nw),r=r->add(lo,hi,madd,nw),madd=0;
	}
};