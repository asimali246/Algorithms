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
int n;
int memo[300][300], p[30], w[30];
int value(int id, int rem)
{
    if(id==n || rem<=0)return 0;
    if(memo[id][rem]!=-1)return memo[id][rem];
    if(w[id]>rem)return memo[id][rem]=value(id+1, rem);
    else
        return memo[id][rem]=max(value(id+1, rem), p[id]+value(id+1,rem-w[id]));
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        char s[100000], *point;
        gets(s);
        int sum=0;
        n=0;
        for(point=strtok(s, " ");point;point=strtok(NULL, " "))
            {w[n++]=atoi(point);sum+=w[n-1];p[n-1]=w[n-1];}
        int ans=0;
        memset(memo, -1, sizeof memo);
        if(sum%2==1)
            printf("NO\n");
        else
        {
            sum/=2;
            ans=value(0, sum);
            if(ans==sum)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}