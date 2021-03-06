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
#define Max 1000010
int n, m;
char T[Max];
int RA[Max], tempRA[Max];
int SA[Max], tempSA[Max];
int c[Max];
char P[Max];
int Phi[Max];
int LCP[Max], PLCP[Max];
void countingSort(int k)
{
    int i, sum, maxi=max(300, n);
    memset(c, 0, sizeof c);
    for(i=0;i<n;++i)
        c[i+k<n?RA[i+k]:0]++;
    for(i=sum=0;i<maxi;++i)
    {
        int t=c[i];
        c[i]=sum;
        sum+=t;
    }
    for(i=0;i<n;++i)
        tempSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
    for(i=0;i<n;++i)
        SA[i]=tempSA[i];
}
void constructSA()
{
    int i, k, r;
    for(i=0;i<n;++i)
        RA[i]=T[i]-'.';
    for(i=0;i<n;++i)
        SA[i]=i;
    for(k=1;k<n;k<<=1)
    {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]]=r=0;
        for(i=1;i<n;++i)
            tempRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
        for(i=0;i<n;++i)
            RA[i]=tempRA[i];
    }
}
ii stringMatching()
{
    int lo=0, hi=n-1, mid=lo;
    while(lo<hi)
    {
        mid=(lo+hi)>>1;
        int res=strncmp(T+SA[mid], P, m);
        if(res>=0)hi=mid;
        else
            lo=mid+1;
    }
    if(strncmp(T+SA[lo], P, m)!=0)
        return ii(-1, -1);
    ii ans;
    ans.first=lo;
    lo=0;
    hi=n-1;
    mid=lo;
    while(lo<hi)
    {
        mid=(lo+hi)>>1;
        int res=strncmp(T+SA[mid], P, m);
        if(res>0)hi=mid;
        else
            lo=mid+1;
    }
    if(strncmp(T+SA[hi], P, m)!=0)hi--;
    ans.second=hi;
    return ans;
}
void computeLCP()
{
    int i, L;
    Phi[SA[0]]=-1;
    for(i=1;i<n;++i)
        Phi[SA[i]]=SA[i-1];
    for(i=L=0;i<n;++i)
    {
        if(Phi[i]==-1)
        {
            PLCP[i]=0;
            continue;
        }
        while(T[i+L]==T[Phi[i]+L])++L;
        PLCP[i]=L;
        L=max(L-1, 0);
    }
    for(i=1;i<n;++i)
        LCP[i]=PLCP[SA[i]];
}
int main()
{
    n=(int)strlen(gets(T));
    constructSA();
    for(int i=0;i<n;++i)
        printf("%2d\t%s\n", SA[i], T+SA[i]);
    while(1)
    {
        gets(P);
        m=strlen(P);
        if(m==0)break;
        ii pos=stringMatching();
        if(pos.first!=-1 && pos.second!=-1)
        {
            printf("%s is found SA [%d..%d] of %s\n", P, pos.first, pos.second, T);
            printf("They are:\n");
            for(int i=pos.first;i<=pos.second;++i)
                printf("  %s\n", T+SA[i]);
        }
        else
            printf("%s is not found in %s\n", P, T);
    }
    computeLCP();
    int mx=0, index=0;
    for(int i=0;i<n;++i)
        if(LCP[i]>mx)
        {
            printf("%d\n", LCP[i]);
            mx=LCP[i];
            index=i;
        }
    printf("The Longest Repeated Substring is:\n");
    for(int i=0;i<mx;++i)
        printf("%c", T[SA[index]+i]);
    printf("\n");
    return 0;
}