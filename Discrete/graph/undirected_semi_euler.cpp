#include <bits/stdc++.h>
using namespace std;

int V, u, a[1000][1000], check[1000];
vector<int> t;

int dfs(int u){
    stack<int> st;
    check[u] = 1;
    st.push(u);t.push_back(u);
    while(!st.empty()){
        int k = st.top();
        st.pop();
        for(int i = 1; i <= V; i++){
            if(a[k][i] == 1 && check[i] == 0){
            	t.push_back(k);
                check[i] = 1;
                st.push(k);
                st.push(i);
                break;
            }
        }
    }
    return t.size();
}

int isWI(){
    for(int i = 1; i <= V; i++){
    	t.clear();
        if(dfs(i) == V)
            return 1;
    }
    return 0;
}

void Run(){
    cin >> V;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0, kt = 0;
    for(int i = 1; i <= V; i++){
    	int sum = 0;
        for(int j = 1; j <= V; j++){
            sum += a[i][j];
        }
        if(sum % 2)cnt++;
    }
    if(cnt == 0 || cnt == 2)kt = 1;
    if(isWI() && kt){
        cout << "La do thi nua Euler";
    }else
        cout << "Khong phai do thi nua Euler";
}

int main(){
    Run();
}
/*

*/