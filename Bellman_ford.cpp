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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int t, x, y, w, n, m, i, u, j;
bool ans;
vector<vector<ii> > adj;
vi dist;
ii v;

int main()
{
    adj.clear(), dist.clear();
    adj.assign(1010, vector<ii>()), dist.assign(1010, INF);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i=0;i<=n;++i)
            adj[i].clear(), dist[i]=INF;
        while(m--)
        {
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back(ii(y, w));
        }
        dist[0]=0;
        ans=false;
        for(i=0;i<n-1;++i)
            for(u=0;u<n;++u)
                for(j=0;j<(int)adj[u].size();++j)
                {
                    v=adj[u][j];
                    if(dist[v.first]>dist[u]+v.second)
                        dist[v.first]=dist[u]+v.second;
                }
        for(u=0;u<n;++u)
            for(j=0;j<(int)adj[u].size();++j)
            {
                v=adj[u][j];
                if(dist[v.first]>dist[u]+v.second)
                    ans=true;
            }
        if(ans)
            puts("possible");
        else
            puts("not possible");
    }
    return 0;
}