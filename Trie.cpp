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
#include <cassert>
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }
 
typedef vector<int> vi;
typedef pair<int, int> ii;


struct Trie {
	Trie *Next[2] ;
} ;

Trie *root, *trav ;
int l, r, ans, i, j, v ;

Trie* New() {
	Trie *temp ;
	temp = new Trie ;
	temp -> Next[0] = temp -> Next[1] = NULL ;
	return temp ;
}

void Insert(int n) {
	trav = root ;
	j = 31 ;
	while( true ) {
		if( n & ( 1 << j ) ) 
			v = 1 ;
		else
			v = 0 ;
		if( !trav -> Next[v] ) {
			trav -> Next[v] = New() ;
		} 
		--j ;
		trav = trav -> Next[v] ;
		if( j < 0 )
			break ; 
	}
}

int getMax(int n) {
	int ans = 0 ;
	j = 31 ;
	trav = root ;
	while( true ) {
		if( n & ( 1 << j ) ) 
			v = 1 ;
		else
			v = 0 ;
		if( v == 0 && trav -> Next[1] ) {
			trav = trav -> Next[1] ;
			ans |= ( 1 << j ) ;
		}
		else
		if( v == 1 && trav -> Next[0] ) {
			trav = trav -> Next[0] ;
			ans |= ( 1 << j ) ;
		}
		else
		if( v == 0 ) 
			trav = trav -> Next[0] ;
		else
			trav = trav -> Next[1] ;
		--j ;
		if( j < 0 )
			break ;
	}
	return ans ;
}

int main() {
	root = New() ;
	scanf("%d %d", &l, &r) ;
	for( i = l; i <= r; ++i ) {
		Insert( i ) ;
		ans = max( ans, getMax(i) ) ;
	}
	printf("%d\n", ans);
	return 0 ;
} 