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
#define inf 2147483640
ll calc(int n)
{
    int x=sqrt(n);
    ll ans=0;
    for(int i=1;i<=x;++i)
    {
        ans+=(n/i);
    }
    ans*=2;
    ans-=x*x;
    return ans;
}
int main()
{
    int n, t;
    ll ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%lld\n", calc(n));
    }
    return 0;
}
/*
        The formula for n/1 + n/2 + n/3 + n/4 + ....... + n/n-1 + n/n is:
                x=n/1 + n/2 + .... + n/sqrt(n) and then
                x*=2;
                y=sqrt(n)
                x-=(y*y);
                print x;
*/