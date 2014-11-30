#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
#include<fstream>
using namespace std;
typedef vector<int> vi;
int arr[50010][110];
int values[110];
int i,j,n;
int calc(int w, int nn)
{
    if(nn<0)return 0;
    if(arr[w][nn]!=-1)return arr[w][nn];
    if(values[nn]>w)
        return arr[w][nn]=calc(w, nn-1);
    else
        return arr[w][nn]=max(calc(w, nn-1), values[nn]+calc(w-values[nn],nn-1));
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int sum=0;
        for(i=0;i<n;i++){scanf("%d", &values[i]);sum+=values[i];}
        memset(arr, -1, sizeof arr);
        int ans=calc(sum/2, n-1);
        ans*=2;
        printf("%d\n", sum-ans);
    }
    return 0;
}