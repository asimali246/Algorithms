#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
 
const int MOD=1000000007;
 
const int maxn=1<<20;
 
int n;
int w[maxn];
int a[maxn];
char s[maxn];
int cnt[maxn<<4];
int sum[maxn<<4][2];
int num[maxn<<4][2];
int lastbit;
 
inline int ADD(int a,int b)
{
	int c=a+b;
	if (c>=MOD) c-=MOD;
	return c;
}
void ck(int id)
{
	int c=cnt[id];
	sum[id][0]=ADD(sum[id*2+1][c],sum[id*2+2][c]);
	sum[id][1]=ADD(sum[id*2+1][c^1],sum[id*2+2][c^1]);
	num[id][0]=ADD(num[id*2+1][c],num[id*2+2][c]);
	num[id][1]=ADD(num[id*2+1][c^1],num[id*2+2][c^1]);
}
void pat(int id,int key)
{
	int c=a[key]^cnt[id];
	sum[id][0]=(w[key]*c)%MOD; num[id][0]=c;
	sum[id][1]=(w[key]*(1-c))%MOD; num[id][1]=1-c;
}
void init(int id,int s,int t)
{
	if (s==t) { pat(id,s); return; }
	int m=(s+t)/2;
	init(id*2+1,s,m);
	init(id*2+2,m+1,t);
	ck(id);
}
void update(int id,int s,int t,int head,int tail)
{
	if (s==t) { cnt[id]^=1; pat(id,s); return; }
	if (s>=head && t<=tail) { cnt[id]^=1; ck(id); return; }
	int m=(s+t)/2;
	if (m>=head) update(id*2+1,s,m,head,tail);
	if (m<tail) update(id*2+2,m+1,t,head,tail);
	ck(id);
}
int solve()
{
	int ret=sum[0][0];
	if (lastbit==1 || num[0][0]%2==0) ret=ADD(ret,1);
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++) a[i]=(s[i]-'0');
	lastbit=a[n-1];
	w[n-1]=0;
	for (int i=n-2;i>=0;i--) w[i]=((i==n-2)?1:((w[i+1]*2)%MOD));
	memset(cnt,0,sizeof(cnt));
	init(0,0,n-1);
	printf("%d\n",solve());
	int m;
	for (scanf("%d",&m);m>0;m--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		update(0,0,n-1,s-1,t-1);
		if (t==n) lastbit^=1;
		printf("%d\n",solve());
	}
	return 0;
}