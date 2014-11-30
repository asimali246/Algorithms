#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>
#include <ctime>
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int tt, ans, l, i, j, p[6200], c, r, x, m;
char s[6200], t[2*6200];

void preprocess(){
    t[0]='^';
    x=1;
    for(i=0;i<l;++i)
        t[x]='#', t[x+1]=s[i], x+=2;
    t[x]='#', t[++x]='$';
    l=x;
}
int manacher(){
    preprocess();
    c=r=0;
    ans=-INF;
    for(i=1;i<l;++i){
        m=2*c-i;
        p[i]=(r>i)?min(r-i, p[m]):0;
        while(t[i+1+p[i]]==t[i-1-p[i]])
            p[i]++;
        if(i+p[i]>r){
            r=p[i]+i;
            c=i;
        }
        ans=max(ans, p[i]);
    }
    return ans;
}
int main(){
    scanf("%d", &tt);
    while(tt--){
        scanf("%s", s);
        l=(int)strlen(s);
        printf("%d\n", manacher());
    }
    return 0;
}
