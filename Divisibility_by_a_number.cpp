#include <iostream>
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
typedef vector<int> vi;
#define ll long long int 
#define inf 2147483647
#define pi acos(-1)
int main(){
    int f,i,a[15],j,t,s,n,rem,l;
    char aa[1005];

    scanf("%d\n",&t);
    while(t--){
        scanf("%s",aa);
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        l = strlen(aa);
        f = 0;
        if(l==1 && aa[0]=='0'){
            printf("%s - Wonderful.\n",aa);
            continue;
        }
        for(i=0;i<n;i++){
            rem = 0;
            for(j=0;j<l;j++){
                s = rem*10 + (aa[j]-'0');
                rem = s%a[i];
            }
            if(rem){
                f = 1;
                break;
            }
        }
        if(f)printf("%s - Simple.\n",aa);
        else printf("%s - Wonderful.\n",aa);
    }
    return 0;
}