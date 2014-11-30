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
#include<cstring>
using namespace std;
typedef vector<int> vi;
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
int main()
{
    ll a[1000010];
    a[1]=0;
    a[2]=1;
    ll x=1, tmp=0, count=0;
    for(int i=3;i<=1000000;++i)
    {   
        if(count==0)
        {
            tmp=x*x+x;
            a[i]=a[i-1]+tmp;
            ++count;
        }
        else
        {
            count=0;
            ++x;
            tmp=x*x;
            a[i]=a[i-1]+tmp;
        }
    }
    ll n;
    while(1)
    {
        scanf("%lld", &n);
        if(n<3)break;
        n-=2;
        printf("%lld\n", a[n]);
    }
    return 0;
}