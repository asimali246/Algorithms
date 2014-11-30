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

int t, r, c, i, j, x, y, a[111][111], flag, num;
vi path, topo, vis;
vector<vector<ii> > adj;
bool blank=false;
char s[11111], *p;

void dfs(int u)
{
    vis[u]=1;
    for(int j=0;j<(int)adj[u].size();++j)
    {
        if(!vis[adj[u][j].first])
            dfs(adj[u][j].first);
    }
    topo.push_back(u);
}

int main()
{
    path.clear(), topo.clear(), adj.clear(), vis.clear();
    adj.assign(111111, vector<ii>()), path.assign(111111, 0), vis.assign(111111, 0);
    scanf("%d", &t);
    while(t--)
    {
        num=1;
        scanf("%d %d", &r, &c);
        getchar();
        for(i=1;i<111111;++i)
            adj[i].clear();
        for(i=1;i<111;++i)
            for(j=1;j<111;++j)
                a[i][j]=1;
        for(i=1;i<=r;++i)
        {
            flag=0;
            s[0]='\0';
            gets(s);
            for(p=strtok(s, " ");p;p=strtok(NULL, " "))
            {
                if(!flag)
                    x=atoi(p), flag=1;
                else
                {
                    y=atoi(p);
                    a[x][y]=0;
                }
            }
        }
        num=1;
        for(i=1;i<100000;++i)
            path[i]=0, vis[i]=0;
        for(i=1;i<=r;++i)
            for(j=1;j<=c;++j)
            {
                if(!a[i][j])
                {
                    vis[num]=1;
                    num++;
                    continue;
                }
                if(j+1<=c && a[i][j+1])
                    adj[num].push_back(ii(num+1, -1));
                if(i+1<=r && a[i+1][j])
                    adj[num].push_back(ii(num+c, -1));
                ++num;
            }
        topo.clear();
        for(i=1;i<num;++i)
            if(!vis[i])
                dfs(i);
        reverse(topo.begin(), topo.end());
        path[1]=1;
        for(i=0;i<(int)topo.size();++i)
        {
            int u=topo[i];
            for(j=0;j<(int)adj[u].size();++j)
            {
                ii v=adj[u][j];
                path[v.first]+=path[u];
            }
        }
        if(blank)
            putchar('\n');
        blank=true;
        printf("%d\n", path[r*c]);
    }
    return 0;
}