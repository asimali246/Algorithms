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

int t, n, i, numDisjointSet, j, num, e;
double x, y, ans;
vector<pair<double, ii> > edge;
vector<pair<double, double> > point;
bool blank=false;
vi p, size;

double dist(pair<double, double> a, pair<double, double> b)
{
	return hypot(a.first-b.first, a.second-b.second);
}

void initSet(int n)
{
	size.assign(n+1, 1);
	p.assign(n+1, 0);
	for(i=1;i<=n;++i)
		p[i]=i;
	numDisjointSet=n;
}
int findSet(int i)
{
	return (p[i]==i)?i:p[i]=findSet(p[i]);
}
bool isSameSet(int i, int j)
{
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
	if(!isSameSet(i, j))
	{
		numDisjointSet--;
		size[findSet(j)]+=size[findSet(i)];
		p[findSet(i)]=p[findSet(j)];
	}
}
int numberDisjointSet()
{
	return numDisjointSet;
}
int sizeSet(int i)
{
	return size[findSet(i)];
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		if(blank)
			putchar('\n');
		blank=true;
		scanf("%d", &n);
		point.clear();
		edge.clear();
		p.clear();
		size.clear();
		initSet(n);
		ans=0.0;
		for(i=1;i<=n;++i)
		{
			scanf("%lf %lf", &x, &y);
			point.push_back(make_pair(x, y));
		}
		e=0;
		for(i=1;i<=n;++i)
		{
			for(j=i+1;j<=n;++j)
			{
				++e;
				edge.push_back(make_pair(dist(point[i-1], point[j-1]), make_pair(i, j)));
			}
		}
		sort(edge.begin(), edge.end());
		num=0;
		for(i=0;i<e;++i)
		{
			pair<double, ii> temp=edge[i];
			if(!isSameSet(temp.second.first, temp.second.second))
			{
				++num;
				ans+=temp.first;
				unionSet(temp.second.first, temp.second.second);
				if(num==n-1)
					break;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}