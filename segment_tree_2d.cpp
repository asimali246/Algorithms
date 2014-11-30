#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>
#include <ctime>
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-15
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
 
const int N = 555;
int a[N][N], m, p, q, r, s, i, j, n;
char ch;
ii t[5*N][5*N];

inline ii combine(ii a, ii b){
	return ii(max(a.first, b.first), min(a.second, b.second));
}
void build_y(int vx, int lx, int rx, int vy, int ly, int ry){
	if(ly==ry){
		if(lx==rx)
			t[vx][vy]=ii(a[lx][ly], a[lx][ly]);
		else
			t[vx][vy]=combine(t[vx*2][vy], t[vx*2+1][vy]);
		return;
	}
	int m=(ly+ry)>>1;
	build_y(vx, lx, rx, vy*2, ly, m);
	build_y(vx, lx, rx, vy*2+1, m+1, ry);
	t[vx][vy]=combine(t[vx][vy*2], t[vx][vy*2+1]);
}
void build_x(int vx, int lx, int rx){
	if(lx!=rx){
		int m=(lx+rx)>>1;
		build_x(vx*2, lx, m);
		build_x(vx*2+1, m+1, rx);
	}
	build_y(vx, lx, rx, 1, 1, n);
}
ii query_y(int vx, int vy, int ly, int ry, int qly, int qry){
	if(ly==qly && ry==qry)
		return t[vx][vy];
	int m=(ly+ry)>>1;
	if(qry<=m)
		return query_y(vx, vy*2, ly, m, qly, qry);
	else
	if(qly>m)
		return query_y(vx, vy*2+1, m+1, ry, qly, qry);
	else
		return combine(query_y(vx, vy*2, ly, m, qly, m), query_y(vx, vy*2+1, m+1, ry, m+1, qry));
}
ii query_x(int vx, int lx, int rx, int qlx, int qly, int qrx, int qry){
	if(lx==qlx && rx==qrx)
		return query_y(vx, 1, 1, n, qly, qry);
	int m=(lx+rx)>>1;
	if(qrx<=m)
		return query_x(vx*2, lx, m, qlx, qly, qrx, qry);
	else
	if(qlx>m)
		return query_x(vx*2+1, m+1, rx, qlx, qly, qrx, qry);
	else
		return combine(query_x(vx*2, lx, m, qlx, qly, m, qry), query_x(vx*2+1, m+1, rx, m+1, qly, qrx, qry));
}
void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int v){
	if(ly==ry){
		if(lx==rx)
			t[vx][vy]=ii(v, v);
		else
			t[vx][vy]=combine(t[vx*2][vy], t[vx*2+1][vy]);
		return;
	}
	int m=(ly+ry)>>1;
	if(y<=m)
		update_y(vx, lx, rx, vy*2, ly, m, x, y, v);
	else
		update_y(vx, lx, rx, vy*2+1, m+1, ry, x, y, v);
	t[vx][vy]=combine(t[vx][vy*2], t[vx][vy*2+1]);
}
void update_x(int vx, int lx, int rx, int x, int y, int v){
	if(lx!=rx){
		int m=(lx+rx)>>1;
		if(x<=m)
			update_x(vx*2, lx, m, x, y, v);
		else
			update_x(vx*2+1, m+1, rx, x, y, v);
	}
	update_y(vx, lx, rx, 1, 1, n, x, y, v);
}
int main(){
	scanf("%d %d", &n, &n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			scanf("%d", &a[i][j]);
	build_x(1, 1, n);
	scanf("%d", &m);
	getchar();
	while(m--){
		ch=getchar();
		if(ch=='q'){
			scanf(" %d %d %d %d", &p, &q, &r, &s);
			getchar();
			ii ans=query_x(1, 1, n, p, q, r, s);
			printf("%d %d\n", ans.first, ans.second);
		}
		else{
			scanf(" %d %d %d", &p, &q, &r);
			getchar();
			update_x(1, 1, n, p, q, r);
		}
	}
	return 0;
}