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
char ss[55][55];
int t, m, n, k;
char p[60];
int l;
ii search()
{
    int flag=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;++j)
        {
            int pos=0, tmp=0, r, s;
            for(r=j;r>=0;--r)
            {
                if(pos==l)
                    break;
                if(ss[i][r]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
            tmp=0, pos=0;
            for(r=i, s=j;r>=0 && s>=0;--r)
            {
                if(pos==l)
                    break;
                if(ss[r][s]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
                --s;
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
            tmp=0, pos=0;
            for(r=i;r>=0;--r)
            {
                if(pos==l)
                    break;
                if(ss[r][j]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
            tmp=0, pos=0;
            for(r=i, s=j;r>=0 && s<n;--r)
            {
                if(pos==l)
                    break;
                if(ss[r][s]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
                ++s;
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
            tmp=0, pos=0;
            for(r=j;r<n;++r)
            {
                if(pos==l)
                    break;
                if(ss[i][r]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
            tmp=0, pos=0;
            for(r=i, s=j;r<m && s<n;++r)
            {
                if(pos==l)
                    break;
                if(ss[r][s]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
                ++s;
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
            tmp=0, pos=0;
            for(r=i;r<m;++r)
            {
                if(pos==l)
                    break;
                if(ss[r][j]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
            tmp=0, pos=0;
            for(r=i, s=j;r<m && s>=0;++r)
            {
                if(pos==l)
                    break;
                if(ss[r][s]!=p[pos++])
                {
                    tmp=1;
                    break;
                }
                --s;
            }
            if(pos!=l)
                tmp=1;
            if(tmp==0)
                return ii(i, j);
        }
    }
}
int main()
{
    scanf("%d", &t);
    int tt=0;
    while(t--)
    {
        scanf("%d %d", &m, &n);
        for(int i=0;i<m;++i)
        {
            scanf("%s", ss[i]);
            for(int j=0;j<n;++j)
                ss[i][j]=toupper(ss[i][j]);
        }
        scanf("%d", &k);
        if(tt)printf("\n");
        tt=1;
        while(k--)
        {
            scanf("%s", p);
            l=strlen(p); 
            for(int i=0;i<l;++i)
                p[i]=toupper(p[i]);
            ii ans=search();
            printf("%d %d\n", ans.first+1, ans.second+1);
        }
    }
    return 0;
}