#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>

 using namespace std;

#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int n, i;
ll ans;
int a[1000010], b[1000010];

void merge(int l1, int r1, int l2, int r2)
{
	int x=l1, y=l2, xx=1;
	int pos=0;
	while(x<=r1 && y<=r2)
	{
		if(a[x]>a[y])
		{
			b[pos++]=a[y++];
			ans+=(ll)((r1-l1+2)-xx);
		}
		else
		{
			b[pos++]=a[x++];
			xx++;
		}
	}
	while(x<=r1)
		b[pos++]=a[x++];
	while(y<=r2)
		b[pos++]=a[y++];
	pos=0;
	for(i=l1;i<=r2;++i)
		a[i]=b[pos++];
}

void merge_sort(int low, int high)
{
	if(low<high)
	{
		int center=(low+high)>>1;
		merge_sort(low, center);
		merge_sort(center+1, high);
		merge(low, center, center+1, high);
	}
}

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		ans=0;
		for(i=0;i<n;++i)
			scanf("%d", &a[i]);
		merge_sort(0, n-1);
		printf("%lld\n", ans);
	}
	return 0;
}
