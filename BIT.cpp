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
#include <ctime>
 
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

const int MAX=10;
int i, val;
int tree[MAX];

int read(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=tree[idx];
		idx-=(idx&(-idx));
	}
	return sum;
}

void update(int idx, int val)
{
	while(idx<MAX)
	{
		tree[idx]+=val;
		idx+=(idx&(-idx));
	}
}

int readSingle(int idx)
{
	int sum=tree[idx];
	if(idx>0)
	{
		int z=idx-(idx&(-idx));
		idx--;
		while(idx!=z)
		{
			sum-=tree[idx];
			idx-=(idx&(-idx));
		}
	}
	return sum;
}

int main()
{
	for(i=1;i<MAX;++i)
	{
		scanf("%d", &val);
		update(i, val);
	}
	printf("%d\n", read(5));
	update(5, 6);
	printf("%d\n", read(5));
	return 0;
}