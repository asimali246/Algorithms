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
char s[1010];
int dp[1024][1024];
int longest(int l, int r)
{
    if(l>r)return dp[l][r]=0;
    if(l==r)return dp[l][r]=1;
    if(dp[l][r]!=-1)return dp[l][r];
    if(s[l]==s[r])
        return dp[l][r]=2+longest(l+1, r-1);
    else
        return dp[l][r]=max(longest(l+1, r), longest(l, r-1));
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        gets(s);
        int l=strlen(s);
        for(int i=0;i<l;++i)
            for(int j=0;j<l;++j)
                dp[i][j]=-1;
        printf("%d\n", longest(0, l-1));
    }
    return 0;
}