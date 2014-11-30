#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
#include<fstream>
#include<map>
using namespace std;
typedef vector<int> vi;
#define inf 2147483640
int x[15], y[15], dist[15][15], memo[12][1<<11], n;
int tsp(int pos, int mask)
{
    if(mask==((1<<(n+1))-1))return dist[pos][0];
    if(memo[pos][mask]!=-1)return memo[pos][mask];
    int ans=inf;
    for(int i=0;i<=n;++i)
    {
        if(i!=pos && !(mask & (1<<i)))
        ans=min(ans, dist[pos][i]+tsp(i, mask|(1<<i)));
    }
    return memo[pos][mask]=ans;
}

int main()
{
    int t, f,ff;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &f, &ff);
        scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
            scanf("%d %d", &x[i], &y[i]);
        memset(memo, -1, sizeof memo);
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
            {
                dist[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            }
        }
        int ans=tsp(0, 1);
        printf("The shortest path has length %d\n" , ans);
    }
    return 0;
}
