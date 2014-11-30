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

int t, total;
bool blank=false;
map<string, int> mp;
char s[33];

int main()
{
	scanf("%d\n\n", &t);
	while(t--)
	{
		mp.clear();
		if(blank)
			putchar('\n');
		blank=true;
		total=0;
		while(gets(s))
		{
			if((int)strlen(s)==0)
				break;
			if(mp.count(s)==0)
				mp[s]=1;
			else
				mp[s]+=1;
			total+=1;
		}
		map<string, int>::iterator it=mp.begin();
		while(it!=mp.end())
		{
			cout<<it->first;
			printf(" %.4lf\n", (double)it->second/(double)total*100.0);
			++it;
		}
	}
	return 0;
}
