#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <bitset>
#include <cstring>
using namespace std;
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
struct point
{
    int x, y;
};
struct line 
{
    double a, b, c;
};
void create(point xx, point yy, line *l)
{
    if(xx.x==yy.x)
    {
        l->a=1;
        l->b=0;
        l->c=-xx.x;
    }
    else
    {
        l->a=-(double)(xx.y-yy.y)/(xx.x-yy.x);
        l->b=1;
        l->c=-(double)(l->a*xx.x)-(l->b * xx.y);
    }
}
int areParallel(line x, line y)
{
    return fabs(x.a-y.a)<EPS && fabs(x.b-y.b)<EPS;
}
int areSame(line x, line y)
{
    return areParallel(x, y) && fabs(x.c-y.c)<EPS;
}
iid intersect(line l1, line l2)
{
    iid ans;
    ans.first=(l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b);
    ans.second=(l1.c*l2.a-l1.a*l2.c)/(l1.a*l2.b-l2.a*l1.b);
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    point x1, x2, x3, x4;
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--)
    {   
        scanf("%d %d %d %d %d %d %d %d", &x1.x, &x1.y, &x2.x, &x2.y, &x3.x, &x3.y, &x4.x, &x4.y);
        line l1, l2;
        create(x1, x2, &l1);
        create(x3, x4, &l2);
        //printf("%.3lf %.3lf %.3lf\n", l1.a, l1.b, l1.c);
        //printf("%.3lf %.3lf %.3lf\n", l2.a, l2.b, l2.c); 
        if(areSame(l1, l2))
        {
            printf("LINE\n");
        }
        else
        if(areParallel(l1, l2))
        {
            printf("NONE\n");
        }
        else
        {
            iid ans=intersect(l1, l2);
            printf("POINT %.2lf %.2lf\n", ans.first, ans.second);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}