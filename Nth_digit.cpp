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
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        int x=1, y=9, sum=0;
        while(n>(x*y))
        {
            n-=(x*y);
            sum+=y;
            y*=10;
            ++x;
        }
        //cout<<sum<<endl;
        int p=n%x;
        int q=n/x;
        sum+=q;
        if(p==0)printf("%d\n", sum%10);
        else
        {
            int count=x-1;
            sum+=1;
            sum/=10;
            int a[15];
            while(true)
            {
                int r=sum%10;
                a[count]=r;
                sum/=10;
                --count;
                if(!count)break;
            }
            printf("%d\n", a[p]);
        }
    }
    return 0;
}