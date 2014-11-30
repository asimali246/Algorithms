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
int check(int n)
{
    int sum=0;
    while(n)
    {
        if(n&1)sum++;
        n>>=1;
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p;
        cin>>p;
        int n;
        cin>>n;
        int a[n+1];
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum=0;
            int temp=0;
            int x;
            while(temp++!=p)
            {
                cin>>x;
                sum<<=1;
                sum|=x;
            }
            a[i]=sum;
        }
        int ans=1000;
        int flag[32770];
        for(int i=0;i<(1<<p);i++)
        {
            int num=check(i);
            if(num>=ans)continue;
            memset(flag, 0, sizeof flag);
            int temp=1;
            int t=0;
            while(temp<=n)
            {
                int x=a[temp] & i;
                if(flag[x]){t=1;break;}
                flag[x]=1;
                temp++;
            }
            if(t==1)continue;
            if(num!=0)
            ans=num;
            break;
        }
        cout<<ans<<endl;
    }
    return 0;
}