#include <iostream>
#include <cstdlib>
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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
ll power(ll a, ll b, ll n)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%n;
        a=(a*a)%n;
        b>>=1;
    }
    return res%n;
}
ll calc(ll n)
{
    vi fact;
    ll x=n-1, p=x;
    fact.clear();
    for(ll i=2;i*i<=p;++i)
    {
        if(p%i==0)
        {
            fact.push_back(i);
            while(p%i==0)
                p/=i;
        }
    }
    if(p>1)
        fact.push_back(p);
    for(ll i=2;i<=n;++i)
    {
        bool ok=true;
        for(ll j=0;j<fact.size() && ok;++j)
            ok &=(power(i, x/fact[j], n)!=1);
        if(ok)
            return i;
    }
    return -1;
}
int main()
{
    ll n;
    while(1)
    {
        scanf("%lld", &n);
        if(!n)
            break;
        printf("%lld\n", calc(n));
    }
    return 0;
}