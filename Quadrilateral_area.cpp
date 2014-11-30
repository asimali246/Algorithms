#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;
typedef vector<int> vi;
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
int main()
{
    int n;
    scanf("%d", &n);
    double a[n+1][3];
    for(int i=1;i<=n;++i)
        scanf("%lf %lf", &a[i][1], &a[i][2]);
    double aa=0.0, bb=0.0, cc=0.0;
    double max1=0.0, max2=0.0;
    double ans=0.0;
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            double dx=(double)(a[j][1]-a[i][1]);
            double dy=(double)(a[j][2]-a[i][2]);
            for(int k=1;k<=n;++k)
            {
                if(k==i||k==j)continue;
                    double tmp=dx*(double)(a[k][2]-a[i][2])-(dy*(double)(a[k][1]-a[i][1]));
                    aa=(double)sqrt((a[j][2]-a[i][2])*(a[j][2]-a[i][2])+((a[j][1]-a[i][1])*(a[j][1]-a[i][1])));
                    bb=(double)sqrt((a[j][2]-a[k][2])*(a[j][2]-a[k][2])+((a[j][1]-a[k][1])*(a[j][1]-a[k][1])));
                    cc=(double)sqrt((a[k][2]-a[i][2])*(a[k][2]-a[i][2])+((a[k][1]-a[i][1])*(a[k][1]-a[i][1])));
                    double s=(aa+bb+cc)/2.0;
                    double area=sqrt(s*(s-aa)*(s-bb)*(s-cc));
                if(tmp<0)
                {
                    if(area>max1)
                        max1=area;
                }
                else
                {
                    if(area>max2)
                        max2=area;
                }
            }
            if((max1+max2)>ans&&max1!=0 && max2!=0)
                ans=max1+max2;
            max1=0.0;
            max2=0.0;
        }
    }
    printf("%.9lf\n", ans);
    return 0;
}