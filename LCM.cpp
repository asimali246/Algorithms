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
ll gcd(ll a, ll b)
{
	if(b==0)return a;
	else
	return gcd(b, a%b);
}
int main()
{
	ll n, i, j, k;
	ll a[10000];
	ll ans=0;
	while(1)
	{
		scanf("%lld", &n);
		if(!n)break;
		if(n==1){printf("1 1\n");continue;}
		ll x=(ll)sqrt(n);
		k=0;
		ans=0;
		for(i=1;i<=x;++i)
		{
			if(n%i==0)
			{
				a[k++]=i;
				a[k++]=(n/i);
			}
		}
		for(i=0;i<k;++i)
		{
			for(j=i+1;j<k;++j)
				if(gcd(a[i], a[j])==1)
					++ans;
		}
		if(x*x==n)--ans;
		printf("%lld %lld\n",n,  ans+1);
	}
	return 0;
}
