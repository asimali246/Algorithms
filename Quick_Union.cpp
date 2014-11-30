#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
using namespace std;
#define N 1000000
int id[N];
int find(int p)
{
    if(id[p]==p) return p;
    return id[p]=find(id[p]);
}
int main ()
{
    int t;
    cin>>t;
    int x=0;
    while(t--){
        for(int i=0;i<N;i++)id[i]=i;
        int n;
        cin>>n;
        getchar();
        char c;
        int p,q;
        int ans1=0,ans2=0;
        while ((c=getchar())&&isalpha(c)){
            cin>>p>>q;
            getchar();
            int pp=find(p);
            int qq=find(q);
            if (c=='c'){
                id[pp]=qq;
            } else {
                if(pp==qq)ans1++;
                else ans2++;
            }
        }
        if (x==1)cout<<endl;
        x=1;
        cout<<ans1<<","<<ans2<<endl;
    }
    return 0;
}