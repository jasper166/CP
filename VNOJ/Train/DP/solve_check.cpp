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
#define inf (int)(1e9)
using namespace std;

const int Max=1e2+10;
int n,r;
int Board[Max][Max];
int Dis,nho;
bool Visit[Max] = {false};
int Test[Max];
int nhoEnd = inf;
int ans = inf;
vector <int> B[Max];

bool Check(int a,int k,int s,int f,int size){
    if(Visit[a]==true) return false;
    if(Board[Test[k-1]][a]==0) return false;
    if(a==s || a==f) return false;
    if(Dis + (size-k)*nho + nhoEnd >= ans) return false;
    return true;
}

void Solution(int k,int v,int f){
    if(Board[v][f]==0) return;
    int temp = Dis + Board[v][f];
    ans = min(ans,temp);
}

void Try(int k,int s,int f,int size,int pos){
    for(int v:B[pos]){
        if(Check(v,k,s,f,size)){
            Test[k] = v;
            Dis += Board[Test[k-1]][v];
            Visit[v] = true;
            if(k==size-1) Solution(k,v,f);
            else Try(k+1,s,f,size,pos);
            Visit[v] = false;
            Test[k] = 0;
            Dis -= Board[Test[k-1]][v];
        }
    }
}

void solve(){
    cin >> n >> r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&Board[i][j]);
            // cin >> Board[i][j];
        }
    }
    cin.ignore();
    for(int i=1;i<=r;i++){
        string s;
        getline(cin,s);
        int temp = 0;
        for(int v:s){
            if(v!=' ') temp = temp*10+(v-'0');
            else{
                B[i].push_back(temp);
                temp = 0;
            }
        }
        if(temp!=0) B[i].push_back(temp);
        int Start = B[i][0];
        int End = B[i][B[i].size()-1];
        int size = B[i].size();
        for(int j=0;j<B[i].size()-2;j++){
            for(int k=j+1;k<B[i].size()-1;k++){
                if(Board[j][k]!=0) nho = min(nho,Board[j][k]);
                if(Board[k][j]!=0) nho = min(nho,Board[k][j]);
            }
        }
        for(auto v:B[i]){
            if(Board[v][End]!=0 && v!=End) nhoEnd = min(nhoEnd,Board[v][End]);
        }
        Test[1] = Start;
        Visit[Start] = true;
        Dis = 0;
        if(size==2){
            cout << Board[Start][End] << '\n';
            continue;
        }
        Try(2,Start,End,size,i);
        if(ans==inf) cout << "0\n";
        else cout << ans << '\n';
        ans = inf;
        nhoEnd = inf;
        nho = inf;
        for(int i=0;i<=n;i++){
            Visit[i] = false;
            Test[i] = 0;
        }
    }
}

int main(){
    // ios_base ::sync_with_stdio(0); 
    // cin.tie(0);
    // cout.tie(0);
//     freopen("input.in","r",stdin);
//  freopen("output.in","w",stdout);
    solve();
}