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
bitset<1000010> bs;
int mu[1000001], M[1000001];
int main()
{
    vi primes;
    bs.set();
    bs[0]=bs[1]=0;
    ll i, j, n;
    for(i=2;i<=1001;i++)
    {
        if(!bs[i])continue;
        for(j=i*i;j<=1000000;j+=i)
            bs[j]=0;
        primes.push_back(i);
    }
    j=primes.size();
    mu[1]=1;
    M[1]=1;
    int num=0, x, count=0, flag=0;;
    for(i=2;i<=1000000;++i)
    {
        if(bs[i])
        {
            mu[i]=-1;
            M[i]=mu[i]+M[i-1];
            continue;
        }
        int ii=i;flag=0;num=0;
        for(n=0;n<j&&primes[n]<ii;++n)
        {
            count=0;
            x=primes[n];
            if(ii%x==0)
            {
                while(ii%x==0){ii/=x;count++;if(count>1)break;}
                if(count>1)
                {
                    mu[i]=0;
                    M[i]=M[i-1];
                    flag=1;
                    break;
                }
                num++;
            }
        }
        if(ii!=1)num+=1;
        if(flag==1)continue;
        if(num%2==0)
        {
            mu[i]=1;
            M[i]=M[i-1]+1;
        }
        else
        {
            mu[i]=-1;
            M[i]=M[i-1]-1;
        }
    }
    while(1)
    {
        scanf("%lld", &n);
        if(!n)break;
        printf("%8lld%8d%8d\n", n, mu[n], M[n]);
    }
    return 0;
}