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
    /*bool operator == (point other) const
    {
        if(fabs(x-other.x)<EPS && fabs(y-other.y)<EPS)
            return true;
        return false;
    }*/
};
bool cmp(point a, point b)
{
    if(fabs(a.y-b.y)>EPS)
        return a.y>b.y;
    return true;
}
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
int inCircle(point p, point c, double r)
{
    double d=hypot(p.x-c.x, p.y-c.y);
    return d<r?0:fabs(d-r)<EPS?1:2;
}
double rounding(double val)
{
    val*=10000000.0;
    val+=0.5;
    val=floor(val);
    return val/10000000.0;
}
bool circle2PtsRad(point p1, point p2, double r, point *c1, point *c2)
{
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  det=rounding(det);
  if (det < 0.0) return false;
  double h = sqrt(det);
  c1->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c1->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  c2->x = (p2.x+p1.x)*0.5 + (p2.y-p1.y)*h;
  c2->y=(p2.y+p1.y)*0.5 + (p1.x-p2.x)*h;
  return true;
}
double areaTriangle(double a, double b, double c)
{
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}