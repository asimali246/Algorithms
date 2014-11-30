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
#include<cstring>
using namespace std;
typedef vector<int> vi;
#define inf 2147483640
int n, k, s;
int a[1000010];
int check(int d)
{
    int i, j, count=1, limit, flag=0, x=4;
    int tmp=a[2]-a[1];
    if(tmp>d)return 0;
    i=3, limit=2*k+1;
    while(count!=n)
    {
        for(j=i;j<=limit;++j)
            if(a[j+1]-a[j]<=d){flag=1;break;}
        if(flag==1)++count;
        else
            return 0;
        flag=0;
        i=j+2;
        limit=x*k+1;
        x+=2;
        if(count==n)return 1;
    }
    if(count<n)return 0;
    return 1;
}
int main()
{
    int d, i, low, high, tmp, flag=0;
    while(scanf("%d %d", &n, &k)!=EOF)
    {
        s=2*n*k;
        flag=0;
        for(i=1;i<=s;++i)
            scanf("%d", &a[i]);
        sort(a+1, a+s+1);
        low=0, high=a[s-k+1]-a[1];
        while(low<high)
        {
            d=(low+high)/2;
            tmp=check(d);
            if(tmp==1)
                {flag=1;high=d;}
            else
                {flag=0;low=d+1;}
        }
        if(k==0 || n==0){printf("0\n");continue;}
        if(flag==0 && n!=1 && low!=high)low-=1;
        printf("%d\n", low);
    }
    return 0;
}