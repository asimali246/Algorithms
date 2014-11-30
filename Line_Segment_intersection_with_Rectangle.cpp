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
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> iid;
double DEG_to_RAD(double d)
{
    return d*PI/180.0;
}
double RAD_to_DEG(double r)
{
    return r*180.0/PI;
}
struct point_i
{
    int x, y;
    point_i(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
};
struct point
{
    double x, y;
    point(double _x, double _y){x=_x;y=_y;}
    bool operator < (point other) const
    {
        if(fabs(x-other.x)>EPS)
            return x<other.x;
        return y<other.y;
    }
};
bool areSame(point_i p1, point_i p2)
{
    return p1.x==p2.x && p1.y==p2.y;
}
bool areSame(point p1, point p2)
{
    return fabs(p1.x-p2.x)<EPS && fabs(p1.y-p2.y)<EPS;
}
double dist(point p1, point p2)
{
    return hypot(p1.x-p2.x, p1.y-p2.y);
}
point rotate(point p, double theta)
{
    double rad=DEG_to_RAD(theta);
    return point(p.x*cos(rad)-p.y*sin(rad),
            p.x*sin(rad)+p.y*cos(rad));
}
struct line
{
    double a, b, c;
};
void pointsToLine(point p1, point p2, line *l)
{
    if(p1.x==p2.x)
    {
        l->a=1.0;
        l->b=0.0;
        l->c=-p1.x;
    }
    else
    {
        l->a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
        l->b=1.0;
        l->c=-(double)(l->a*p1.x)-(l->b*p1.y);
    }
}
bool areParallel(line l1, line l2)
{
    return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);
}
bool areSame(line l1, line l2)
{
    return areParallel(l1, l2) && fabs(l1.c-l2.c)<EPS;
}
bool areIntersect(line l1, line l2, point *p)
{
    if(areSame(l1, l2))return false;
    if(areParallel(l1, l2))return false;
    p->x=(double)(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
    p->y=(double)(l1.c*l2.a-l1.a*l2.c)/(l1.a*l2.b-l2.a*l1.b);
    return true;
}
struct vec
{
    double x, y;
    vec(double _x, double _y)
    {
        x=_x;
        y=_y;
    }
};
vec toVector(point p1, point p2)
{
    return vec(p2.x-p1.x, p2.y-p1.y);
}
vec scaleVector(vec v, double s)
{
    return vec(v.x*s, v.y*s);
}
point translate(point p, vec v)
{
    return point(p.x+v.x, p.y+v.y);
}
void pointSlopeToLine(point p, double m, line *l)
{
    l->a=-m;
    l->b=1;
    l->c=-((l->a*p.x)+(l->b*p.y));
}
void closestPoint(line l, point p, point *ans)
{
    line perp;
    if(fabs(l.b)<EPS)
    {
        ans->x=-(l.c);
        ans->y=p.y;
        return;
    }
    if(fabs(l.a)<EPS)
    {
        ans->x=p.x;
        ans->y=-(l.c);
        return;
    }
    pointSlopeToLine(p, 1/l.a, &perp);
    areIntersect(l, perp, ans);
}
double distToLine(point p, point A, point B, point *c)
{
    double scale=(double)
    ((p.x-A.x)*(B.x-A.x)+(p.y-A.y)*(B.y-A.y))/
    ((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
    c->x=A.x+scale*(B.x-A.x);
    c->y=A.y+scale*(B.y-A.y);
    return dist(p, *c);
}
double distToLineSegment(point p, point A, point B, point *c)
{
    if((B.x-A.x)*(p.x-A.x)+(B.y-A.y)*(p.y-A.y)<EPS)
    {
        c->x=A.x;
        c->y=A.y;
        return dist(p, A);
    }
    if((A.x-B.x)*(p.x-B.x)+(A.y-B.y)*(p.y-B.y)<EPS)
    {
        c->x=B.x;
        c->y=B.y;
        return dist(p, B);
    }
    return distToLine(p, A, B, c);
}
double cross(point p, point q, point r)
{
    return (r.x-q.x)*(p.y-q.y)-(r.y-q.y)*(p.x-q.x);
}
bool ccw(point p, point q, point r)
{
    return cross(p, q, r)>0;
}
bool collinear(point p, point q, point r)
{
    return fabs(cross(p, q, r))<EPS;
}
bool onSegment(point p, point q, point r)
{
    if(q.x<=max(p.x, r.x) && q.x>=min(p.x, r.x) && q.y<=max(p.y, r.y) && q.y>=min(p.y, r.y))
        return true;
    return false;
}
int main()
{   
    int n;
    scanf("%d", &n);
    while(n--)
    {
        point p(0.0, 0.0), q(0.0, 0.0), lt(0.0, 0.0), rb(0.0, 0.0), aa(0.0, 0.0), bb(0.0, 0.0), cc(0.0, 0.0), dd(0.0, 0.0);
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p.x, &p.y, &q.x, &q.y, &lt.x, &lt.y, &rb.x, &rb.y);
        aa.x=lt.x, aa.y=lt.y;
        bb.x=rb.x, bb.y=lt.y;
        cc.x=rb.x, cc.y=rb.y;
        dd.x=lt.x, dd.y=rb.y;
        if((ccw(p, q, aa)!=ccw(p, q, bb)) && (ccw(aa, bb, p)!=ccw(aa, bb, q)))
        {
            printf("T\n");
            continue;
        }
        if((ccw(p, q, bb)!=ccw(p, q, cc)) && (ccw(bb, cc, p)!=ccw(bb, cc, q)))
        {
            printf("T\n");
            continue;
        }
        if((ccw(p, q, cc)!=ccw(p, q, dd)) && (ccw(cc, dd, p)!=ccw(cc, dd, q)))
        {
            printf("T\n");
            continue;
        }
        if((ccw(p, q, dd)!=ccw(p, q, aa)) && (ccw(dd, aa, p)!=ccw(dd, aa, q)))
        {
            printf("T\n");
            continue;
        }
        if((collinear(p, q, aa) && onSegment(p, aa, q)) || (collinear(p, q, bb) && onSegment(p, bb, q)) || (collinear(aa, bb, p) && onSegment(aa, p, bb)) || (collinear(aa, bb, q) && onSegment(aa, q, bb)))
        {
            printf("T\n");
            continue;
        }
        if((collinear(p, q, bb) && onSegment(p, bb, q)) || (collinear(p, q, cc) && onSegment(p, cc, q)) || (collinear(bb, cc, p) && onSegment(bb, p, cc)) || (collinear(bb, cc, q) && onSegment(bb, q, cc)))
        {
            printf("T\n");
            continue;
        }
        if((collinear(p, q, cc) && onSegment(p, cc, q)) || (collinear(p, q, dd) && onSegment(p, dd, q)) || (collinear(cc, dd, p) && onSegment(cc, p, dd)) || (collinear(cc, dd, q) && onSegment(cc, q, dd)))
        {
            printf("T\n");
            continue;
        }
        if((collinear(p, q, dd) && onSegment(p, dd, q)) || (collinear(p, q, aa) && onSegment(p, aa, q)) || (collinear(dd, aa, p) && onSegment(dd, p, aa)) || (collinear(dd, aa, q) && onSegment(dd, q, aa)))
        {
            printf("T\n");
            continue;
        }
        if((p.x<max(cc.x, dd.x) && p.x>min(cc.x, dd.x)) && (p.y<max(bb.y, cc.y) && p.y>min(bb.y, cc.y)) && (q.x<max(cc.x, dd.x) && q.x>min(cc.x, dd.x)) && (q.y<max(bb.y, cc.y) && q.y>min(bb.y, cc.y)))
        {
            printf("T\n");
            continue;
        }
        printf("F\n");
    }
    return 0;
}