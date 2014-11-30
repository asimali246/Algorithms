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
int main()
{
    int n;
    int x[9], y[9];
    int c=1;
    while(1)
    {
        scanf("%d", &n);
        if(!n)break;
        int a[n+1];
        for(int i=1;i<=n;++i)
        {
            a[i]=i;
            scanf("%d %d", &x[i], &y[i]);
        }
        printf("**********************************************************\n");
        printf("Network #%d\n", c);
        ++c;
        double ans =2147483647.00;
        int  d[n+1];
        double b[n+1], c[n+1];
        do
        {
            double sum=0.0;
            for(int i=1;i<n;++i)
            {
                int xx=abs(x[a[i+1]]-x[a[i]]);
                int yy=abs(y[a[i+1]]-y[a[i]]);
                double term=(sqrt(xx*xx+yy*yy))+16.0;
                c[i]=term;
                sum+=term;
            }
            if(sum<ans)
            {
                ans=sum;
                memcpy(d, a, sizeof a);
                memcpy(b, c, sizeof c);
            }
        }while(next_permutation(a+1, a+n+1));
        for(int i=1;i<n;++i)
        {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[d[i]], y[d[i]], x[d[i+1]], y[d[i+1]], b[i]);
        }
        printf("Number of feet of cable required is %.2lf.\n", ans);
    }
    return 0;
}
