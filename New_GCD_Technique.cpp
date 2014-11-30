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
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
ll gcd(ll a , ll b)
{
	while(a>0 && b>0)
		if(a>b)a%=b;
		else
			b%=a;
	return a+b;
}
int main()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", gcd(a, b));
	return 0;
}