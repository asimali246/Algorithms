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
        int a[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d", &a[i][j]);
        int ans=-100*75*75;
        int b[n+10];
        for(int i=0;i<n;i++)
        {
            memset(b, 0, sizeof b);
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                    b[k]+=a[(i+j)%n][k];
                for(int k=0;k<n;k++)
                {
                    int sum=0;
                    for(int l=0;l<n;l++)
                        {sum+=b[(k+l)%n];
                        if(sum>ans)ans=sum;}
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}