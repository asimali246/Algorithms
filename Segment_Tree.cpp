#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
typedef vector<int> vi;
void Segment_tree_build(vi &t, const vi &v, int vertex, int L, int R)
{
    if(L==R)
    {
        t[vertex]=L;
    }
    else
    {
        int nL=2*vertex;
        int nR=2*vertex+1;
        Segment_tree_build(t, v, nL, L, (L+R)/2);
        Segment_tree_build(t, v, nR, (L+R)/2+1, R);
        int lContent=t[nL], rContent=t[nR];
        int lValue=v[lContent], rValue=v[rContent];
        t[vertex]=(lValue<=rValue)?lContent:rContent;
    }
}
void create(vi &t, const vi &v)
{
    int len = (int)(2 * pow(2.0, floor((log((double)v.size()) / log(2.0)) + 1)));
    t.assign(len,0);
    Segment_tree_build(t,v,1,0,(int)v.size()-1);
}
int rmq(vi &t, const vi &v, int vertex, int L, int R, int i, int j)
{
    if(i>R||j<L)return -1;
    if (L >= i && R <= j) return t[vertex];
    int p1 = rmq(t, v, 2 * vertex, L, (L + R) / 2, i, j);
    int p2 = rmq(t, v, 2 * vertex + 1, (L + R) / 2 + 1, R, i, j);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(v[p1]<=v[p2])return p1;
    else return p2;
}
int rmq(vi &t, const vi& v, int i, int j) { 
return rmq(t, v, 1, 0, (int)v.size() - 1, i, j); }
int main()
{
    int a[9]={1,1,0,0,1,1,0,0,1,1,1};
    vi v(a,a+11);
    vi st;
    create(st,v);
    cout<<rmq(st,v, 0, 6)<<endl;
    cout<<rmq(st,v, 5, 7)<<endl;
    return 0;
}