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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int N, n, m, s, t, x, y, w, i, cs=1;
vi dist;
priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<vector<ii> > adj;

int main()
{
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        dist.clear();
        adj.clear();
        adj.assign(n, vector<ii>());
        dist.assign(n, INF);
        pq.push(ii(0, s));
        dist[s]=0;
        for(i=0;i<n;++i)
            adj[i].clear();
        while(m--)
        {
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back(ii(y, w));
            adj[y].push_back(ii(x, w));
        }
        while(!pq.empty())
        {
            ii temp=pq.top();pq.pop();
            int d=temp.first, u=temp.second;
            if(d==dist[u])
                for(int j=0;j<(int)adj[u].size();++j)
                {
                    ii v=adj[u][j];
                    if(dist[u]+v.second<dist[v.first])
                    {
                        dist[v.first]=dist[u]+v.second;
                        pq.push(ii(dist[v.first], v.first));
                    }
                }
        }
        if(dist[t]!=INF)
            printf("Case #%d: %d\n",cs++,  dist[t]);
        else
            printf("Case #%d: unreachable\n", cs++);
    }
    return 0;
}