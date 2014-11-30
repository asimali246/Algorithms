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
int n;
char T[Max];
int RA[Max], tempRA[Max];
int SA[Max], tempSA[Max];
int c[Max];
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
int main()
{
    n=(int)strlen(gets(T));
    constructSA();
    for(int i=0;i<n;++i)
        printf("%2d\t%s\n", SA[i], T+SA[i]);
    return 0;
}