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
int const maxn=41;
int const maxs=2*maxn*1000+10;
int const offset=40*1000;
int n, f;
int a[maxn], pos[maxn][maxs], neg[maxn][maxs];
int respos[maxn], resneg[maxn];
int value(int id, int sum)
{
    if(id==n)
        return sum==f;
    int &pp=pos[id][sum+offset];
    int &nn=neg[id][sum+offset];
    if(pp!=-1 && nn!=-1)
        return pp||nn;
    pp=nn=0;
    if(sum+a[id]<maxs)
        pp|=value(id+1, sum+a[id]);
    if(sum-a[id]+offset<maxs)
        nn|=value(id+1, sum-a[id]);
    if(pp)respos[id]=1;
    if(nn)resneg[id]=1;
    return pp||nn;
}
int main()
{
    while(1)
    {
        scanf("%d %d", &n, &f);
        if(n==0 && f==0)return 0;
        for(int i=0;i<n;++i)
            scanf("%d", &a[i]);
        memset(pos, -1, sizeof pos);
        memset(neg, -1, sizeof neg);
        memset(respos, 0, sizeof respos);
        memset(resneg, 0, sizeof resneg);
        int ans=value(0, 0);
        if(ans==0)
        {
            printf("*\n");
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                if(respos[i] && resneg[i])printf("?");
                else
                    if(respos[i])printf("+");
                else
                    if(resneg[i])printf("-");
            }
            printf("\n");
        }
    }
    return 0;
}