#include "bits/stdc++.h"

using    namespace      std;
typedef     long        long ll;

#define     mem(a,b)    memset(a, b, sizeof(a))
#define     SZ          100010
#define     SZ1         2610

char    str[SZ];
ll  dp[SZ1][SZ1];

ll solve(ll s,ll e)
{
    if(s == e)      return dp[s][e] = 1;
    if(s > e)       return dp[s][e] = 0;
    ll &ret = dp[s][e];
    if(ret != -1)       return ret;
    ret = max(solve(s+1, e), solve(s, e-1));
    if(str[s] == str[e]) ret = max(ret, 2+solve(s+1, e-1));
    return ret;
}

void path(ll s,ll e, ll cnt)
{
    if(cnt <= 0 || s > e) return;
    if(s == e)
    {
        printf("%c",str[s]);
        return;
    }
    if(dp[s][e] == dp[s+1][e])  return path(s+1, e, cnt);
    if(dp[s][e] == dp[s][e-1])  return path(s, e-1, cnt);
    printf("%c",str[s]);        path(s+1, e-1, cnt-2);      printf("%c",str[e]);
}

int main()
{
    scanf("%s",str);    ll n = strlen(str); n = min((int)n-1, 2600);

    for(ll i=0;i<=n;i++)    for(ll j=0;j<=n;j++)    dp[i][j] = -1;
    solve(0, n);
    path(0, n, 100);// 100 is the limit
    printf("\n");
    return 0;
}