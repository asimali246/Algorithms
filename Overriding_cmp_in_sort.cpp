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
struct Node
{
    char name[30];
    ll time;
};
bool cmp(Node a, Node b)
{
    if(a.time<b.time)return true;
    if(a.time>b.time)return false;
    if(strcasecmp(a.name, b.name)>0)
        return false;
    else
        return true;
}
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        struct Node ans[n];
        int k=0;
        while(n--)
        {
            int m, s, ms;
            char ss[100];
            scanf("%s : %d min %d sec %d ms", ss, &m, &s, &ms);
            ll tmp=(m*60+s)*1000+ms;
            strcpy(ans[k].name, ss);
            ans[k].time=tmp;
            ++k;
        }
        //for(int i=0;i<k;++i)
          //  printf("%s  %lld\n", ans[i].name, ans[i].time);
        sort(ans, ans+k, cmp);
        //for(int i=0;i<k;++i)
          //  printf("%s  %lld\n", ans[i].name, ans[i].time);
        int cs=1;
        for(int i=0;i<k;i+=2)
        {
            printf("Row %d\n", cs);
            printf("%s\n", ans[i].name);
            if(i+1<k)
                printf("%s\n", ans[i+1].name);
            cs++;
        }
        printf("\n");
    }
    return 0;
}