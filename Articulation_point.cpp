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

int n, uu, vv, counter, root, children, i, flag, loop, ans;
vector<vector<ii> > adj;
vi low, num, parent, articulation;
char s[1010], *point;

void articulation_point(int u)
{
	low[u]=num[u]=counter++;
	for(int j=0;j<(int)adj[u].size();++j)
	{
		ii v=adj[u][j];
		if(num[v.first]==-1)
		{
			parent[v.first]=u;
			if(u==root)
				children++;
			articulation_point(v.first);
			if(low[v.first]>=num[u])
				articulation[u]=1;
			low[u]=min(low[u], low[v.first]);
		}
		else
		if(parent[u]!=v.first)
			low[u]=min(low[u], num[v.first]);
	}
}

int main()
{
	adj.assign(101, vector<ii>());
	low.assign(101, 0);
	num.assign(101, 0);
	parent.assign(101, 0);
	articulation.assign(101, 0);
	while(true)
	{
		counter=0;
		scanf("%d", &n);
		if(!n)
			break;
		for(i=1;i<=n;++i)
			low[i]=0,num[i]=parent[i]=-1, articulation[i]=0, adj[i].clear();
		loop=0;
		while(true)
		{
			flag=0;
			gets(s);
			for(point=strtok(s, " ");point;point=strtok(NULL, " "))
			{
				if(!flag)
				{
					uu=atoi(point);
					if(!uu)
					{
						loop=1;
						break;
					}
					flag=1;
				}
				else
				{
					vv=atoi(point);
					adj[uu].push_back(make_pair(vv, 1));
					adj[vv].push_back(make_pair(uu, 1));
				}
			}
			if(loop)
				break;
		}
		for(i=1;i<=n;++i)
		{
			if(num[i]==-1)
			{
				root=i;
				children=0;
				articulation_point(i);
				articulation[root]=(children>1);
			}
		}
		ans=0;
		for(i=1;i<=n;++i)
			if(articulation[i])
				++ans;
		printf("%d\n", ans);
	}
	return 0;
}