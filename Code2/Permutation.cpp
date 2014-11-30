#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
#include<fstream>
#include<map>
#include<cstring>
using namespace std;
typedef vector<int> vi;
#define ll long long int
#define inf 2147483647
#define pi acos(-1)
int main()
{
    int n;
    char s[25];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", s);
        int l=strlen(s);
        sort(s, s+l);
        printf("%s\n", s);
    }
    return 0;
}
