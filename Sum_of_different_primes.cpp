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
int b[1000], memo[500][20][1200];
int n, k;
int value(int id,int pos, int rem)
{
    if(id==n||rem<0)return 0;
    if(pos==k)
    {
        if(rem==0)return 1;
        else
            return 0;
    }
    if(memo[id][pos][rem]!=-1)return memo[id][pos][rem];
    int tmp=0;
    if(b[id]>rem)
        tmp+=value(id+1, pos, rem);
    else
    {
        tmp+=value(id+1, pos, rem);
        tmp+=value(id+1, pos+1, rem-b[id]);
    }
    return memo[id][pos][rem]=tmp;
}
int main()
{
    int a[1200];
    memset(a, 0, sizeof a);
    for(int i=2;i<=1200;++i)
    {
        if(a[i]==1)continue;
        for(int j=i+i;j<=1200;j+=i)
            a[j]=1;
    }
    k=0;
    for(int i=2;i<1200;++i)
        if(a[i]==0)b[k++]=i;
    for(int i=0;i<n;++i)cout<<b[i]<<endl;
    n=k;
    int nn, ans;
    while(1)
    {
        scanf("%d %d", &nn , &k);
        if(nn==0 && k==0)break;
        memset(memo, -1, sizeof memo);
        ans=value(0, 0, nn);
        printf("%d\n", ans);
    }
    return 0;
}