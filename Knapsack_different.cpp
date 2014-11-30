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
int main()
{
    int m, n;
    int a[110], dp[10100], w[110], p[110];
    while(scanf("%d %d", &m, &n)!=EOF)
    {
        if(n==0 && m==0)return 0;
        m+=200;
        for(int i=0;i<n;i++)
            scanf("%d %d", &w[i], &p[i]);
        memset(dp, 0, sizeof dp);
        dp[0]=1;
        for(int i=0;i<n;++i)
        {
            for(int j=m;j>=0;--j)
            {
                if(dp[j] && (j+w[i])<=m)dp[j+w[i]]=max(dp[j+w[i]], dp[j]+p[i]);
            }
        }
        int ans=0;
        for(int i=0;i<=m-200;++i)
            ans=max(ans, dp[i]);
        for(int i=2001;i<=m;++i)ans=max(ans, dp[i]);
        printf("%d\n", ans-1);
    }
    return 0;
}