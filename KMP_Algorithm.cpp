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

#define Max_N 1001000
char T[Max_N], P[Max_N];
int n, m;
int b[Max_N];
void kmpPreProcess()
{
    int i=0, j=-1;
    b[0]=-1;
    while(i<m)
    {
        while(j>=0 && P[i]!=P[j])j=b[j];
        ++i;
        ++j;
        b[i]=j;
    }
}
void kmpSearch()
{
    kmpPreProcess();
    int i=0, j=0;
    while(i<n)
    {
        while(j>=0 && T[i]!=P[j])j=b[j];
        ++i;
        ++j;
        if(j==m)
        {
            printf("P is found at %d in T\n", i-j);
            j=b[j];
        }
    }
}
int main()
{
    gets(T);
    gets(P);
    n=strlen(T);
    m=strlen(P);
    kmpSearch();
    return 0;
}