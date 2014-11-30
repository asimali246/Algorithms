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
    int i,j,x;
    int a[40000];
    bool flag=false;
    int t=1;
    while(1)
    {
        scanf("%d", &x);
        if(x==-1)break;
        a[0]=x;
        int max=1;
        i=1;
        while(1)
        {
            scanf("%d", &x);
            if(x==-1)break;
            a[i++]=x;
        }
        vi v(a, a+i);
        vi lis(i, 1);
        for(i=0;i<v.size();i++)
        {
            for(j=0;j<i;j++)
            {
                if(v[j]>v[i] && lis[i]<lis[j]+1)
                {
                    lis[i]=lis[j]+1;
                    if(lis[i]>max)max=lis[i];
                }
            }
        }
        if(flag==true)printf("\n");
        flag=true;
        printf("Test #%d:\n", t++);
        printf("  maximum possible interceptions: %d\n", max);
    }
    return 0;
}