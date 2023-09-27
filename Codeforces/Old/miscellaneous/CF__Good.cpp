#include <bits/stdc++.h>
using namespace std;

const int Max=102;
int n,m;
int sx,sy,fx,fy;
bool VISIT[Max][Max];
int matrix[Max][Max];
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,-2,-1,1,2};

void bfs(){
    queue < pair<int,int> > sto;
    VISIT[sx][sy] = false;
    sto.push({sx,sy});
    while(!sto.empty()){
        auto u = sto.front();
        sto.pop();

        for(int i=0;i<8;i++){
            int a = u.first + dx[i];
            int b = u.second + dy[i];
            if(a==fx && b==fy){
                cout << "YES\n";
                exit(0);
            }

            if(a<0 || a>=n || b<0 || b>=n) continue;
            if(VISIT[a][b] == false) continue;

            VISIT[a][b] = false;
            sto.push({a,b});
        }
    }
    cout << "NO\n";
}

void solve(){
    cin >> n;
    cin >> sx >> sy >> fx >> fy;
    --sx, --sy, --fx, --fy;
    for(int i=0;i<=n - 1;i++){
        for(int j=0;j<=n -1;j++){
            cin >> matrix[i][j];
            if(matrix[i][j]==0) VISIT[i][j] = false;
            else VISIT[i][j] = true;
        }
    }
    if(VISIT[fx][fy]==false){
        cout << "NO";
        return;
    }
    bfs();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}