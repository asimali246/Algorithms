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
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int i, j, k, x, y, cs=1;
int adj[111][111];
bool flag;
int sum, d;

int main()
{
    while(1)
    {
        flag=false;
        for(i=1;i<=100;++i)
            for(j=1;j<=100;++j)
                adj[i][j]=(i==j)?0:INF;
        while(1)
        {
            scanf("%d %d", &x, &y);
            adj[x][y]=1;
            if(!x && !y)
                break;
            flag=true;
        }
        if(!flag)
            break;
        for(k=1;k<=100;++k)
            for(i=1;i<=100;++i)
                for(j=1;j<=100;++j)
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
        sum=d=0;
        for(i=1;i<=100;++i)
            for(j=1;j<=100;++j)
                if(adj[i][j]!=INF && i!=j)
                    sum+=adj[i][j], d++;
        printf("Case %d: average length between pages = %.3lf clicks\n", cs++, (double)sum/d);
    }
    return 0;
}
