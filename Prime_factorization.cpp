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
int sumi(ll n)
{
    int sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int prime(ll n)
{
    int sum=0, k=0, flag=0;
    int t=sqrt(n);
    for(int i=2;i<=t;++i)
    {
        k=0;
        while(n%i==0){k++;n/=i;flag=1;}
        int tmp=sumi(i);
        sum+=(k*tmp);
    }
    if(n>1)sum+=sumi(n);
    if(flag==0)return -55;
    return sum;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    ll i;
    while(t--)
    {
        scanf("%d", &n);
        for(i=n+1;i<inf;++i)
        {
            int x=sumi(i);
            int y=prime(i);
            if(x==y)
            {
                printf("%lld\n", i);
                break;
            }
        }       
    }
    return 0;
}