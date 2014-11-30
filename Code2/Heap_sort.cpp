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

int n, a[111], i, j;

void max_heapify(int x, int n)
{
    j=x;
    j<<=1;
    while(j<=n)
    {
        if(j+1<=n && a[j]<a[j+1])
            j++;
        if(a[j>>1]>=a[j])
            break;
        else
            swap(a[j>>1], a[j]);
        j<<=1;
    }
}

int main()
{
    n=10;
    for(i=1;i<=10;++i)
        a[i]=rand()%33;
    for(i=n/2;i>=1;--i)
        max_heapify(i, n);
    for(i=n;i>1;--i)
    {
        swap(a[i], a[1]);
        max_heapify(1, i-1);
    }
    for(i=1;i<=n;++i)
        printf("%d\n", a[i]);
    return 0;
}