#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using ll = long long;

int __gcd(int a, int b){
    if (b == 0) return a;
    return __gcd(b, a % b);
}

ll __gcd(ll a, ll b){
    if (b == 0) return a;
    return __gcd(b, a % b);
}

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename Y>
void __print(stack <Y> x){
	vector <Y> y;
	cout << "{";
	while (!x.empty()){
		y.push_back(x.top());
		x.pop();
	}
	Y e = y.back();
	y.pop_back();
	for (auto &i : y) cout << i << ", ";
	
	cout << e << "} ";
}
template<typename Y>
void __print(queue <Y> x){
	vector <Y> y;
	cout << "{";
	while (!x.empty()){
		y.push_back(x.front());
		x.pop();
	}
	Y e = y.back();
	y.pop_back();
	for (auto &i : y) cout << i << ", ";
	
	cout << e << "} ";
}
template<typename Y>
void __print(priority_queue <Y> x){
	vector <Y> y;
	cout << "{";
	while (!x.empty()){
		y.push_back(x.top());
		x.pop();
	}
	Y e = y.back();
	y.pop_back();
	for (auto &i : y) cout << i << ", ";
	
	cout << e << "} ";
}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << "{"; __print(x.first); cout << ", "; __print(x.second); cout << "}\n";}
template<typename T>
void __print(const T &x) {int f = 0; for (auto &i : x) cout << (f++ ? ", " : ""), __print(i);}

void _print() {cout << " ]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}

#define debug(x...) cout << "#L" <<__LINE__ <<": [" << #x << "]:\n" <<"[ "; _print(x);
#define debugArr(A, a, b)  cout << "#L" <<__LINE__ <<": ["; { cout << #A << "]:\n[ "; FOR(_,a,b - 1) cout << A[_] << ", "; cout << A[b] << " ]\n"; }
#endif


