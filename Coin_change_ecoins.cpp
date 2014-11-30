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
    int n, m, s;
    scanf("%d", &n);
    int dp[310][310], c[45], e[45];
    while(n--)
    {
        scanf("%d %d", &m, &s);
        for(int i=0;i<m;++i)
            scanf("%d %d", &c[i], &e[i]);
        for(int i=0;i<=s;++i)
            for(int j=0;j<=s;++j)
                dp[i][j]=99999999;
        int ans=2147483647;
        dp[0][0]=0;
        for(int i=0;i<m;++i)
        {
            int x=c[i], y=e[i];
            for(int k=x;k<=s;++k)
            {
                for(int l=y;l<=s;++l)
                {
                    if(dp[k-x][l-y]!=99999999)
                        dp[k][l]=min(dp[k][l], 1+dp[k-x][l-y]);
                }
            }
        }
        for(int i=0;i<=s;++i)
        {
            for(int j=0;j<=s;++j)
            {
                if(dp[i][j]!=99999999 && i*i+(j*j)==s*s && ans>dp[i][j])
                    ans=dp[i][j];
            }
        }
        if(ans==2147483647)
            printf("not possible\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}