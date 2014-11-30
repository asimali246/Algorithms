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

void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<(int)adj[u].size();++i)
	{
		ii temp=adj[u][i];
		if(visited[temp.first]==0)
		{
			parent[temp.first]=u;
			dfs(temp.first);
		}
		else
		if(visited[temp.first]==1)
		{
			if(parent[u]==temp.first)
			{
				printf("Back Edge\n");
			}
			else
				printf("There is a cycle in a graph.\n");
		}
		else
		if(visited[temp.first]==2)
			printf("There is a forward edge in the graph.\n");
	}
	visited[u]=2;
}