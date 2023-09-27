#include <bits/stdc++.h>
using namespace std;

int n,k;
int x[30];
int a[30];
//-------------------Cac ham su dung--------------------
void init(); // Khoi tao cau hinh dau tien
void display(); // In ra cau hinh hien tai
void genNext(); // Sinh ra cau hinh tiep theo
bool isLast(); // Kiem tra cau hinh cuoi cung
//------------------------------------------------------

int main(){
    init(); 
    while(!isLast()){
        display();
        genNext();
    }
    display();
}

void init(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        x[i] = i;
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
}

void display(){
    for(int i = 1; i <= k; i++){
        cout << a[x[i]] << " ";
    }
    cout << endl;   
}

bool isLast(){
    for(int i = 1; i <= k; i++){
        if(x[i] != n - k + i){
            return false;
        }
    }
    return true;
}

void genNext(){
    int i = k;
    while(x[i] == n - k + i){
        i--;
    }
    x[i]++;
    for(int j = i + 1; j <= k; j++)
        x[j] = x[j - 1] + 1;
}
