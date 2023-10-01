#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
// FAST IO
namespace IO {
    const int BUFFER_SIZE = 1 << 15;
 
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
 
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
 
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
 
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();
 
        return input_buffer[advance ? input_pos++ : input_pos];
    }
 
    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;
 
        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;
 
        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
 
        if (negative)
            number = -number;
    }
 
    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
    template<typename T>
    inline void read_char(T &c){
        c = next_char();
    }
};

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e3 + 5;


int n, m;
struct Point {
    int x, y;
};
vector <pair <Point, Point>> fences;
vector <Point> cows;
vector <int> dX, dY;

int d[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int limX, limY;

bool isValid (int x, int y) {
    return (0 <= x && x <= limX && 0 <= y && y <= limY && d[x][y] != -1);
}
int bfs (int X, int Y) {
    queue <pii> q;
    q.emplace(X, Y);
    int res = 1;
    d[X][Y] = -1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isValid(nx, ny)){
                if (d[nx][ny] == 1)
                    res++;
                d[nx][ny] = -1;
                q.emplace(nx, ny);
            }
        }
    }
    return res;
}


void run_case(){
    scanf("%d%d", &n, &m);
    memset(d, 0, sizeof d);
    dX.clear();
    dY.clear();
    cows.clear();
    fences.clear();
    dX.push_back(-INF);
    dY.push_back(-INF);
    dX.push_back(INF);
    dY.push_back(INF);
    limX = limY = -INF;

    for (int i = 1; i <= n; i++) {
        int x, y, X, Y;
        scanf("%d%d%d%d", &x, &y, &X, &Y);
        Point xy = {x, y};
        Point XY = {X, Y};
        fences.push_back(make_pair(xy, XY));
        dX.push_back(x); dX.push_back(X);
        dY.push_back(y); dY.push_back(Y);
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        cows.push_back({x, y});
        dX.push_back(x); dY.push_back(y);
    }
    sort(all(dX));
    sort(all(dY));
    dX.erase(unique(dX.begin(), dX.end()), dX.end());
    dY.erase(unique(dY.begin(), dY.end()), dY.end());
//    debug(dX);
  //  debug(dY);
    
    for (auto &[xy, XY] : fences) {
        xy.x = (lower_bound(all(dX), xy.x) - dX.begin()) * 2;
        xy.y = (lower_bound(all(dY), xy.y) - dY.begin()) * 2;
        XY.x = (lower_bound(all(dX), XY.x) - dX.begin()) * 2;
        XY.y = (lower_bound(all(dY), XY.y) - dY.begin()) * 2;

        limX = max({limX, xy.x, XY.x});
        limY = max({limX, xy.y, XY.y});
    }

    for (auto &[xy, XY] : fences) {
        int x = min(xy.x, XY.x);
        int y = min(xy.y, XY.y);
        int X = max(xy.x, XY.x);
        int Y = max(xy.y, XY.y);
      //  debug(x, y, X, Y);
        for (int row = x; row <= X; row++)
            for (int col = y; col <= Y; col++)
                d[row][col] = -1;
    }

    for (auto &xy : cows) {
        xy.x = (lower_bound(all(dX), xy.x) - dX.begin()) * 2;
        xy.y = (lower_bound(all(dY), xy.y) - dY.begin()) * 2;
        limX = max(limX, xy.x);
        limY = max(limY, xy.y);
        d[xy.x][xy.y] = 1;
    }
   //debug(limX, limY);
//   FOR(col, 0, 30) FOR(row, 0, 30)  cout << d[row][col] << " \n"[row == 30];
    
    int res = 1;
    for (auto &[x, y] : cows) {
        if (d[x][y] == 1){
           // debug(x, y);
            res = max(res, bfs(x, y));
        }
    }
    printf("%d\n", res);
    // for (auto &[xy, XY] : fences) {
    //     debug(xy.x, xy.y, XY.x, XY.y);
    // }
}

signed main(){

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    scanf("%d", &Test);
    FOR(i, 1, Test){

        run_case();
    }
}

