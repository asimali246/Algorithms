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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int t, n, i, j, k, ans, p;
int adj[33][33];
char s[111], a, tmp[111];
bool blank=false;
map<char, int> mp;
vi src;

int main()
{
    src.clear();
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--)
    {
        src.clear();
        mp.clear();
        ans=-INF;
        for(i=1;i<=26;++i)
            for(j=1;j<=26;++j)
                adj[i][j]=(i==j)?0:INF;
        while(gets(s)!=NULL)
        {
            if(strlen(s)==0 || strcmp(s, "")==0)
                break;
            tmp[0]='\0';
            sscanf(s, "%c %d %s\n", &a, &n, tmp);
            mp[a]=n;
            if(strlen(tmp)==0)
                src.push_back(a-64);
            for(i=0;i<(int)strlen(tmp);++i)
                adj[tmp[i]-64][a-64]=-n;
        }
        for(k=1;k<=26;++k)
            for(i=1;i<=26;++i)
                for(j=1;j<=26;++j)
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
        for(i=0;i<(int)src.size();++i)
        {
            p=INF;
            for(j=1;j<=26;++j)
                p=min(adj[src[i]][j], p);
            if(p<=0)
            {
                p=abs(p);
                p+=mp[src[i]+64];
                ans=max(p, ans);
            }
        }
        if(blank)
            putchar('\n');
        blank=true;
        printf("%d\n", ans);
    }
    return 0;
}