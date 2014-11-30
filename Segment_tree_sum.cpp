#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <vector>
#include <new>
#include <fstream>
#include <map>
#include <bitset>
#include <cstring>
 using namespace std;
#define ll long long int 
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
typedef pair<char, int> ci;
#define Max 1100000
ll n, q;
ll a[Max], t[5*Max+10];
void build (ll v, ll tl, ll tr) 
{
    if(tl==tr)
        t[v]=a[tl];
    else 
    {
        ll tm=(tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
ll sum (ll v, ll tl, ll tr, ll l, ll r)
{
    if(l>r)
        return 0;
    if(l==tl && r==tr)
        return t[v];
    ll tm=(tl+tr)/2;
    return sum(v*2, tl, tm, l, min(r,tm))+sum(v*2+1, tm+1, tr, max(l,tm+1), r);
}
void update (ll v, ll tl, ll tr, ll pos, ll val) 
{
    if (tl==tr)
        t[v]+=val;
    else 
    {
        ll tm=(tl+tr)/2;
        if(pos<=tm)
            update(v*2, tl, tm, pos, val);
        else
            update(v*2+1, tm+1, tr, pos, val);
        t[v]=t[v*2]+t[v*2+1];
    }
}
int main()
{
    scanf("%lld %lld", &n, &q);
    for(int i=0;i<n;++i)
        scanf("%lld", &a[i]);
    getchar();
    build(1, 0, n-1);
    char ch;
    ll a, b;
    while(q--)
    {
        cin>>ch;
        scanf("%lld %lld", &a, &b);
        getchar();
        if(ch=='G')
            update(1, 0, n-1, a, b);
        else
        if(ch=='T')
            update(1, 0, n-1, a, -b);
        else
        if(ch=='S')
            printf("%lld\n", sum(1, 0, n-1, a, b));
    }
    return 0;
}