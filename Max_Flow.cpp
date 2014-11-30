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

int n, s, t, c, cs=1, mf, f, x, y, cost, i, j;
vector<vector<ii> > adj;
int res[111][111];
vi p;
bitset<111> bs;
queue<int> q;

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

int main()
{
    adj.clear(), p.clear();
    adj.assign(111, vector<ii>());
    p.assign(111, -1);
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        mf=0;
        scanf("%d %d %d", &s, &t, &c);
        for(i=1;i<=n;++i)
            adj[i].clear();
        memset(res, 0, sizeof res);
        while(c--)
        {
            scanf("%d %d %d", &x, &y, &cost);
            adj[x].push_back(ii(y, cost));
            adj[y].push_back(ii(x, cost));
            res[x][y]+=cost;
            res[y][x]+=cost;
        }
        while(1)
        {
            for(i=1;i<=n;++i)
                p[i]=-1;
            q=queue<int>();
            bs.reset();
            q.push(s);
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
                        p[v.first]=u;
                        q.push(v.first);
                    }
                }
            }
            augment(t, INF);
            if(f==0)
                break;
            mf+=f;
        }
        printf("Network %d\n", cs++);
        printf("The bandwidth is %d.\n", mf);
        putchar('\n');
    }
    return 0;
}