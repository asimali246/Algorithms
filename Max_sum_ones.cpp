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
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int a[n+1][n+1];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                a[i][j]=1;
        int b, r1,c1, r2, c2;
        scanf("%d", &b);
        for(int i=1;i<=b;++i)
        {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            for(int k=r1;k<=r2;++k)
                for(int l=c1;l<=c2;++l)
                    a[k][l]=0;
        }
        int sum[n+1][n+1];
        memset(sum, 0, sizeof sum);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                sum[i][j]=a[i][j];
                if(i>1)sum[i][j]+=sum[i-1][j];
                if(j>1)sum[i][j]+=sum[i][j-1];
                if(i>1 && j>1)sum[i][j]-=sum[i-1][j-1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                for(int k=i;k<=n;++k)
                {
                    for(int l=j;l<=n;++l)
                    {
                        int temp=sum[k][l];
                        if(i>1)temp-=sum[i-1][l];
                        if(j>1)temp-=sum[k][j-1];
                        if(i>1 && j>1)temp+=sum[i-1][j-1];
                        if(temp==((k-i+1)*(l-j+1)))
                        if(temp>ans)ans=temp;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}