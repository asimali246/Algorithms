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
ll gcd(ll a, ll b)
{
    if(!b)return a;
    else
        return gcd(b, a%b);
}
int main()
{
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", gcd(a, b));
    return 0;
}