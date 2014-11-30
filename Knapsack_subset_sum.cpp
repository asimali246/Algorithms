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
int memo[1010][35], p[1010], w[1010];
int value(int id, int rem)
{
    if(id==n||rem==0)return 0;
    if(memo[id][rem]!=-1)return memo[id][rem];
    if(w[id]>rem)return memo[id][rem]=value(id+1, rem);
    else
        return memo[id][rem]=max(value(id+1, rem),p[id]+value(id+1,rem-w[id]));
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int g;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%d %d", &p[i], &w[i]);
        }
        scanf("%d", &g);
        int ans=0;
        memset(memo, -1, sizeof memo);
        while(g--)
        {
            int tmp;
            scanf("%d", &tmp);
            ans+=value(0, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}