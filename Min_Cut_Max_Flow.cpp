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

int n, m, c, i, j, x, y, res[55][55], s=1, t=2, f;
vector<ii> edge;
vector<vector<ii> > adj;
vi p, vis;
queue<int> q;
bitset<60> bs;
map<int, int> mp;

void augment(int v, int minCost)
{
    if(v==s)
    {
        f=minCost;
        return;
    }
    else
    if(p[v]!=-1)
    {
        augment(p[v], min(minCost, res[p[v]][v]));
        res[p[v]][v]-=f;
        res[v][p[v]]+=f;
    }
}

void dfs(int u)
{
    vis[u]=1;
    mp[u]=1;
    for(int j=1;j<=n;++j)
    {
        if(res[u][j]>0 && vis[j]==-1)
            dfs(j);
    }
}

int main()
{
    adj.clear(), p.clear(), vis.clear();
    adj.assign(60, vector<ii>()), p.assign(60, -1), vis.assign(60, -1);
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(!n && !m)
            break;
        memset(res, 0, sizeof res);
        for(i=1;i<=n;++i)
            adj[i].clear(), vis[i]=-1;
        edge.clear();
        mp.clear();
        while(m--)
        {
            scanf("%d %d %d", &x, &y, &c);
            edge.push_back(ii(x, y));
            res[x][y]=res[y][x]=c;
            adj[x].push_back(ii(y, c));
            adj[y].push_back(ii(x, c));
        }
        while(1)
        {
            q=queue<int>();
            q.push(s);
            bs.reset();
            for(i=1;i<=n;++i)
                p[i]=-1;
            bs[s]=1;
            f=0;
            while(!q.empty())
            {
                int u=q.front();q.pop();
                if(u==t)
                    break;
                for(j=0;j<(int)adj[u].size();++j)
                {
                    ii v=adj[u][j];
                    if(res[u][v.first]>0 && !bs[v.first])
                    {
                        bs[v.first]=1;
                        q.push(v.first);
                        p[v.first]=u;
                    }
                }
            }
            augment(t, INF);
            if(!f)
                break;
        }
        for(i=1;i<=n;++i)
            mp[i]=2;
        dfs(s);
        for(i=0;i<(int)edge.size();++i)
        {
            if(mp[edge[i].first]!=mp[edge[i].second])
                printf("%d %d\n", edge[i].first, edge[i].second);
        }
        putchar('\n');
    }
    return 0;
}