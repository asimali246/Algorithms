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

 using namespace std;

#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9

template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int qnum, pd, k;
priority_queue<ii, vector<ii>, greater<ii> > pq;
char s[155];
ii ans;
map<int, int> mp;

int main()
{
	mp.clear();
	while(true)
	{
		gets(s);
		if(s[0]=='#')
			break;
		sscanf(s, "Register %d %d", &qnum, &pd);
		pq.push(make_pair(pd, qnum));
		mp[qnum]=pd;
	}
	scanf("%d", &k);
	while(k--)
	{
		ans=pq.top();
		printf("%d\n", ans.second);
		pq.pop();
		pq.push(make_pair(ans.first+mp[ans.second], ans.second));
	}
	return 0;
}