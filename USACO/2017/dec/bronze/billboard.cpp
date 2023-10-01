/*	
 * 	@Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

struct board{
	int x1, y1, x2, y2;
	int area(){
		return (y2 - y1) * (x2 - x1);
	}
};


int lap(board p, board q){
	int xLap = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
	int yLap = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
	return xLap * yLap;
}
int orz(){
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	board a, b, t;
	scanf("%d%d%d%d", &a.x1, &a.y1, &a.x2, &a.y2);
	scanf("%d%d%d%d", &b.x1, &b.y1, &b.x2, &b.y2);
	scanf("%d%d%d%d", &t.x1, &t.y1, &t.x2, &t.y2);

	printf("%d\n", a.area() + b.area() - lap(a, t) - lap(b, t));
	return 0;
}
