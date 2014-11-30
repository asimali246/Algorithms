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
    ll b, p, m;
    ll ans=0;
    while(scanf("%lld %lld %lld", &b, &p, &m)!=EOF)
    {
        ll ans=1;
        while(p>0)
        {
            if(p & 1)
            {
                ans=(ans*b)%m;
            }
            b=(b*b)%m;
            p>>=1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}