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
 
struct state
{
    int len, link;
    map<char, int> next;
};

int flag;
const int MAX=250010;
state st[MAX*2];
int sz, last;

void sa_init()
{
    sz=last=0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}

void sa_extend(char c) 
{
    int cur=sz++;
    st[cur].len=st[last].len+1;
    int p;
    for(p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c]=cur;
    if(p==-1)
        st[cur].link=0;
    else 
    {
        int q=st[p].next[c];
        if(st[p].len+1==st[q].len)
            st[cur].link=q;
        else 
        {
            int clone=sz++;
            st[clone].len=st[p].len+1;
            st[clone].next=st[q].next;
            st[clone].link=st[q].link;
            for(;p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c]=clone;
            st[q].link=st[cur].link=clone;
        }
    }
    last = cur;
}

string lcs(string s, string t) 
{
    sa_init();
    for(int i=0;i<(int)s.length();++i)
        sa_extend(s[i]);
    int v=0, l=0, best=0, bestpos=0;
    for(int i=0;i<(int)t.length();++i) 
    {
        while(v && !st[v].next.count(t[i]))
        {
            v=st[v].link;
            l=st[v].len;
        }
        if(st[v].next.count(t[i]))
        {
            v=st[v].next[t[i]];
            ++l;
        }
        if(l>best)
            best=l, bestpos=i;
    }
    return t.substr(bestpos-best+1, best);
}

string s, t;
int main()
{
    cin>>s;
    cin>>t;
    string ans=lcs(s, t);
    if(ans.length())
    {
        cout<<ans<<endl;
        printf("%d\n", ans.length());
    }
    else
        puts("0");
    return 0;
}