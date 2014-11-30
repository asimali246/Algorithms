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
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ans=exgcd(b,a%b,x,y);
        long long t=x;
        x=y;
        y=t-a/b*y;
        return ans;
    }
}
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    long long a,b,x,y,d;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        d=gcd(a,b);
        a/=d,b/=d;
        exgcd(a,b,x,y);
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
    return 0;
}