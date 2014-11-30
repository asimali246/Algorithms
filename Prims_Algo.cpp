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

 using namespace std;

#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<vector<ii> > adj;
vi visited;
int cost=0;

void process(int u)
{
	visited[u]=1;
	for(int j=0;j<(int)adj[u].size();++j)
	{
		ii v=adj[u][j];
		if(!visited[v.first])
			pq.push(ii(v.second, v.first));
	}
}
int main()
{
	process(0);
	while(!pq.empty())
	{
		ii ed=pq.top();
		pq.pop();
		int v=ed.second, w=ed.first;
		if(!visited[v])
			cost+=w, process(v);
	}
	printf("%d\n", cost);
	return 0;
}