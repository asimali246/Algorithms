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
int arr[205][20];
int model[205][25];
int M, C,i, j;
int calc(int money, int c)
{
    if(money<0)return -10000;
    if(c==C)return M-money;
    if(arr[money][c]!=-1)return arr[money][c];
    int maxx=-10000;
    for(int ii=1;ii<=model[c][0];ii++)
    {
        maxx=max(maxx, calc(money-model[c][ii], c+1));
    }
    return arr[money][c]=maxx;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &M, &C);
        for(i=0;i<C;i++)
        {
            scanf("%d", &model[i][0]);
            for(j=1;j<=model[i][0];j++)
                scanf("%d",&model[i][j]);
        }
        memset(arr, -1, sizeof arr);
        int ans=calc(M, 0);
        if(ans<0)printf("no solution\n");
        else printf("%d\n", ans);
    }
    return 0;
}