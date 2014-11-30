#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        int a[n+1];
        int i,j;
        for(i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1,cmp);
        int sum=0,k;
        int flag=0;
        for(k=1;k<=n;k++)
        {
            sum+=a[k];
            int temp=0;
            for(i=k+1;i<=n;i++)
            {
                temp+=min(a[i],k);
            }
            temp+=(k*(k-1));
            if(sum>temp){flag=1;break;}
        }
        if(sum%2!=0)flag=1;
        if(flag==0)cout<<"Possible"<<endl;
        else cout<<"Not possible"<<endl;
    }
    return 0;
}