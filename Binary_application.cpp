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
double p,q,r,s,t,u;
double rounding(double ans)
{
    ans*=10000000.0;
    ans+=.5;
    int x=floor(ans);
    return (double)x/10000000.0;
}
int check(double val)
{
    double ans=0.0;
    ans=p*exp(-val)+(q*sin(val))+(r*cos(val))+(s*tan(val))+(t*val*val)+u;
    ans=rounding(ans);
    if(ans==0)return 0;
    if(ans<0)
        return -1;
    if(ans>0)return 1;
}
int main()
{
    int flag=0;
    while(scanf("%lf %lf %lf %lf %lf %lf",&p ,&q, &r, &s, &t, &u)!=EOF)
    {
        double x=0.0,y=1.0;
        flag=0;
        int ll=0;
        double mid=0.0;
        if(check(1.0)==0){flag=1;mid=1.0;}
        if(check(0.0)==0){flag=1;mid=0.0;}
        if(flag!=1){
        for(int i=1;i<=35;i++)//log base 2 (1-0)/10**-9;
        {
            mid=(x+y)/2.0;
            int l=check(mid);
            if(l>0)
                {ll=1;x=mid;}
            if(l<0)
                {y=mid;ll=-1;}
            if(l==0)
                {flag=1;break;}
        }}
        if(flag==1)printf("%.4lf\n", mid);
        else printf("No solution\n");
    }
    return 0;
}