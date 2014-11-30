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
#define Max 100010
char T[Max], P[Max];
int n, m;
int b[Max];
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
int kmpSearch()
{
    kmpPreProcess();
    int i=0, j=0;
    while(i<n)
    {
        while(j>=0 && T[i]!=P[j])j=b[j];
        ++i;
        ++j;
    }
    return i-j;
}
int main()
{
    while(gets(T) && strlen(T))
    {
        n=m=strlen(T);
        int p=0;
        for(int i=n-1;i>=0;--i)
            P[p++]=T[i];
        P[p++]='\0';
        int x=kmpSearch();
        printf("%s", T);
        for(int i=x-1;i>=0;--i)
            printf("%c", T[i]);
        printf("\n");
    }
    return 0;
}