/*
    Knuth optimization: O(n^3) -> O(n^2)
    dp(i, j) = min(k) : dp(i, k) + dp(k + 1, j) + cost(i, j)
    - cost function sastifies quadrangle inequality
    - opt(i, j - 1) <= opt(i, j) <= opt(i + 1, j);
*/
int n;
int a[N], opt[N][N];
ll dp[N][N], prf[N];

ll cost(int l, int r) {  return (prf[r] - prf[l - 1]); }

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        prf[i] = prf[i - 1] + a[i];
        opt[i][i] = i;
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = opt[i][j - 1]; k <= min(j, opt[i + 1][j]); ++k) {
                ll cur = dp[i][k] + dp[k + 1][j] + cost(i, j);
                if (cur < dp[i][j]) {
                    dp[i][j] = cur;
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}
/*
    Maximum Matching
*/
class maximumBipartiteMatching {
    private:
        int nLeft, nRight;
        vector < int > l, r, dist;
        vector < vector < int > > adj;

    public:
        maximumBipartiteMatching() = default;
        maximumBipartiteMatching(int _n1, int _n2) : 
        nLeft(_n1), nRight(_n2), l(_n1 + 1), r(_n2 + 1), dist(_n1 + 1), adj(_n1 + 1) {}

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        bool bfs(){
            queue < int > qe;
            for(int i = 1; i <= nLeft; i ++){
                if(l[i]){
                    dist[i] = INF;
                }else{
                    dist[i] = 0;
                    qe.push(i);
                }
            }
            for(dist[0] = INF; !qe.empty(); qe.pop()){
                int u = qe.front();
                for(int v : adj[u]){
                    if(dist[r[v]] == INF){
                        dist[r[v]] = dist[u] + 1;
                        qe.push(r[v]);
                    }
                }
            }
            return dist[0] != INF;
        }

        bool dfs(int u){
            if(!u) return true;
            for(int v : adj[u]){
                if(dist[r[v]] == dist[u] + 1 && dfs(r[v])){
                    r[v] = u;
                    l[u] = v;
                    return true;
                }
            }
            dist[u] = INF;
            return false;
        }

        int solve(){
            int ans = 0;
            while(bfs())for(int i = 1; i <= nLeft; i ++){
                if(!l[i])ans += dfs(i);
            }
            return ans;
        }
        void printMaximumMatching(){
            for(int i = 1; i <= nLeft; i ++){
                if(l[i])
                    cout << i << " " << l[i] << el;
            }
        }
};