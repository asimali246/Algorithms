#include <iostream>
#include <cstdlib>
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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
int k;
int a[25];
void combinations(int ans[], int start, int elem)
{
    if(elem==6)
    {
        for(int i=0;i<6;++i)
        {
            if(i>0)
                printf(" ");
            printf("%d", ans[i]);
        }
        putchar('\n');
        return;
    }
    for(int i=start; i<k; ++i)
    {
        ans[elem++]=a[i];
        combinations(ans, i+1, elem);
        elem--;
    }
}
int main()
{
    bool flag=false;
    while(1)
    {
        scanf("%d", &k);
        if(!k)
            break;
        for(int i=0;i<k;++i)
            scanf("%d", &a[i]);
        int ans[10];
        if(flag)
            putchar('\n');
        flag=true;
        combinations(ans, 0, 0);
    }
}