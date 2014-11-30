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
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
int main()
{
    ll n,m;
    while(scanf("%lld %lld", &n, &m)!=EOF)
    {
        ll ans=1;
        for(ll i=n;i>=n-m+1;--i)
        {
            ans*=i;
            while(ans%10==0)ans/=10;
            ans%=1000000000;
        }
        printf("%lld\n", ans%10);
    }
    return 0;
}