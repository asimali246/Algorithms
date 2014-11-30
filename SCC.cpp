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

vector<vector<ii> > adj;
vi low, num, visited, S;
int t, n, m, ans, x, y, i, counter, cs=1;
map<string, int> mp;
map<int, string> rev;
char a[33], b[33];
bool blank=false, space=false;

void Tarjan(int u)
{
	low[u]=num[u]=counter++;
	S.push_back(u);
	visited[u]=1;
	for(int j=0;j<(int)adj[u].size();++j)
	{
		ii v=adj[u][j];
		if(num[v.first]==-1)
			Tarjan(v.first);
		if(visited[v.first])
			low[u]=min(low[u], low[v.first]);
	}
	if(low[u]==num[u])
	{
		while(1)
		{
			int v=S.back();
			S.pop_back();
			visited[v]=0;
			if(space)
				printf(", ");
			space=true;
			cout<<rev[v];
			if(u==v)
				break;
		}
		printf("\n");
		space=false;
	}
}
int main()
{
	adj.assign(33, vector<ii>());
	visited.assign(33, 0);
	low.assign(33, 0);
	low.assign(33, 0);
	num.assign(33, 0);
	while(true)
	{
		counter=1;
		scanf("%d %d", &n, &m);
		if(!n && !m)
			break;
		for(i=1;i<=n;++i)
			adj[i].clear(), num[i]=-1, low[i]=visited[i]=0;
		mp.clear();
		rev.clear();
		while(m--)
		{
			scanf("%s %s", a, b);
			if(mp.count(a)==0)
			{
				mp[a]=counter++;
				rev[counter-1]=a;
			}
			if(mp.count(b)==0)
			{
				mp[b]=counter++;
				rev[counter-1]=b;
			}
			adj[mp[a]].push_back(make_pair(mp[b], 1));
		}
		if(blank)
			putchar('\n');
		blank=true;
		counter=0;
		S.clear();
		printf("Calling circles for data set %d:\n", cs++);
		for(i=1;i<=n;++i)
			if(num[i]==-1)
				{
					space=false;
					Tarjan(i);
				}
	}
	return 0;
}