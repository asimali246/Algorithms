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
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
ll mod;
struct Matrix
{
    ll a[2][2];
};
ll fastExp(ll a, ll p)
{
    if(p==0)return 1;
    if(p==1)return a;
    else
    {
        ll res=fastExp(a, p/2);
        res*=res;
        if(p & 1)res*=a;
        return res;
    }
}
Matrix multiply(Matrix a, Matrix b)
{
    struct Matrix ans;
    int i, j, k;
    for(i=0;i<2;++i)
        for(j=0;j<2;++j)
        {
            ans.a[i][j]=0;
            for(k=0;k<2;++k)
                ans.a[i][j]+=(a.a[i][k]*b.a[k][j])%mod;
            ans.a[i][j]%=mod;
        }
    return ans;
}
Matrix solve(Matrix base, ll p)
{
    struct Matrix ans;
    int i, j;
    for(i=0;i<2;++i)
        for(j=0;j<2;++j)
            ans.a[i][j]=(i==j);
    while(p)
    {
        if(p&1)
            ans=multiply(ans, base);
        base=multiply(base, base);
        p>>=1;
    }
    return ans;
}
int main()
{
    ll n, m;
    while(scanf("%lld %lld", &n, &m)!=EOF)
    {
        mod=fastExp(2, m);
        struct Matrix ans;
        ans.a[0][0]=ans.a[0][1]=ans.a[1][0]=1;
        ans.a[1][1]=0;
        ans=solve(ans, n);
        printf("%lld\n", ans.a[0][1]);
    }
    return 0;
}