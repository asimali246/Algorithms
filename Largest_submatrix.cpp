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
using namespace std;
typedef vector<int> vi;
int main()
{
    int t;
    scanf("%d", &t);
    char f;
    scanf("%c", &f);
    scanf("%c", &f);
    bool flag=false;
    while(t--)
    {
        char s[30][30];
        char a[30];
        int pos=0;
        while ( gets (s[pos]) && strlen (s[pos]) ) pos++;
        int sum[pos+1][pos+1];
        int ans=0;
        for(int i=0;i<pos;i++)
        {
            for(int j=0;j<pos;j++)
            {
                sum[i][j]=(int)s[i][j]-48;
                if(i>0)sum[i][j]+=sum[i-1][j];
                if(j>0)sum[i][j]+=sum[i][j-1];
                if(i>0 && j>0)sum[i][j]-=sum[i-1][j-1];
            }
        }
        for(int i=0;i<pos;i++)
        {
            for(int j=0;j<pos;j++)
            {
                for(int k=i;k<pos;k++)
                {
                    for(int l=j;l<pos;l++)
                    {
                        int temp=sum[k][l];
                        if(i>0)temp-=sum[i-1][l];
                        if(j>0)temp-=sum[k][j-1];
                        if(i>0 && j>0)temp+=sum[i-1][j-1];
                        if(temp==((k-i+1)*(l-j+1)))
                        ans=max(ans, temp);
                    }
                }
            }
        }
        if(flag==true)printf("\n");
        flag=true;
        printf("%d\n", ans);
    }
    return 0;
}