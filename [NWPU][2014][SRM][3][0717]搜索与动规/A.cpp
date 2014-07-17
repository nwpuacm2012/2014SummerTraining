/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eqs=1e-8;
int a[20005];
int main()
{
    int n;
    LL ans=0;
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        q.push(a[i]);
    }
    while(q.size()>1)
    {
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        ans+=(x+y);
        q.push(x+y);
    }
    printf("%lld\n",ans);
    return 0;
}