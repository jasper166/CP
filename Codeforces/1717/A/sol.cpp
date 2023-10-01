#include "bits/stdc++.h"

int n;
void solver(){
    std :: cin >> n;
    std :: cout << n + (n / 2) * 2 + (n / 3) * 2 << "\n";
}

int main(){

    int Test = 1;
    std :: cin >> Test;
    while (Test--){
        solver();
    }
}



