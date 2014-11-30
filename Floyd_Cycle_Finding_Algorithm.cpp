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
#include <bitset>
#include <cstring>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
int z, l, i, m;
int f(int x)
{
    return (z*x+i)%m;
}
ii solve()
{
    int t=f(l), h=f(f(l));
    while(t!=h)
    {
        t=f(t);
        h=f(f(h));
    }
    h=l;
    int mu=0;
    while(h!=t)
    {
        h=f(h);
        t=f(t);
        mu++;
    }
    h=f(t);
    int lambda=1;
    while(h!=t)
    {
        h=f(h);
        lambda++;
    }
    return ii(mu,lambda);
}
int main()
{
    int t=1;
    while(1)
    {
        scanf("%d %d %d %d", &z, &i, &m, &l);
        if(z==0 && i==0 && m==0 && l==0)
            break;
        ii ans=solve();
        printf("Case %d: %d\n", t++, ans.second);
    }
    return 0;
}