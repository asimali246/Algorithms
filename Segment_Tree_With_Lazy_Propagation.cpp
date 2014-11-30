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
#define inf 2147483647
#define pi acos(-1)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
#define Max 1100000
int arr[Max];
int lazy[5*Max+10];
int cnt[5*Max+10];
void build(int id, int l, int r)
{
    if(l==r)
    {
        cnt[id]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    cnt[id]=cnt[id*2]+cnt[id*2+1];
}
void insert(int, int, int , int , int, int);
void update(int id, int l, int r)
{
    if(lazy[id]==-1)
        return;
    int mid=(l+r)/2;
    insert(id*2, l, mid, l, mid, lazy[id]);
    insert(id*2+1, mid+1, r, mid+1, r, lazy[id]);
}
void insert(int id, int l, int r, int a, int b, int op)
{
    if(lazy[id]!=-1)
    {
        if(lazy[id]==op && (op==1||op==2))
            return;
    }
    int mid=(l+r)/2;
    if(l==a && r==b)
    {
        if(op==1 || op==2)
        {
            cnt[id]=(b-a+1)*(2-op);
            lazy[id]=op;
        }
        else
        {
            cnt[id]=(b-a+1)-cnt[id];
            if(lazy[id]==0)lazy[id]=-1;
            else
            if(lazy[id]==1)lazy[id]=2;
            else
            if(lazy[id]==2)lazy[id]=1;
            else lazy[id]=0;
        }
        return;
    }
    update(id, l, r);
    lazy[id]=-1;
    if(mid<a)
    {
        insert(id*2+1, mid+1, r, a, b, op);
    }
    else
    if(b<=mid)
    {
        insert(id*2, l, mid, a, b, op);
    }
    else
    {
    insert(id*2, l, mid, a, mid, op);
    insert(id*2+1, mid+1, r, mid+1, b, op);
    }
    cnt[id]=cnt[id*2]+cnt[id*2+1];
}
int query(int id, int l, int r, int a, int b)
{
    if(l==a && r==b)
        return cnt[id];
    int ans=0;
    if(cnt[id]==0)
        return 0;
    if((r-l+1)==cnt[id])
        return (b-a+1);
    if(lazy[id]!=-1)
    {
        update(id, l, r);
        lazy[id]=-1;
    }
    int mid=(l+r)/2;
    if(mid<a)
    {
        ans=query(id*2+1, mid+1, r, a, b);
    }
    else
    if(b<=mid)
    {
        ans=query(id*2, l, mid, a, b);
    }
    else
    {
        ans+=query(id*2+1, mid+1, r, mid+1, b);
        ans+=query(id*2, l, mid, a, mid);
    }
    return ans;
}
int main()
{
    int t;
    int cs=1, no=1;
    scanf("%d", &t);
    char str[60];
    while(t--)
    {
        int m;
        scanf("%d", &m);
        int n=1;
        memset(lazy, -1, sizeof(lazy));
        while(m--)
        {
            int tt;
            scanf("%d", &tt);
            scanf("%s", str);
            int l=strlen(str);
            for(int i=0;i<tt;++i)
            {
                for(int j=0;j<l;++j)
                    arr[n++]=str[j]-'0';
            }
        }
        n-=1;
        build(1, 1, n);
        int q;
        scanf("%d", &q);
        getchar();
        char ch;
        int a, b;
        printf("Case %d:\n", cs++);
        no=1;
        while(q--)
        {  
            scanf("%c %d %d",&ch, &a, &b);
            getchar();
            ++a;
            ++b;
            if(ch=='F')
            {
                insert(1, 1, n, a, b, 1);
            }
            else
            if(ch=='E')
            {
                insert(1, 1, n, a, b, 2);
            }
            else
            if(ch=='I')
            {
                insert(1, 1, n, a, b, 0);
            }
            else
            {
                int ans=query(1, 1, n, a, b);
                printf("Q%d: %d\n", no++, ans);
            }
        }
    }
    return 0;
}