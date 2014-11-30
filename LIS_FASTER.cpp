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
vi v, indexes, rev;
int binary_search_find(int a[], int end, int x)
{
    int low=0, high=end, mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
            return mid;
        else
        if(a[mid]>x)
            high=mid-1;
        else
            low=mid+1;
    }
    if(x<=a[mid])
        return mid;
    else return mid+1;
}
int main()
{
    int n;
    int ans=1, count=1, pos=1, ind=1;
    while(scanf("%d", &n)!=EOF)
    {
        v.push_back(n);
        indexes.push_back(1);
        ++count;
    }
    int seq[count];
    seq[1]=v[0];
    for(int i=1;i<v.size();++i)
    {
        if(v[i]<seq[1])
        {
            seq[1]=v[i];
            indexes[i]=1;
        }
        else
        if(v[i]>seq[pos])
        {
            seq[++pos]=v[i];
            indexes[i]=pos;
        }
        else
        {
            int place=binary_search_find(seq, pos, v[i]);
            seq[place]=v[i];
            indexes[i]=place;
        }
        if(indexes[i]>=ans)
        {
            ans=indexes[i];
            ind=i;
        }
        
    }
    int p=ans;
    for(int i=ind;i>=0 && p>0;i--)
    {
        if(indexes[i]==p)
        {
            rev.push_back(v[i]);
            --p;
        }
    }
    printf("%d\n-\n", ans);
    for(int i=rev.size()-1;i>=0;i--)
    {
        printf("%d\n", rev[i]);
    }
    return 0;
}