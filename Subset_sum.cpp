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
int a[210];
long long int memo[210][210][25];
int n, m, d, q, s=1;
long long int value(int id,int p,long long int sum)
{
    if(p==m && sum==0)return 1;
    if(id==n)return 0;
    if(memo[id][p][sum]!=-1)return memo[id][p][sum];
    long long int tmp=0;
    tmp+=value(id+1, p, sum);
    tmp+=value(id+1, p+1, ((long long int)(((sum+a[id])%d)+d)%d));
    memo[id][p][sum]=tmp;
    return tmp;
}
int main()
{
    while(1)
    {
        scanf("%d %d", &n, &q);
        if(n==0 && q==0)break;
        for(int i=0;i<n;i++)
            scanf("%d", &a[i]);
        int qq=1;
        printf("SET %d:\n", s);
        ++s;
        while(q--)
        {
            scanf("%d %d", &d, &m);
            memset(memo, -1, sizeof memo);
            long long int ans=value(0, 0, 0);
            printf("QUERY %d: %lld\n", qq, ans);
            ++qq;
        }
    }
    return 0;
}