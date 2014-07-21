/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eps=1e-8;
const double pi=acos(-1.0);
LL n,m,k;
bool check(LL x)
{
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=min((LL)m,(x-1)/i);
    }
    return sum<k;
}
int main()
{
    cin>>n>>m>>k;
    LL l=1,r=(LL)n*m,ans;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}